#include "RayTriangle.h"


RayTriangle::~RayTriangle()
{
    //dtor
}
RayTriangle::RayTriangle(Vertex3Bf a, Vertex3Bf b, Vertex3Bf c)
{
    //https://www.opengl.org/wiki/Calculating_a_Surface_Normal
    m_vertex.x=(a),m_vertex.y=(b),m_vertex.z=(c);

Vector3Bf U = Vector3Bf(b.m_position - a.m_position);
Vector3Bf V = Vector3Bf(c.m_position - a.m_position);

m_FaceNormal.x=U.y*V.z - U.z*V.y;
m_FaceNormal.y=U.z*V.x - U.x*V.z;
m_FaceNormal.z=U.x*V.y - U.y*V.x;


}

Vertex3Bf RayTriangle::getVertex1() const
{
    return m_vertex.x;
}

Vertex3Bf RayTriangle::getVertex2() const
{
    return m_vertex.y;

}

Vertex3Bf RayTriangle::getVertex3() const
{
    return m_vertex.z;

}
Vector3Vertex3Bf RayTriangle::getVertices() const
{
    return m_vertex;
}
bool RayTriangle::intersect(const Ray& ray,d_type::Bfloat &distance,Info &info) const
{

    Vector3Bf v0v1 = m_vertex.y.m_position - m_vertex.x.m_position;
    Vector3Bf v0v2 = m_vertex.z.m_position - m_vertex.x.m_position;
    Vector3Bf pvec = Vector3Bf::cross(ray.getDirection(),v0v2);
    float det = Vector3Bf::dotProduct(v0v1,pvec);

// if the determinant is negative the triangle is backfacing
// if the determinant is close to 0, the ray misses the triangle
    //if (det < F_EPSILON) return false;

// ray and triangle are parallel if det is close to 0
    if (fabs(det) < F_EPSILON   ) return false;

    float invDet = 1 / det;

    Vector3Bf tvec = ray.getOrigin() - m_vertex.x.m_position;
    float u = Vector3Bf::dotProduct(tvec,pvec) * invDet;
    if (u < 0 || u > 1) return false;

    Vector3Bf qvec = Vector3Bf::cross(tvec,v0v1);
    float v = Vector3Bf::dotProduct(ray.getDirection(),qvec) * invDet;
    if (v < 0 || u + v > 1) return false;

    distance = Vector3Bf::dotProduct(qvec,v0v2)  * invDet;

    info.m_normal=m_FaceNormal;
    info.m_localHitPoint=ray.getOrigin()+distance*ray.getDirection();
    return true;


}
