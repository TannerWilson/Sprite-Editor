#include "layer.h"

Layer::Layer(int width,int height)
{
    this->pixels = new Vector4[width*height];
}

Layer::~Layer()
{
    delete [] pixels;
}
