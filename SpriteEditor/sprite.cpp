#include "sprite.h"

Sprite::Sprite()
{
    images.push_back(new Image());
}

Image* Sprite::AddImage()
{
    Image* newimage = new Image();
    images.push_back(newimage);
    return newimage;
}

void Sprite::DeleteImage(int index)
{
    images.erase(images.begin() + index);
}

Image* Sprite::GetImage(int index)
{
    return images.at(index);
}
