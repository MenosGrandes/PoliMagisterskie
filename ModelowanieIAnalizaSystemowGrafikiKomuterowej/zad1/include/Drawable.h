#ifndef DRAWABLE_H
#define DRAWABLE_H
class RenderTarget;
class Drawable
{

    public:
        virtual ~Drawable() {}
    protected:
    friend class RenderTarget;
    virtual void draw(RenderTarget & target) const = 0;

};

#endif // DRAWABLE_H
