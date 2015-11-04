#include "Box.h"

Box::Box()
{
    //ctor
}

Box::Box(const Vector3Bf& min, const Vector3Bf& max):m_min(min),m_max(max)
{
//    this->m_material=new PerfectDifuse(Colour::Black);
}

void Box::setMin(const Vector3Bf& min)
{
    this->m_min=min;
}

void Box::setMax(const Vector3Bf& max)
{
    this->m_max=max;
}

Box::~Box()
{
    //dtor
}
d_type::BBool Box::intersect(const Ray& r, d_type::Bfloat& distance,Info &info) const
{
    d_type::Bfloat tmin = (m_min.x - r.getOrigin().x) / r.getDirection().x;
    d_type::Bfloat tmax = (m_max.x - r.getOrigin().x) / r.getDirection().x;

    if (tmin > tmax) std::swap(tmin, tmax);

    d_type::Bfloat tymin = (m_min.y - r.getOrigin().y) / r.getDirection().y;
    d_type::Bfloat tymax = (m_max.y - r.getOrigin().y) / r.getDirection().y;

    if (tymin > tymax) std::swap(tymin, tymax);

    if ((tmin > tymax) || (tymin > tmax))
        return false;

    if (tymin > tmin)
        tmin = tymin;

    if (tymax < tmax)
        tmax = tymax;

    float tzmin = (m_min.z - r.getOrigin().z) / r.getDirection().z;
    float tzmax = (m_max.z - r.getOrigin().z) / r.getDirection().z;

    if (tzmin > tzmax) std::swap(tzmin, tzmax);

    if ((tmin > tzmax) || (tzmin > tmax))
        return false;

    if (tzmin > tmin)
        tmin = tzmin;

    if (tzmax < tmax)
        tmax = tzmax;

    distance = tmin;

    if (distance < 0)
    {
        distance = tmax;
        if (distance < 0) return false;
    }

    return true;
}

Vector3Bf Box::getMin() const
{
    return m_min;
}



Vector3Bf Box::getMax() const
{
    return m_max;
}


