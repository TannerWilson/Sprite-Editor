#include "model.h"

Model::Model(QGraphicsScene* scene,int screenheight,int screenwidth,int unitsize)
{
    this->unitSize = unitsize;
    this->scene = scene;
    this->color = Vector4(0,0,0,255);
    drawGrid(screenheight,screenwidth,unitsize);
    this->selectedSprite = new Sprite();
    this->currentTool = "Pen";
    this->screenHeight = screenheight;
    this->screenWidth = screenwidth;
    this->mouseIsPressed = false;
}

// private methods

void Model::save()
{
    int cellCount = (screenHeight/unitSize) * (screenWidth/unitSize);

    QString fileName = QFileDialog::getSaveFileName();
    QString colorDelim = " ";
    QFile file(fileName);
    int rowIndicator = screenWidth / unitSize;

    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );

        stream << screenWidth << " " << screenHeight << "\n";
        stream << selectedSprite->images.size() << "\n";
        stream << unitSize << "\n";

        for (size_t i = 0; i < selectedSprite->images.size(); i++){
            Image* currentImage = selectedSprite->getImage(i);

            for (int k = 0; k < cellCount; k ++){
                QColor currentColor = currentImage->getPixelColorIndex(k);
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

void Model::open()
{
    int frameCount = 0;

    QString filename = QFileDialog::getOpenFileName();

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QString content = file.readAll();
    QTextStream stream(&content);

    this->selectedSprite->images.clear();

    stream >> screenHeight >> screenWidth >> frameCount >> unitSize;

    int cellCount = (screenHeight/unitSize) * (screenWidth/unitSize);

    for(int i = 0; i < frameCount; i++){
        selectedSprite->addImage();
        qDebug() << "Added Image";
    }

    while(!stream.atEnd()){
        for (int i = 0; i < frameCount; i++){
            this->selectedImage = selectedSprite->getImage(i);
            this->selectedImage->setSize(screenWidth,screenHeight, unitSize);
            qDebug() << "Selected Image at index " <<i;
            for (int k = 0; k < cellCount; k++){
                int red;
                int green;
                int blue;
                int alpha;
                stream >> red >> green >> blue >> alpha;
                qDebug() << red << green << blue << alpha;
                QPoint point = selectedImage->indexToPoint(k);
                if((red+blue+green+alpha) !=0){
                    penDraw(point.x(),point.y(),Vector4(red, green, blue, alpha));
                }
            }
        }
    }
    file.close();
}

void Model::exportSprite(Sprite sprite){;}
void Model::updateGUI(){;}

void Model::drawGrid(int imageHeight, int imageWidth, int unitSize)
{
    int numberofVerticalLines = imageWidth/unitSize;
    int numberofHorizontalLines = imageHeight/unitSize;

    QPen outlinePen(Qt::black);
    outlinePen.setWidth(1);
    QPen rectPen(QColor(150,150,150,150));
    QBrush greyBrush(QColor(150, 150, 150, 150));

    // Draw grid and checkered background
    for(int i = 0; i <= numberofVerticalLines; i++)
    {
        for(int j = 0; j <= numberofHorizontalLines; j++)
        {
            if(i%2 == 0)
            {
                if(j%2 == 0)
                {
                    scene->addRect(i*unitSize, j*unitSize, unitSize, unitSize, rectPen, greyBrush);
                }
            }
            else
            {
                if(j%2 == 1)
                {
                    scene->addRect(i*unitSize, j*unitSize, unitSize, unitSize, rectPen, greyBrush);
                }
            }
        }
    }
}

// public methods

void Model::addLayer(){;}

void Model::addImage()
{
    selectedSprite->addImage();
}

void Model::removeImageAt(int index)
{
    selectedSprite->deleteImage(index);
}

/*
 * Returns the index of the Sprite's image that's currently being modified
 */
int Model::getCurrentImageIndex()
{
    return selectedSprite->getCurrentImageIndex();
}

/*
 * Updates the index of the Sprite image currently being modified,
 * and sets the model's Image pointer to that image
 */
void Model::setCurrentImageIndex(int index)
{
    selectedImage = selectedSprite->setCurrentImageIndex(index);
    selectedImage->setSize(screenWidth,screenHeight, unitSize);
    redrawImage(index);
}



void Model::penDraw(int x, int y, Vector4 color)
{

    // Outline
    QPen outlinePen(QColor(150,150,150,150));
    outlinePen.setWidth(1);

    // BrushColor
    QBrush brush(QColor(color.r, color.g, color.b, color.a));

    /*
     * if someone can think of a better idea to change the map from a string,QGraphicsRectItem do it.
     */

    stringstream posstring;
    posstring << x << " " << y;

    // Is the pixel already there?
    if(pixelMap[posstring.str()] == NULL)
    {
        // If so draw it and add it to the map.
        QGraphicsRectItem* rect = scene->addRect(x*unitSize, y*unitSize, unitSize, unitSize, outlinePen, brush);
        pixelMap[posstring.str()] = rect;
    }
    else // Or just update the old pixel.
        pixelMap[posstring.str()]->setBrush(brush);

    this->selectedImage->addPixel(QPoint(x,y),QColor(color.r, color.g, color.b, color.a));
    this->selectedImage->addPixelIndex(QPoint(x,y),QColor(color.r, color.g, color.b, color.a));

}

void Model::fill(int x, int y, Vector4 color)
{
    if (x > 0 && y > 0)
    {
        stringstream ss;
        ss << x << y;
        QColor originalColor = this->selectedImage->getPixels()[ss.str()];
        QColor newColor(color.r, color.g, color.b, color.a);
        recursiveFill(x, y, originalColor, newColor);
    }
}

void Model::recursiveFill(int x, int y, QColor originalColor, QColor newColor)
{
    stringstream ss;
    ss << x << y;
    QColor currentColor = this->selectedImage->getPixels()[ss.str()];

    if (newColor != currentColor && originalColor == currentColor)
    {
        penDraw(x, y, Vector4(newColor.red(), newColor.green(), newColor.blue(), newColor.alpha()));
        recursiveFill(x, y, originalColor, newColor);
        recursiveFill(x-1, y, originalColor, newColor);
        recursiveFill(x+1, y, originalColor, newColor);
        recursiveFill(x, y-1, originalColor, newColor);
        recursiveFill(x, y+1, originalColor, newColor);
    }
}

void Model::erase(int x, int y)
{
    this->deleteRect(x, y);
}

void Model::deleteRect(int x, int y)
{
    stringstream posstring;
    posstring << x << " " << y;
    if(pixelMap[posstring.str()] != NULL)
        pixelMap[posstring.str()]->setBrush(* new QBrush(QColor(0, 0, 0, 0)));

    this->selectedImage->clearPixel(QPoint(x,y));
}

QPoint Model::getCellLocation(QPointF point)
{
    QPoint returnpoint;

    float mousex = point.x();
    float mousey = point.y();

    if(mousex < unitSize && mousex > 0)
        returnpoint.setX(0);
    else
    {
        int countx = 0;
        while(mousex >= unitSize)
        {

            mousex -= unitSize;
            countx++;
        }

        if(mousex > 0)
            countx++;

        returnpoint.setX(countx-1);
    }

    if(mousey < unitSize && mousey > 0)
        returnpoint.setY(0);
    else
    {
        int county = 0;
        while(mousey >= unitSize)
        {
            mousey -= unitSize;
            county++;
        }

        if(mousey > 0)
            county++;

        returnpoint.setY(county-1);
    }
    return returnpoint;

}

void Model::mousePressed(QPointF point)
{
    if(point.x() < 0 || point.x() > screenWidth || point.y() < 0 || point.y() > screenHeight)
        return;

    QPoint cellloc = getCellLocation(point);
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
void Model::mouseMove(QPointF point)
{
    if(mouseIsPressed)
        this->mousePressed(point);
}

/*
 * Stop drag painting/erasing once user releases mouse
 */
void Model::mouseReleased(QPointF point)
{
    this->mouseIsPressed = false;
}


void Model::redrawImage(int index)
{

    qDeleteAll( pixelMap );
    pixelMap.clear();
    scene->clear();


    selectedImage = this->selectedSprite->getImage(index);
    drawGrid(this->screenHeight,this->screenWidth,this->unitSize);

    for(int x = 0; x < screenHeight/unitSize; x++)
    {
        for(int y = 0; y < screenWidth/unitSize; y++)
        {
            QColor newcolor = selectedImage->getPixelColor(QPoint(x,y));
            if(newcolor != QColor(0,0,0,0))
                penDraw(x,y,Vector4(newcolor.red(),newcolor.green(),newcolor.blue(),newcolor.alpha()));
        }
    }

}

void Model::preview()
{

    if(currentPreviewFrame < selectedSprite->images.size())
    {
        redrawImage(currentPreviewFrame);
        currentPreviewFrame++;
    }
    else
        currentPreviewFrame = 0;

}

void Model::startPreview()
{
    qDebug() << selectedSprite->images.size();
    currentPreviewFrame = 0;
    previewTimer = new QTimer;
    connect(previewTimer, SIGNAL(timeout()), this, SLOT(preview()));
    previewTimer->start(1000);
}

void Model::stopPreview()
{
    previewTimer->stop();
    currentPreviewFrame = 0;
    redrawImage(0);

}
