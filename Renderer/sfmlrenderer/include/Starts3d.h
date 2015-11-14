#ifndef STARTS3D_H
#define STARTS3D_H
#include <random>
#include "Bitmap.h"

class Starts3d
{
    public:
        Starts3d(d_type::Buint numbers,d_type::Bfloat spread,d_type::Bfloat speed);
        void UpdateAndRender(Bitmap*bmp,d_type::Bfloat delta);
        virtual ~Starts3d();
    protected:
    private:
        d_type::Bfloat m_spread,m_speed;
        d_type::Bfloat *m_starX;
        d_type::Bfloat *m_starY;
        d_type::Bfloat *m_starZ;

        void initStar(d_type::Bint index);

};

#endif // STARTS3D_H
