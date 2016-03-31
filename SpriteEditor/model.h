#ifndef MODEL_H
#define MODEL_H

#include "sprite.h"
#include "image.h"
#include "layer.h"
#include "tool.h"
#include "vector.h"
#include <QGraphicsScene>

class Model
{

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
    void DrawRectToScreen(float x, float y, float height, float width, Vector4 color);

public:
    Model(QGraphicsScene* scene);
    Model();
    void Draw(int, int, Vector4);
    void MouseClicked(int, int);
    void MouseReleased(int, int);
    void AddLayer();
    void AddImage();

};

#endif // MODEL_H
