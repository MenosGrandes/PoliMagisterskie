#ifndef PLANE_H
#define PLANE_H
#include "Raycastable.h"

class Plane : public IRaycastable
{
public:
    Plane();
    Plane(Vector3Bf normal,Vector3Bf inPoint);
    virtual ~Plane();
    //GETTERS
    Vector3Bf getNormal() const;
    Vector3Bf getInPoint() const;
    //SETTERS
    void setNormal(const Vector3Bf val) ;
    void setInPoint(const Vector3Bf val ) ;
    d_type::BBool intersect(const Ray&ray,d_type::Bfloat &distance,Info &info) const ;
    d_type::BBool shadowHit(const Ray& ray,d_type::Bfloat & distance)const;

protected:
private:
    Vector3Bf m_normal,m_inPoint;
};

#endif // PLANE_H
