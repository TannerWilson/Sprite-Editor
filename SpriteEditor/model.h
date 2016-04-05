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
    int screenwidth;
    int screenheight;

    int currentpreviewframe;
    QTimer *previewtimer;

    QMap<string,QGraphicsRectItem*> pixelmap;

    bool mouseIsPressed;

    // private methods

    void Export(Sprite);
    void UpdateGUI();
    void DrawGrid(int height, int width, int unitsize);




public:
    Model(QGraphicsScene* scene, int screenheight, int screenwidth, int unitsize);
    Model();
    void penDraw(int x, int y, Vector4 color);
    void erase(int x, int y);
    void fill(int x, int y, Vector4 color);

    void RedrawImage(int index);
    void DeleteRect(int x, int y);
    void AddLayer();
    void AddImage();
    void RemoveImageAt(int index);
    int GetCurrentImageIndex();
    void SetCurrentImageIndex(int index);
    QPoint GetCellLocation(QPointF point);
    int unitsize;
    Vector4 color;
    Vector4 secondaryColor;
    QString currentTool;

public slots:
    void MousePressed(QPointF point);
    void MouseMove(QPointF point);
    void MouseReleased(QPointF point);
    void Save();
    void Open();
    void StartPreview();
    void StopPreview();
    void Preview();

};

#endif // MODEL_H
