#ifndef PLANE_H
#define PLANE_H
#include "Raycastable.h"

class Plane : public Raycastable
{
public:
    Plane();
    Plane(Vector3Bf normal,Vector3Bf inPoint);
    virtual ~Plane();
    //GETTERS
    Vector3Bf getNormal() const;
    Vector3Bf getInPoint() const;
    d_type::Bfloat getDistance() const;
    void calculateEquationOfPlane();
    //SETTERS
    void setNormal(const Vector3Bf val) ;
    void setInPoint(const Vector3Bf val ) ;
    void setDistance(const d_type::Bfloat val) ;
    virtual Vector3BfVector intersect(const Ray&ray) const ;

protected:
private:
    Vector3Bf m_normal,m_inPoint;
    d_type::Bfloat m_distance;
};

#endif // PLANE_H
