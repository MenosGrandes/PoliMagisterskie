#ifndef SPHERE_H
#define SPHERE_H
#include "Raycastable.h"
class Sphere : public Raycastable
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
    virtual d_type::Buint intersect(const Ray&ray,d_type::Bfloat &dist) const ;
protected:
private:
    //MEMBERS
    Vector3Bf m_center;
    d_type::Buint m_radius;
    d_type::Buint m_sqRadius;

};

#endif // SPHERE_H
