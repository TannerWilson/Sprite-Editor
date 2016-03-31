#ifndef LAYER_H
#define LAYER_H


#include "vector.h"
class Layer
{
public:
    Layer(int width, int height);
    ~Layer();
    Vector4* pixels;
};


#endif // LAYER_H
