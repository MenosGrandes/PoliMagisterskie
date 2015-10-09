#ifndef DRAWABLE_H
#define DRAWABLE_H
class RenderTarget;
class Drawable
{
    public:
        virtual ~Drawable() {}
    protected:
    virtual void draw(RenderTarget & target) =0;
    private:
};

#endif // DRAWABLE_H
