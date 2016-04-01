#ifndef GIFEXPORT_H
#define GIFEXPORT_H
#include <string>
#include "sprite.h"


class GIFExport
{
public:
    GIFExport();
    void save(string fileName, Sprite* sprite);

};

#endif // GIFEXPORT_H
