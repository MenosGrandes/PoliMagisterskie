#ifndef RAYCASTABLE_H
#define RAYCASTABLE_H
#include "Ray.h"

class Raycastable
{
public:
    virtual d_type::Buint intersect(const Ray& ray, d_type::Bfloat &dist) const = 0;

};

#endif // RAYCASTABLE_H
