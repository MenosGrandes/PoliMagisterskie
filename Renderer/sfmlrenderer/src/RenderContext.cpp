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
    int yStart=(int)std::ceil(min.position.y);
    int yEnd=(int)std::ceil(max.position.y);
    int xStart=(int)std::ceil(min.position.x);
    int xEnd=(int)std::ceil(max.position.x);

        float yDist = max.position.y - min.position.y;
		float xDist = max.position.x - min.position.x;
    if(yDist <= 0 )
    {
        return;
    }
    float xStep=(float)xDist/(float)yDist;
    float yPrestep=yStart - min.position.y;

    float curX=min.position.y+yPrestep* xStep;
    for(int i=yStart; i<yEnd; i++)
    {
        m_scanBuffer[i*2+whichSide]= (int)std::ceil(curX);
        curX+=xStep;
    }
}
void RenderContext::scanConvertTriangle(Vertex2 min, Vertex2 mid, Vertex2 max, d_type::Bint whichSide)
{
    scanConvertLine(min,max,0+whichSide);
    scanConvertLine(min,mid,1-whichSide);
    scanConvertLine(mid,max,1-whichSide);

}
void RenderContext::fillTriangle(Vertex2 _v1, Vertex2 _v2, Vertex2 _v3)
{
Matrix4f screenSpaceTransform= Matrix4f();
screenSpaceTransform.InitScreenSpaceTransform(m_width/2,m_height/2);
 Vertex2 v1=_v1.transform(screenSpaceTransform).perspectiveDivide();
 Vertex2 v2=_v2.transform(screenSpaceTransform).perspectiveDivide();
 Vertex2 v3=_v3.transform(screenSpaceTransform).perspectiveDivide();

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
    fillShape((d_type::Bint)std::ceil(v1.position.y),(d_type::Bint)std::ceil(v3.position.y));
}
