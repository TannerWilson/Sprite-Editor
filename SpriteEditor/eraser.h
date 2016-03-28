#ifndef ERASER_H
#define ERASER_H
#include "tool.h"

// Represents a tool for erasing pixels. Inherits from the abstract class Tool
class Eraser : public Tool
{
public:
    Eraser();
    void OnClick(int,int);
    void OnRelease(int,int);
    void OnHover(int,int);
    void OnDrag(int,int);
};

#endif // ERASER_H
