#include "model.h"

Model::Model(QGraphicsScene* scene)
{
    this->scene = scene;
    DrawGrid(3000,3000,50);
}

// private methods

void Model::Save(Sprite sprite){;}
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
        QGraphicsRectItem* rect = scene->addRect((x-1)*50, (y-1)*50, 50, 50, outlinePen, brush);
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

    if(mousex < 50 && mousex > 0)
        returnpoint.setX(1);
    else
    {
        int countx = 0;
        while(mousex >= 50)
        {

            mousex -= 50;
            countx++;
        }

        if(mousex > 0)
            countx++;

        returnpoint.setX(countx);
    }

    if(mousey < 50 && mousey > 0)
        returnpoint.setY(1);
    else
    {
        int county = 0;
        while(mousey >= 50)
        {
            mousey -= 50;
            county++;
        }

        if(mousey > 0)
            county++;

        returnpoint.setY(county);
    }
    return returnpoint;

}

void Model::MouseClicked(QPointF point)
{
    QPoint cellloc = GetCellLocation(point);
    this->Draw(cellloc.x(),cellloc.y(),Vector4(255,0,0,255));
}

void Model::MouseMove(QPointF point)
{
   // qDebug() << "Mouse Move X= " << point.x() << " Y= " << point.y();
}

void Model::MouseReleased(QPointF point)
{
   // qDebug() << "Mouse Released X= " << point.x() << " Y= " << point.y();

}


