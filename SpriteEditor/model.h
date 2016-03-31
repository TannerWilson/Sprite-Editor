#ifndef MODEL_H
#define MODEL_H

#include "sprite.h"
#include "image.h"
#include "layer.h"
#include "tool.h"
#include "vector.h"
#include <QGraphicsScene>
#include <QtGui>
#include <qobject.h>
#include <string>
#include <sstream>
using namespace std;

class Model :public QObject
{
    Q_OBJECT
private:
    // private data members
    Sprite *selectedSprite;
    Image *selectedImage;
    Layer *selectedLayer;
    Tool *currentTool;

    QGraphicsScene* scene;

    // private methods
    void Save(Sprite);
    void Export(Sprite);
    void UpdateGUI();

    void DrawGrid(int height, int width, int unitsize);

    QMap<string,QGraphicsRectItem*> pixelmap;

public:
    Model(QGraphicsScene* scene, int screenheight, int screenwidth, int unitsize);
    Model();
    void Draw(int x, int y, Vector4 color);
    void DeleteRect(int x, int y);
    void AddLayer();
    void AddImage();
    QPoint GetCellLocation(QPointF point);
    int unitsize;

public slots:
    void MouseClicked(QPointF point);
    void MouseMove(QPointF point);
    void MouseReleased(QPointF point);

};

#endif // MODEL_H
