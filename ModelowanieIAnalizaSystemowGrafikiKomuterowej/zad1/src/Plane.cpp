#include "Plane.h"

Plane::Plane():m_normal(),m_inPoint(),m_distance(0)
{

}
Plane::Plane(Vector3Bf normal, Vector3Bf inPoint):m_normal(),m_inPoint(),m_distance(0)
{
m_distance=Vector3Bf::dotProduct(m_normal,m_inPoint);
}

Plane::~Plane()
{

}

Vector3Bf Plane::getNormal() const
{
return m_normal;
}

Vector3Bf Plane::getInPoint() const
{
return m_inPoint;
}

d_type::Bfloat Plane::getDistance() const
{
return m_distance;
}

void Plane::setNormal(const Vector3Bf val)
{
m_normal=val;
}

void Plane::setInPoint(const Vector3Bf val)
{
m_inPoint=val;
}

void Plane::setDistance(const d_type::Bfloat val)
{
m_distance=val;

}

Vector3BfVector Plane::intersect(const Ray& ray) const
{
/*
https://en.wikipedia.org/wiki/Line%E2%80%93plane_intersection
d=((punktWPlaszczyznie - punktPoczatkaPromienia) DOT normalnaPlaszczyzny)/normalnyplaszczyszny DOT kierunekVektora

jezeli  normalnyplaszczyszny DOT kierunekVektora == 0 to plaszczyzna i wektor sa rownolegle
jezeli  ((punktWPlaszczyznie - punktPoczatkaPromienia) DOT normalnaPlaszczyzny)/normalnyplaszczyszny DOT kierunekVektora ==  0 promien znajduje sie na plaszczyznie
jezeli  normalnyplaszczyszny DOT kierunekVektora !=0 to jest intersekcja i obliczamy ja za pomoca wzoru p=d*kierunekVektora + punktPoczatkuPromienia

*/
d_type::Bfloat a;
d_type::Bfloat lDOTn=Vector3Bf::dotProduct(m_normal,ray.getDestination());
Vector3BfVector vec;

if(lDOTn==0)
{
    a=Vector3Bf::dotProduct((m_inPoint - ray.getOrigin()),m_normal);
    if(a == 0)
    {
        std::cout<<"Ma wszystko\n";
    }
    else
    {
        std::cout<<"NIE MA\n";
    }
}
else
{
    vec.push_back(ray.getDestination()*(a/lDOTn) + ray.getOrigin());

}

return vec;


}

