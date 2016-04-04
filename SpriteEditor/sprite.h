#ifndef SPRITE_H
#define SPRITE_H

#include <vector>
#include "image.h"
using namespace std;
class Sprite
{
    // the image currently being modified
    int currentImageIndex; // starts from 0
public:
    Sprite();
    vector<Image*> images; // 0-indexed
    Image* AddImage();
    void DeleteImage(int index);
    Image* GetImage(int index);
    int GetCurrentImageIndex();
};

#endif // SPRITE_H
