#ifndef IMAGE_H
#define IMAGE_H


#include <vector>
#include "layer.h"
using namespace std;

class Image
{
public:
    Image();
    vector<Layer> layers;
};
#endif // IMAGE_H
