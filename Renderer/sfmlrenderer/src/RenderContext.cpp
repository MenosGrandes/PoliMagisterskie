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

    for(d_type::Bint j=minY; j<maxY; j++)
    {
        d_type::Bint xMin= m_scanBuffer[j*2];
        d_type::Bint xMax= m_scanBuffer[j*2+1];
        for(d_type::Bint i=xMin; i<xMax; i++)
        {
            drawPixel(i,j,255,255,255,255);
        }
    }
}
void RenderContext::scanConvertLine(Vertex2 min, Vertex2 max, d_type::Bint whichSide)
{
    int yStart=(int)min.position.y;
    int yEnd=(int)max.position.y;
    int xStart=(int)min.position.x;
    int xEnd=(int)max.position.x;

    int yDist=yEnd - yStart;
    int xDist=xEnd -xStart;
    if(yDist <= 0 )
    {
        return;
    }
    float xStep=(float)xDist/(float)yDist;
    float curX=(float) xStart;
    for(int i=yStart; i<yEnd; i++)
    {
        m_scanBuffer[i*2+whichSide]= (int)curX;
        curX+=xStep;
    }
}
void RenderContext::scanConvertTriangle(Vertex2 min, Vertex2 mid, Vertex2 max, d_type::Bint whichSide)
{
    scanConvertLine(min,max,0+whichSide);
    scanConvertLine(min,mid,1-whichSide);
    scanConvertLine(mid,max,1-whichSide);

}
void RenderContext::fillTriangle(Vertex2 v1, Vertex2 v2, Vertex2 v3)
{
Matrix4f screenSpaceTransform= Matrix4f();
screenSpaceTransform.InitScreenSpaceTransform(m_width/2,m_height/2);
 v1=v1.transform(screenSpaceTransform).perspectiveDivide();
 v2=v2.transform(screenSpaceTransform).perspectiveDivide();
 v3=v3.transform(screenSpaceTransform).perspectiveDivide();

    if(v3.position.y<v2.position.y)
    {
        Vertex2 tmp = v3;
        v3=v2;
        v2=tmp;
    }
//////////////////////////////////
    if(v2.position.y<v1.position.y)
    {
        Vertex2 tmp = v2;
        v2=v1;
        v1=tmp;
    }
/////////////////////////////////
    if(v3.position.y<v2.position.y)
    {
        Vertex2 tmp = v3;
        v3=v2;
        v2=tmp;
    }
    d_type::Bfloat area = v1.triangleArea(v3,v2);
    d_type::Bint handedness= area >=0 ? 1 : 0;
    scanConvertTriangle(v1,v2,v3,handedness);
    fillShape((d_type::Bint)v1.position.y,(d_type::Bint)v3.position.y);
}
