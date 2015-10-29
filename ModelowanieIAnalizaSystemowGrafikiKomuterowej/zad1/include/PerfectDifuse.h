#ifndef PERFECTDIFUSE_H
#define PERFECTDIFUSE_H
#include "IMaterial.h"

class PerfectDifuse : public IMaterial
{
public:
    PerfectDifuse(Colour c);
    PerfectDifuse();

    virtual ~PerfectDifuse();
    Colour radiance(PointLight pl,const Vector3Bf &hitPoint, const Vector3Bf &normal)
    {
        Vector3Bf inDir=pl.getPosition()-hitPoint;
        Vector3Bf::normalize(inDir);
        d_type::Bfloat diffuseFactor=Vector3Bf::dotProduct(normal,inDir);
        if(diffuseFactor < 0)
        {
            return Colour::Black;
        }
        return pl.getColor() * m_color*diffuseFactor;
    }

protected:
private:

};

#endif // PERFECTDIFUSE_H
