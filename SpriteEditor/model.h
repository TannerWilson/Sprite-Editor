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
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QGraphicsRectItem>

using namespace std;

class Model :public QObject
{
    Q_OBJECT
private:
    // private data members
    Sprite *selectedSprite;
    Image *selectedImage;
    Layer *selectedLayer;

    QGraphicsScene* scene;

    // private methods
    void recursiveFill(int x, int y, QColor currentColor, QColor newColor);
    bool colorEquals(Vector4 vectorColor, QColor color);
    void Export(Sprite);
    void UpdateGUI();
    void DrawGrid(int height, int width, int unitsize);
    QMap<string,QGraphicsRectItem*> pixelmap;

public:
    Model(QGraphicsScene* scene, int screenheight, int screenwidth, int unitsize);
    Model();
    void penDraw(int x, int y, Vector4 color);
    void erase(int x, int y);
    void fill(int x, int y, Vector4 color);

    void DeleteRect(int x, int y);
    void AddLayer();
    void AddImage();
    void RemoveImageAt(int index);
    int GetCurrentImageIndex();
    QPoint GetCellLocation(QPointF point);
    int unitsize;
    Vector4 color;
    Vector4 secondaryColor;
    QString currentTool;

public slots:
    void MouseClicked(QPointF point);
    void MouseMove(QPointF point);
    void MouseReleased(QPointF point);
    void Save();
    void Open();

};

#endif // MODEL_H
