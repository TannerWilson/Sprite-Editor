#ifndef IMAGE_H
#define IMAGE_H


#include <vector>
#include "layer.h"
#include <qmap.h>
#include <string>
#include <qpoint.h>
#include <QColor>
#include <sstream>
using namespace std;

class Image
{
private:
    QMap<string,QColor> pixels;
    QMap<int,QColor> pixelsIndex;
    int ScreenHeight;
    int ScreenWidth;
    int UnitSize;

public:
    Image();
    QColor GetPixelColor(QPoint point);
    void AddPixel(QPoint point, QColor color);
    void ClearPixel(QPoint point);
    QMap<string,QColor> getPixels() { return pixels; }

    QColor GetPixelColorIndex(int k);
    void AddPixelIndex(QPoint point, QColor color);
    void ClearPixelIndex(QPoint point);
    void SetSize(int x, int y, int unit);
    int PointToIndex(QPoint point);
    QPoint IndexToPoint(int index);

};
#endif // IMAGE_H
