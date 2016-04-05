#include "model.h"

Model::Model(QGraphicsScene* scene,int screenheight,int screenwidth,int unitsize)
{
    this->unitsize = unitsize;
    this->scene = scene;
    this->color = Vector4(0,0,0,255);
    DrawGrid(screenheight,screenwidth,unitsize);
    this->selectedSprite = new Sprite();
    this->currentTool = "Pen";
    this->screenheight = screenheight;
    this->screenwidth = screenwidth;
    this->mouseIsPressed = false;
}

// private methods

void Model::Save()
{
    int cellCount = (screenheight/unitsize) * (screenwidth/unitsize);

    QString fileName = QFileDialog::getSaveFileName();
    QString colorDelim = " ";
    QFile file(fileName);
    int rowIndicator = screenwidth / unitsize;

    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );

        stream << screenwidth << " " << screenheight << "\n";
        stream << selectedSprite->images.size() << "\n";
        stream << unitsize << "\n";

        for (size_t i = 0; i < selectedSprite->images.size(); i++){
            Image* currentImage = selectedSprite->GetImage(i);

            for (int k = 0; k < cellCount; k ++){
                QColor currentColor = currentImage->GetPixelColorIndex(k);
                stream <<  currentColor.red() << colorDelim;
                stream <<  currentColor.green() << colorDelim;
                stream <<  currentColor.blue() << colorDelim;
                stream <<  currentColor.alpha();
                if ((k+1) % rowIndicator == 0 && k !=0){
                    stream << "\n";
                }
                else {
                    stream << " ";
                }
            }

        }
    }
    file.close();
}

void Model::Open()
{
    int frameCount = 0;

    QString filename = QFileDialog::getOpenFileName();

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QString content = file.readAll();
    QTextStream stream(&content);

    this->selectedSprite->images.clear();

    stream >> screenheight >> screenwidth >> frameCount >> unitsize;

    int cellCount = (screenheight/unitsize) * (screenwidth/unitsize);

    for(int i = 0; i < frameCount; i++){
        selectedSprite->AddImage();
        qDebug() << "Added Image";
    }

    while(!stream.atEnd()){
        for (int i = 0; i < frameCount; i++){
            this->selectedImage = selectedSprite->GetImage(i);
            this->selectedImage->SetSize(screenwidth,screenheight, unitsize);
            qDebug() << "Selected Image at index " <<i;
            for (int k = 0; k < cellCount; k++){
                int red;
                int green;
                int blue;
                int alpha;
                stream >> red >> green >> blue >> alpha;
                qDebug() << red << green << blue << alpha;
                QPoint point = selectedImage->IndexToPoint(k);
                if((red+blue+green+alpha) !=0){
                    penDraw(point.x(),point.y(),Vector4(red, green, blue, alpha));
                }
            }
        }
    }
    file.close();
}

void Model::Export(Sprite sprite){;}
void Model::UpdateGUI(){;}

void Model::DrawGrid(int imageheight, int imagewidth, int unitsize)
{
    int numberofverticallines = imagewidth/unitsize;
    int numberofhorizontallines = imageheight/unitsize;

    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);

    for(int i = 0; i <= numberofverticallines; i++)
        scene->addLine((i*unitsize),0,(i*unitsize),imageheight,outlinePen);

    for(int j = 0; j <= numberofhorizontallines; j++)
        scene->addLine(0,(j*unitsize),imagewidth,(j*unitsize),outlinePen);
}

// public methods

void Model::AddLayer(){;}

void Model::AddImage()
{
    selectedSprite->AddImage();
}

void Model::RemoveImageAt(int index)
{
    selectedSprite->DeleteImage(index);
}

/*
 * Returns the index of the Sprite's image that's currently being modified
 */
int Model::GetCurrentImageIndex()
{
    return selectedSprite->GetCurrentImageIndex();
}

/*
 * Updates the index of the Sprite image currently being modified,
 * and sets the model's Image pointer to that image
 */
void Model::SetCurrentImageIndex(int index)
{
    selectedImage = selectedSprite->SetCurrentImageIndex(index);
    RedrawImage(index);
}



void Model::penDraw(int x, int y, Vector4 color)
{

    // Outline
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);

    // BrushColor
    QBrush brush(QColor(color.r, color.g, color.b, color.a));

    /*
     * if someone can think of a better idea to change the map from a string,QGraphicsRectItem do it.
     */

    stringstream posstring;
    posstring << x << " " << y;

    // Is the pixel already there?
    if(pixelmap[posstring.str()] == NULL)
    {
        // If so draw it and add it to the map.
        QGraphicsRectItem* rect = scene->addRect(x*unitsize, y*unitsize, unitsize, unitsize, outlinePen, brush);
        pixelmap[posstring.str()] = rect;
    }
    else // Or just update the old pixel.
        pixelmap[posstring.str()]->setBrush(brush);

    this->selectedImage->AddPixel(QPoint(x,y),QColor(color.r, color.g, color.b, color.a));
    this->selectedImage->AddPixelIndex(QPoint(x,y),QColor(color.r, color.g, color.b, color.a));

}

void Model::erase(int x, int y)
{
    this->DeleteRect(x, y);
}

void Model::fill(int x, int y, Vector4 color)
{

}

void Model::DeleteRect(int x, int y)
{
    stringstream posstring;
    posstring << x << " " << y;
    if(pixelmap[posstring.str()] != NULL)
        pixelmap[posstring.str()]->setBrush(* new QBrush(QColor(0, 0, 0, 0)));

    this->selectedImage->ClearPixel(QPoint(x,y));
}

QPoint Model::GetCellLocation(QPointF point)
{
    QPoint returnpoint;

    float mousex = point.x();
    float mousey = point.y();

    if(mousex < unitsize && mousex > 0)
        returnpoint.setX(0);
    else
    {
        int countx = 0;
        while(mousex >= unitsize)
        {

            mousex -= unitsize;
            countx++;
        }

        if(mousex > 0)
            countx++;

        returnpoint.setX(countx-1);
    }

    if(mousey < unitsize && mousey > 0)
        returnpoint.setY(0);
    else
    {
        int county = 0;
        while(mousey >= unitsize)
        {
            mousey -= unitsize;
            county++;
        }

        if(mousey > 0)
            county++;

        returnpoint.setY(county-1);
    }
    return returnpoint;

}

void Model::MousePressed(QPointF point)
{
    if(point.x() < 0 || point.x() > screenwidth || point.y() < 0 || point.y() > screenheight)
        return;

    QPoint cellloc = GetCellLocation(point);
    this->mouseIsPressed = true;

    if (this->currentTool == "Pen")
    {
        this->penDraw(cellloc.x(),cellloc.y(),this->color);
    }
    else if (this->currentTool == "Eraser")
    {
        this->erase(cellloc.x(), cellloc.y());
    }
    else if (this->currentTool == "Bucket")
    {
        this->fill(cellloc.x(), cellloc.y(), this->color);
    }
}

/*
 * Allows drag painting/erasing
 */
void Model::MouseMove(QPointF point)
{
   if(mouseIsPressed)
       this->MousePressed(point);
}

/*
 * Stop drag painting/erasing once user releases mouse
 */
void Model::MouseReleased(QPointF point)
{
    this->mouseIsPressed = false;
}


void Model::RedrawImage(int index)
{

    qDeleteAll( pixelmap );
    pixelmap.clear();
    scene->clear();


    selectedImage = this->selectedSprite->GetImage(index);
    DrawGrid(this->screenheight,this->screenwidth,this->unitsize);

    for(int x = 0; x < screenheight/unitsize; x++)
    {
        for(int y = 0; y < screenwidth/unitsize; y++)
        {
            QColor newcolor = selectedImage->GetPixelColor(QPoint(x,y));
            if(newcolor != QColor(0,0,0,0))
                penDraw(x,y,Vector4(newcolor.red(),newcolor.green(),newcolor.blue(),newcolor.alpha()));
        }
    }

}

void Model::Preview()
{

    if(currentpreviewframe < selectedSprite->images.size())
    {
        RedrawImage(currentpreviewframe);
        currentpreviewframe++;
    }
    else
        currentpreviewframe = 0;

}

void Model::StartPreview()
{
    qDebug() << selectedSprite->images.size();
    currentpreviewframe = 0;
    previewtimer = new QTimer;
    connect(previewtimer, SIGNAL(timeout()), this, SLOT(Preview()));
    previewtimer->start(1000);
}

void Model::StopPreview()
{
    previewtimer->stop();
    currentpreviewframe = 0;
    RedrawImage(0);

}
