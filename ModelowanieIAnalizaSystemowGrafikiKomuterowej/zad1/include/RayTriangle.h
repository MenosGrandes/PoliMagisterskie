#ifndef RAYTRIANGLE_H
#define RAYTRIANGLE_H
#include "Vertex3.h"
#include "Raycastable.h"

class RayTriangle : public IRaycastable
{
public:
    RayTriangle(Vertex3Bf a,Vertex3Bf b,Vertex3Bf c,IMaterial *material);
    virtual ~RayTriangle();
    Vertex3Bf getVertex1() const;
    Vertex3Bf getVertex2() const;
    Vertex3Bf getVertex3() const;
    Vector3Vertex3Bf getVertices() const;
    bool intersect(const Ray& ray,d_type::Bfloat &distance,Vector3Bf & normal) const;

protected:
private:
    Vector3Vertex3Bf m_vertex;
};

#endif // RAYTRIANGLE_H
