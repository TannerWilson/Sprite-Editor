#include "image.h"

Image::Image()
{

}

QColor Image::GetPixelColor(QPoint point)
{
    stringstream key;
    key << point.x() << " " << point.y();
    if(pixels.contains(key.str()))
        return pixels[key.str()];
    else
        return QColor(0,0,0,0);
}

void Image::AddPixel(QPoint point, QColor color)
{
    stringstream key;
    key << point.x() << " " << point.y();
    pixels[key.str()] = color;
}

void Image::ClearPixel(QPoint point)
{
    stringstream key;
    key << point.x() << " " << point.y();
    pixels[key.str()] = QColor(0,0,0,0);
}
