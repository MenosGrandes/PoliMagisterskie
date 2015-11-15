#ifndef RAYTRIANGLE_H
#define RAYTRIANGLE_H
#include "Vertex3.h"
#include "Raycastable.h"

class RayTriangle : public IRaycastable
{
public:
    RayTriangle(Vertex3Bf a,Vertex3Bf b,Vertex3Bf c);
    virtual ~RayTriangle();
    Vertex3Bf getVertex1() const;
    Vertex3Bf getVertex2() const;
    Vertex3Bf getVertex3() const;
    Vector3Vertex3Bf getVertices() const;
    d_type::BBool intersect(const Ray& ray,d_type::Bfloat &distance,Info &info) const;
    d_type::BBool shadowHit(const Ray& ray,d_type::Bfloat & distance) const;

protected:
private:
    Vector3Vertex3Bf m_vertex;
    Vector3Bf m_FaceNormal;
};

#endif // RAYTRIANGLE_H
