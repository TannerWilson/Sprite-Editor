#ifndef MODEL_H
#define MODEL_H

#include "sprite.h"
#include "image.h"
#include "layer.h"
#include "tool.h"
#include "vector.h"

class Model
{

private:
    // private data members
    Sprite *selectedSprite;
    Image *selectedImage;
    Layer *selectedLayer;
    Tool *currentTool;

    // private methods
    void Save(Sprite);
    void Export(Sprite);
    void UpdateGUI();

public:
    Model();
    void Draw(int, int, Vector);
    void MouseClicked(int, int);
    void MouseReleased(int, int);
    void AddLayer();
    void AddImage();

};

#endif // MODEL_H
