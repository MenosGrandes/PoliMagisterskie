#include "Plane.h"

Plane::Plane():m_normal(),m_inPoint()
{
    this->m_material=nullptr;
}
Plane::Plane(Vector3Bf inPoint,Vector3Bf normal,IMaterial *material):m_normal(normal),m_inPoint(inPoint)
{
    this->m_material=material;
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



void Plane::setNormal(const Vector3Bf val)
{
    m_normal=val;
}

void Plane::setInPoint(const Vector3Bf val)
{
    m_inPoint=val;
}


    bool Plane::intersect(const Ray&ray,d_type::Bfloat &distance,Vector3Bf & normal) const
{
    /*
    https://en.wikipedia.org/wiki/Line%E2%80%93plane_intersection
    d=((punktWPlaszczyznie - punktPoczatkaPromienia) DOT normalnaPlaszczyzny)/normalnyplaszczyszny DOT kierunekVektora

    jezeli  normalnyplaszczyszny DOT kierunekVektora == 0 to plaszczyzna i wektor sa rownolegle
    jezeli  ((punktWPlaszczyznie - punktPoczatkaPromienia) DOT normalnaPlaszczyzny)/normalnyplaszczyszny DOT kierunekVektora ==  0 promien znajduje sie na plaszczyznie
    jezeli  normalnyplaszczyszny DOT kierunekVektora !=0 to jest intersekcja i obliczamy ja za pomoca wzoru p=d*kierunekVektora + punktPoczatkuPromienia

    */

    d_type::Bfloat t=Vector3Bf::dotProduct((m_inPoint - ray.getOrigin()),m_normal) /  Vector3Bf::dotProduct(m_normal,ray.getDirection());
    Vector3BfVector vec;
    if( t > F_EPSILON)
    {
        distance=t;
        normal=m_normal;
        return true;
    }


    return false;;


}

