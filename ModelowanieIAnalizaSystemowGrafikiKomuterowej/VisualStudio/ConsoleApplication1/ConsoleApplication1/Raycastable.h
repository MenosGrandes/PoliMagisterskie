#ifndef RAYCASTABLE_H
#define RAYCASTABLE_H
#include "Ray.h"
#include <vector>

class IRaycastable
{
public:
    virtual Vector3BfVector intersect(const Ray& ray) const=0 ;

};
typedef std::vector<IRaycastable*> RaycastableVector;
#endif // RAYCASTABLE_H
