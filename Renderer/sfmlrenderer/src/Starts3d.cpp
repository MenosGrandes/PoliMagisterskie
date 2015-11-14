#include "Starts3d.h"


Starts3d::~Starts3d()
{
    //dtor
}
Starts3d::Starts3d(d_type::Buint numbers, d_type::Bfloat spread, d_type::Bfloat speed):m_spread(spread),m_speed(speed)
{
    m_starX=new d_type::Bfloat[numbers];
    m_starY=new d_type::Bfloat[numbers];
    m_starZ=new d_type::Bfloat[numbers];
    for(d_type::Bint i=0; i<numbers; i++)
    {
        initStar(i);
    }
}


void Starts3d::UpdateAndRender(Bitmap* bmp, d_type::Bfloat delta)
{
    bmp->clear(0x00);
//    d_type::Bfloat halfsizeW=bmp->getWidth()/2.0f;
//        d_type::Bfloat halfsizeH=bmp->getHeight()/2.0f;
//
//    for(d_type::Bint i=0; i<4096; i++)
//    {
//        m_starZ[i]-=delta*m_speed;
//        if(m_starZ[i]<=0)
//        {
//            initStar(i);
//        }
//        d_type::Bint x=(int)((m_starX[i]/m_starZ[i])*halfsizeW+halfsizeW);
//        d_type::Bint y=(int)((m_starY[i]/m_starZ[i])*halfsizeH+halfsizeH);
//        if(x< 0 || x>=bmp->getWidth() ||(y<0 || y>=bmp->getHeight()))
//        {
//            initStar(i);
//        }
//        else
//        {
//            bmp->drawPixel(x,y,255,255,255,255);
//        }
//    }
}
void Starts3d::initStar(d_type::Bint index)
{
    srand(time(0));
    float r = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX) -0.5f)*m_spread;
    float r2 = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX) -0.5f)*m_spread;

    float r3 = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX) +0.00001)*m_spread;
    std::cout<<r<<"\n";
    m_starX[index]=2*r;
    m_starY[index]=2*r2;
    m_starZ[index]=r3;
}
