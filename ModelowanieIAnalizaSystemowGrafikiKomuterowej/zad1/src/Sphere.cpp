#include "Sphere.h"

Sphere::Sphere(Vector3Bf center, d_type::Bfloat radius):IRaycastable(),m_center(center),m_radius(radius)
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

bool Sphere::intersect(const Ray& ray,d_type::Bfloat &distance,Info &info) const
{
//http://stackoverflow.com/questions/6533856/ray-sphere-intersection


#define M_INTER
#ifdef MY_INTER

    FastSqrt sqrtf;
    Vector3Bf direction=ray.getDirection();
    Vector3Bf oc=ray.getOrigin()-m_center;

    d_type::Bfloat a=direction.lengthSquared();

    d_type::Bfloat b=(Vector3Bf::dotProduct(oc,direction*2.0f));

    d_type::Bfloat c=oc.lengthSquared() - m_sqRadius;

    d_type::Bfloat delta=b*b - 4*a*c;
    std::vector<Vector3Bf> vec;
    if(delta>0)
    {

        d_type::Bfloat t1 = ((-1)*b-sqrtf.sqrt7(delta))/(2*a);
        if(t1> F_EPSILON)
        {
            vec.push_back(Vector3Bf(ray.getOrigin()+t1*direction));
        }
        d_type::Bfloat t2 = ((-1)*b+sqrtf.sqrt7(delta))/(2*a);

        if(t2>F_EPSILON)
        {
            vec.push_back(Vector3Bf(ray.getOrigin()+t2*direction));
        }

    }
    else if(delta==0)
    {
        d_type::Bfloat t = -b/(2*a);
        if(t>0)
        {
            vec.push_back(Vector3Bf(ray.getOrigin()+t*direction));
        }

    }
    return vec;

#endif // MY_INTER
#ifdef M_INTER





    d_type::Bfloat t;

    FastSqrt sqrtf;
    Vector3Bf direction=ray.getDirection();
    Vector3Bf oc=ray.getOrigin()-m_center;

    d_type::Bfloat a=direction.lengthSquared();

    d_type::Bfloat b=(Vector3Bf::dotProduct(oc*2.0f,direction));

    d_type::Bfloat c=oc.lengthSquared() - m_sqRadius;

    d_type::Bfloat delta=b*b - 4*a*c;
    if(delta <0)
    {
        return false;
    }

    t=(-b-sqrtf.sqrt7(delta))/(2*a);
    if(t<F_EPSILON)
    {
        t=(-b+sqrtf.sqrt7(delta))/(2*a);

    }
    if(t<F_EPSILON)
    {
        return false;
    }





        info.m_localHitPoint=(ray.getOrigin()+(ray.getDirection()*t));
    info.m_normal=info.m_localHitPoint-m_center;
    Vector3Bf::normalize(info.m_normal);
    distance=t;
    return true;


#endif // M_INTER

}
