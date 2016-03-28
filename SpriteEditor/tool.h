#ifndef TOOL_H
#define TOOL_H

// An abstract class representing tools for modifying pixels
class Tool
{
public:
    virtual void OnClick(int,int) = 0;
    virtual void OnRelease(int,int) = 0;
    virtual void OnHover(int,int) = 0;
    virtual void OnDrag(int,int) = 0;
};

#endif // TOOL_H
