#ifndef RENDERCONTEXT_H
#define RENDERCONTEXT_H
#include "Bitmap.h"

class RenderContext : public Bitmap
{
    public:
        RenderContext(d_type::Bint width,d_type::Bint height);
        virtual ~RenderContext();
        void drawScanBuffer(d_type::Bint y,d_type::Bint minXA,d_type::Bint maxX);
        void fillShape(d_type::Bint minY,d_type::Bint maxY);
    protected:
    private:
        d_type::Bint *m_scanBuffer;
};

#endif // RENDERCONTEXT_H
