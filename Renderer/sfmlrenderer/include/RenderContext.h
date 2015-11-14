#ifndef RENDERCONTEXT_H
#define RENDERCONTEXT_H
#include "Bitmap.h"
#include "Vertex2.h"
class RenderContext : public Bitmap
{
    public:
        RenderContext(d_type::Bint width,d_type::Bint height);
        virtual ~RenderContext();
        void drawScanBuffer(d_type::Bint y,d_type::Bint minXA,d_type::Bint maxX);
        void fillShape(d_type::Bint minY,d_type::Bint maxY);
        void scanConvertLine(Vertex2 min,Vertex2 max,d_type::Bint whichSide);
void scanConvertTriangle(Vertex2 min, Vertex2 mid, Vertex2 max, d_type::Bint whichSide);
void fillTriangle(Vertex2 f, Vertex2 s, Vertex2 t);
    protected:
    private:
        d_type::Bint *m_scanBuffer;
};

#endif // RENDERCONTEXT_H
