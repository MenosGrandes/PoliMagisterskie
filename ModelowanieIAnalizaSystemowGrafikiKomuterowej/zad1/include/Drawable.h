#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "RenderTarget.h"
class RenderTarget;
class Drawable
{

public:
    virtual ~Drawable() {}
    friend class RenderTarget;
    virtual void draw(RenderTarget & target) const = 0;


};

#endif // DRAWABLE_H
