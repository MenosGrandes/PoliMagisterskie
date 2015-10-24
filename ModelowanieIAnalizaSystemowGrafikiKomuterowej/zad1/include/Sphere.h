#ifndef SPHERE_H
#define SPHERE_H
#include "Raycastable.h"
#include <iostream>
#include "../src/algorithms.hpp"
class Sphere : public IRaycastable
{
public:
    Sphere(Vector3Bf center,d_type::Bfloat radius,IMaterial *material);

    //GETTERS
    Vector3Bf getCenter() const;
    d_type::Buint getRadius() const;

    //SETTERS
    void setCenter(const Vector3Bf center);
    void setRadius(const d_type::Buint center);
    //METHODS
    bool intersect(const Ray&ray,d_type::Bfloat &distance,Vector3Bf & normal) const ;
protected:
private:
    //MEMBERS
    Vector3Bf m_center;
    d_type::Buint m_radius;
    d_type::Bfloat m_sqRadius;



};

#endif // SPHERE_H
