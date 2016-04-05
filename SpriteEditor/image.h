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

public:
    Image();
    QColor GetPixelColor(QPoint point);
    void AddPixel(QPoint point, QColor color);
    void ClearPixel(QPoint point);

};
#endif // IMAGE_H
