#include "Sphere.h"
const double Sphere::kEpsilon = 0.001;

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

    t=(-b-sqrt(delta))/(2*a);
    if(t<kEpsilon)
    {
        t=(-b+sqrt(delta))/(2*a);

    }
    if(t<kEpsilon)
    {
        return false;
    }





    info.m_localHitPoint=(ray.getOrigin()+(ray.getDirection()*t));
    info.m_normal=info.m_localHitPoint-m_center;
    Vector3Bf::normalize(info.m_normal);
    distance=t;
    return true;




//        d_type::Bfloat          t;
//        Vector3Bf        temp    = ray.getOrigin() - m_center;
//        d_type::Bfloat          a               = Vector3Bf::dotProduct(ray.getDirection() , ray.getDirection());
//        d_type::Bfloat          b               = 2.0 * Vector3Bf::dotProduct(temp , ray.getDirection());
//        d_type::Bfloat          c               = Vector3Bf::dotProduct(temp , temp) - m_radius * m_radius;
//        d_type::Bfloat          disc    = b * b - 4.0 * a * c;
//
//        if (disc < 0.0)
//                return(false);
//        else {
//                d_type::Bfloat e = sqrt(disc);
//                d_type::Bfloat denom = 2.0 * a;
//                t = (-b - e) / denom;    // smaller root
//
//                if (t > kEpsilon) {
//                        distance = t;
//                        info.m_normal        = (temp + t * ray.getDirection()) / m_radius;
//                        info.m_localHitPoint = ray.getOrigin() + t * ray.getDirection();
//                        return (true);
//                }
//
//                t = (-b + e) / denom;    // larger root
//
//                if (t > kEpsilon) {
//                        distance = t;
//                        info.m_normal   = (temp + t * ray.getDirection()) / m_radius;
//
//                        info.m_localHitPoint = ray.getOrigin() + t * ray.getDirection();
//
//                        return (true);
//                }
//        }
//
//        return (false);

#endif // M_INTER

}

Box Sphere::getBoundingBox(void) const {
                double delta = 0.0001;
        //
        //      return(BBox(min(p0.x, p0.x + a.x + b.x) - delta, max(p0.x, p0.x + a.x + b.x) + delta,
        //                              min(p0.y, p0.y + a.y + b.y) - delta, max(p0.y, p0.y + a.y + b.y) + delta,
        //                              min(p0.z, p0.z + a.z + b.z) - delta, max(p0.z, p0.z + a.z + b.z) + delta));

        return (Box(Vector3Bf (m_center.x - m_radius - delta, m_center.y - m_radius - delta, m_center.z - m_radius - delta),
                 Vector3Bf(m_center.x + m_radius + delta, m_center.y + m_radius + delta, m_center.z + m_radius + delta)));
}

d_type::BBool Sphere::shadowHit(const Ray& ray, d_type::Bfloat& distance) const
{

d_type::Bfloat t;

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

    t=(-b-sqrt(delta))/(2*a);
    if(t<kEpsilon)
    {
        t=(-b+sqrt(delta))/(2*a);

    }
    if(t<kEpsilon)
    {
        return false;
    }
    distance=t;
    return true;
}
