#ifndef PLANE_H
#define PLANE_H
#include "Raycastable.h"

class Plane : public Raycastable
{
public:
    Plane();
    virtual ~Plane();
    //GETTERS
    Vector3Bf getNormal() const;
    Vector3Bf getInPoint() const;
    d_type::Bfloat getDistance() const;

    //SETTERS
    void setNormal(const Vector3Bf val) ;
    void setInPoint(const Vector3Bf val ) ;
    void setDistance(const d_type::Bfloat val) ;

protected:
private:
    Vector3Bf m_normal,inPoint;
    d_type::Bfloat m_distance;
};

#endif // PLANE_H
