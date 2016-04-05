#include "model.h"

Model::Model(QGraphicsScene* scene,int screenheight,int screenwidth,int unitsize)
{
    this->unitsize = unitsize;
    this->scene = scene;
    this->color = Vector4(0,0,0,255);
    DrawGrid(screenheight,screenwidth,unitsize);
    this->selectedSprite = new Sprite();
    this->selectedImage = selectedSprite->GetImage(0);
    this->currentTool = "Pen";
    this->screenheight = screenheight;
    this->screenwidth = screenwidth;
}

// private methods

void Model::Save()
{
    QString fileName = QFileDialog::getSaveFileName();

    QString toSave = "";

    QFile file(fileName);

    QTextStream stream( &file );



//    Image current = this->selectedSprite->images.at(i);


    // Get current layer and add it to string
//    Layer temp = current.layers.at(i);
//    Vector4* RGB = temp.pixels;

    for (size_t i = 0; i < this->pixelmap.size(); i++)
    {

    }

    if ( file.open(QIODevice::ReadWrite) )
    {
//        QString sep = ",";
//        toSave = QString::number(RGB->r) + sep + QString::number(RGB->g) + sep + QString::number(RGB->b) + sep + QString::number(RGB->a);
//        stream << toSave << "\n";
    }





}

void Model::Open()
{
      qDebug() << "open" << endl;
//    QString fileName = QFileDialog::getSaveFileName();

//    QFile file(fileName);
//    QTextStream in(&file);

//    // Ensure file is open
//    if (!file.open(QIODevice::ReadOnly))
//    {
//        QMessageBox::information(0, "Error", file.errorString());
//    }
//    while(!in.atEnd())
//    {
//        QString line = in.readLine();
//    }
}

void Model::Export(Sprite sprite){;}
void Model::UpdateGUI(){;}

void Model::DrawGrid(int imageheight, int imagewidth, int unitsize)
{
    int numberofverticallines = imageheight/unitsize;
    int numberofhorizontallines = imagewidth/unitsize;

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
    posstring << x << y;

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
    posstring << x << y;
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

void Model::MouseClicked(QPointF point)
{
    QPoint cellloc = GetCellLocation(point);

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

void Model::MouseMove(QPointF point)
{
   // qDebug() << "Mouse Move X= " << point.x() << " Y= " << point.y();
}

void Model::MouseReleased(QPointF point)
{

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


