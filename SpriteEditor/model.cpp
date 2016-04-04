#include "model.h"

Model::Model(QGraphicsScene* scene,int screenheight,int screenwidth,int unitsize)
{
    this->unitsize = unitsize;
    this->scene = scene;
    this->color = Vector4(0,0,0,255);
    DrawGrid(screenheight,screenwidth,unitsize);
}

// private methods

void Model::Save()
{
 QString fileName = QFileDialog::getSaveFileName();

 QString toSave = "";

 QFile file(fileName);

 QTextStream stream( &file );

 // Loop through each image in sprite
 for(size_t i = 0; i < this->selectedSprite->images.size(); i++)
 {
     Image current = this->selectedSprite->images.at(i);

     // loop through each layer in current image
     for(size_t i = 0; i < current.layers.size(); i++)
     {
         // Get current layer and add it to string
         Layer temp = current.layers.at(i);
         Vector4* RGB = temp.pixels;

         if ( file.open(QIODevice::ReadWrite) )
         {
             QString sep = ",";
             toSave = QString::number(RGB->r) + sep + QString::number(RGB->g) + sep + QString::number(RGB->b) + sep + QString::number(RGB->a);
             stream << toSave << "\n";
         }
         //toSave += RGB->r + "," + RGB->g + "," + RGB->b + "," + RGB->a + "\n";
     }
 }


}

void Model::Load(QString fileName)
{
    QFile file(fileName);
    QTextStream in(&file);

    // Ensure file is open
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "Error", file.errorString());
    }
    while(!in.atEnd())
    {
        QString line = in.readLine();
    }
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

void Model::AddImage(){;}

void Model::Draw(int x, int y, Vector4 color)
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

}

void Model::DeleteRect(int x, int y)
{
    stringstream posstring;
    posstring << x << y;
    if(pixelmap[posstring.str()] != NULL)
        pixelmap[posstring.str()]->setBrush(* new QBrush(QColor(0, 0, 0, 0)));
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
    this->Draw(cellloc.x(),cellloc.y(),this->color);
    qDebug() << this->color.r;
    qDebug() << this->color.g;
    qDebug() << this->color.b;
    qDebug() << this->color.a;
}

void Model::MouseMove(QPointF point)
{
   // qDebug() << "Mouse Move X= " << point.x() << " Y= " << point.y();
}

void Model::MouseReleased(QPointF point)
{

}


