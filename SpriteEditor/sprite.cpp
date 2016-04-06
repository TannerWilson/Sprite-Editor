#include "sprite.h"

Sprite::Sprite()
{
    currentImageIndex = 0;
}

Image* Sprite::addImage()
{
    Image* newimage = new Image();
    images.push_back(newimage);
    return newimage;
}

void Sprite::deleteImage(int index)
{
    images.erase(images.begin() + index);
    if(currentImageIndex > 0)
    {
        currentImageIndex--;
    }
}

Image* Sprite::getImage(int index)
{
    return images.at(index);
}

int Sprite::getCurrentImageIndex()
{
    return currentImageIndex;
}

Image* Sprite::setCurrentImageIndex(int index)
{
    currentImageIndex = index;
    return images[index];
}
