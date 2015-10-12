#include "Sphere.h"

Sphere::Sphere(Vector3Bf center, d_type::Bfloat radius):m_center(center),m_radius(radius),Raycastable()
{
    m_sqRadius=m_radius*m_radius;
}


Vector3Bf Sphere::getCenter() const
{
    return m_center;
}

d_type::Buint Sphere::getRadius() const
{
    return m_radius;
}

void Sphere::setCenter(const Vector3Bf center)
{
    m_center=center;
}

void Sphere::setRadius(d_type::Buint radius)
{
    m_radius=radius;
}

Buint Sphere::intersect(const Ray& ray, d_type::Bfloat &dist) const
{
    Vector3Bf v_tmp=ray.getOrigin() - m_center; // difference between origin of RAY and center of Sphere
    d_type::Bfloat b= -(v_tmp.dotProduct(v_tmp,ray.getDirection())); // -
    d_type::Bfloat det=( b*b )*(-v_tmp.dotProduct(v_tmp,v_tmp)) + (m_sqRadius); // b^2 - 4*a*c

    if(det>0)
    {
        det=sqrtf(det);
        d_type::Bfloat i1=b-det;
        d_type::Bfloat i2=b+det;
        if(i2 > 0)
        {
            if(i1<0)
            {
                if(i2<dist)
                {
                    dist=i2;
                    return RAY_HIT_POINTS;
                }
            }
            else
            {
                if(i1< dist)
                {
                    dist=i1;
                    return RAY_HIT_POINT;
                }

            }
        }


    }
    dist=0;
    return RAY_MISS;




}
