#ifndef SPRITE_H
#define SPRITE_H

#include <vector>
#include "image.h"
using namespace std;
class Sprite
{
public:
    Sprite();
    vector<Image*> images;
    Image* AddImage();
    void DeleteImage(int index);
    Image* GetImage(int index);
};

#endif // SPRITE_H
