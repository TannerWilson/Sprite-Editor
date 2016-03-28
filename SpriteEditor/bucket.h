#ifndef BUCKET_H
#define BUCKET_H
#include "tool.h"

// Represents a tool for painting adjacent, identically-colored pixels a new color.
// Inherits from the abstract class Tool
class Bucket : public Tool
{
public:
    Bucket();
    void OnClick(int,int);
    void OnRelease(int,int);
    void OnHover(int,int);
    void OnDrag(int,int);
};
#endif // BUCKET_H
