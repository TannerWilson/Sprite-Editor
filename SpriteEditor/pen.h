#ifndef PEN_H
#define PEN_H
#include "tool.h"

// Represents a tool for painting pixels to an image. Inherits from the abstract class Tool
class Pen : public Tool
{
public:
    Pen();
    void OnClick(int,int);
    void OnRelease(int,int);
    void OnHover(int,int);
    void OnDrag(int,int);
};

#endif // PEN_H
