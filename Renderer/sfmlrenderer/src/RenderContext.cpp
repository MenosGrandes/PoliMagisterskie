#include "RenderContext.h"

RenderContext::RenderContext(d_type::Bint width,d_type::Bint height):Bitmap(width,height)
{
   m_scanBuffer=new d_type::Bint[height*2];
}

RenderContext::~RenderContext()
{
    //dtor
}
void RenderContext::drawScanBuffer(d_type::Bint y, d_type::Bint minX, d_type::Bint maxX)
{
    m_scanBuffer[y*2]=minX;
    m_scanBuffer[y*2+1]=maxX;
}

void RenderContext::fillShape( d_type::Bint minY, d_type::Bint maxY)
{

for(d_type::Bint j=minY;j<maxY;j++)
{
    d_type::Bint xMin= m_scanBuffer[j*2];
    d_type::Bint xMax= m_scanBuffer[j*2+1];
    for(d_type::Bint i=xMin;i<xMax;i++)
    {
        drawPixel(i,j,255,255,255,255);
    }
}
}
