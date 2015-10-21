#ifndef SPHERE_H
#define SPHERE_H
#include "Raycastable.h"
#include <iostream>
class Sphere : public IRaycastable
{
public:
    Sphere(Vector3Bf center,d_type::Bfloat radius);

    //GETTERS
    Vector3Bf getCenter() const;
    d_type::Buint getRadius() const;

    //SETTERS
    void setCenter(const Vector3Bf center);
    void setRadius(const d_type::Buint center);
    //METHODS
     Vector3BfVector intersect(const Ray&ray) const ;
protected:
private:
    //MEMBERS
    Vector3Bf m_center;
    d_type::Buint m_radius;
    d_type::Bfloat m_sqRadius;



};

#endif // SPHERE_H
