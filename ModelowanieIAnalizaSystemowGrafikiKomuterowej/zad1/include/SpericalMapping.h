#ifndef SPERICALMAPPING_H
#define SPERICALMAPPING_H
#include "IMapping.h"

class SpericalMapping : public IMapping
{
public:
    SpericalMapping();

    void getTexelCoord(const Vector3Bf &localHitPoint, const d_type::Bint m_width, const d_type::Bint m_height, d_type::Bint& row, d_type::Bint& column) const
    {
        float theta = acos(localHitPoint.y);
        float phi = atan2(localHitPoint.x, localHitPoint.z);

        if (phi < 0.0)
                phi += TWO_PI;

        // map theta and phi to u, v (range is 0 to 1)

        float u = phi * INV_TWO_PI;
        float v = 1.0 - theta * INV_PI;

        // map u and v to texel coordinates

        column = (int) ((m_width - 1) * u);
        row = (int) ((m_height - 1) * v);

    }
    virtual ~SpericalMapping();
protected:
private:
};

#endif // SPERICALMAPPING_H
