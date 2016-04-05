#include "sprite.h"

Sprite::Sprite()
{
    currentImageIndex = 0;
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
    if(currentImageIndex > 0)
    {
        currentImageIndex--;
    }
}

Image* Sprite::GetImage(int index)
{
    return images.at(index);
}

int Sprite::GetCurrentImageIndex()
{
    return currentImageIndex;
}

Image* Sprite::SetCurrentImageIndex(int index)
{
    currentImageIndex = index;
    return images[index];
}
