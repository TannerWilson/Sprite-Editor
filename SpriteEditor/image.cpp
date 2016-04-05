#include "image.h"

Image::Image()
{

}

QColor Image::GetPixelColor(QPoint point)
{
    stringstream key;
    key << point.x() << point.y();
    if(pixels.contains(key.str()))
        return pixels[key.str()];
    else
        return QColor(0,0,0,0);
}

void Image::AddPixel(QPoint point, QColor color)
{
    stringstream key;
    key << point.x() << point.y();
    pixels[key.str()] = color;
}

void Image::ClearPixel(QPoint point)
{
    stringstream key;
    key << point.x() << point.y();
    pixels[key.str()] = QColor(0,0,0,0);
}

QColor Image::GetPixelColorIndex(int index)
{
    if(pixelsIndex.contains(index))
        return pixelsIndex[index];
    else
        return QColor(0,0,0,0);
}

void Image::AddPixelIndex(QPoint point, QColor color)
{
    pixelsIndex[PointToIndex(point)] = color;
}

void Image::ClearPixelIndex(QPoint point)
{
    pixelsIndex[PointToIndex(point)] = QColor(0,0,0,0);
}

void Image::SetSize(int x, int y, int unit){
    ScreenWidth = x;
    ScreenHeight = x;
    UnitSize = unit;
}

int Image::PointToIndex(QPoint point){
    int xindex = point.x();
    int yindex = point.y();
    int finalindex = xindex + yindex * (ScreenWidth/UnitSize);
    return finalindex;
}

QPoint Image::IndexToPoint(int index){
    int xindex = index % (ScreenWidth/UnitSize);
    int yindex = (index - xindex) / (ScreenWidth/UnitSize);
    QPoint point(xindex, yindex);
    return point;
}
