#ifndef RAYCASTABLE_H
#define RAYCASTABLE_H
#include "Ray.h"

class Raycastable
{
public:
    virtual Vector3BfVector intersect(const Ray& ray) const = 0;

};

#endif // RAYCASTABLE_H
