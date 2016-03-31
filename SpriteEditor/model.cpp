#include "model.h"

Model::Model(QGraphicsScene* scene)
{
    this->scene = scene;
    DrawGrid(1000,1000,50);
    Draw(0,0,Vector4(0,0,255,255));
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

    for(int i = 0; i < numberofverticallines; i++)
        scene->addLine((i*unitsize),0,(i*unitsize),imageheight,outlinePen);

    for(int j = 0; j < numberofhorizontallines; j++)
        scene->addLine(0,(j*unitsize),imagewidth,(j*unitsize),outlinePen);
}

// public methods

void Model::AddLayer(){;}

void Model::AddImage(){;}

void Model::Draw(int x, int y, Vector4 color)
{
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);

    QBrush brush(QColor(color.r, color.g, color.b, color.a));

    scene->addRect(x, y, 50, 50, outlinePen, brush);
}
void Model::MouseClicked(int x, int y){;}

void Model::MouseReleased(int x, int y){;}


