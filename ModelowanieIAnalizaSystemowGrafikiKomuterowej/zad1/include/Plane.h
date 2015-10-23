#ifndef PLANE_H
#define PLANE_H
#include "Raycastable.h"

class Plane : public IRaycastable
{
public:
    Plane();
    Plane(Vector3Bf normal,Vector3Bf inPoint,IMaterial *material);
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
    bool intersect(const Ray&ray,d_type::Bfloat &distance) const ;

protected:
private:
    Vector3Bf m_normal,m_inPoint;
    d_type::Bfloat m_distance;
};

#endif // PLANE_H
