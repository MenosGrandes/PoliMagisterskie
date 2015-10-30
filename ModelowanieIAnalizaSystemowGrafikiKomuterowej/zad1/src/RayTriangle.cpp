#include "RayTriangle.h"


RayTriangle::~RayTriangle()
{
    //dtor
}
RayTriangle::RayTriangle(Vertex3Bf a, Vertex3Bf b, Vertex3Bf c,IMaterial * mat)
{
    m_vertex.x=(a),m_vertex.y=(b),m_vertex.z=(c);
    m_material=mat;
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
bool RayTriangle::intersect(const Ray& ray,d_type::Bfloat &distance,Vector3Bf & normal) const
{
#define MOOLER
#ifdef MOOLER
    Vector3Bf v0v1 = m_vertex.y.m_position - m_vertex.x.m_position;
    Vector3Bf v0v2 = m_vertex.z.m_position - m_vertex.x.m_position;
    Vector3Bf pvec = Vector3Bf::cross(ray.getDirection(),v0v2);
    float det = Vector3Bf::dotProduct(v0v1,pvec);

// if the determinant is negative the triangle is backfacing
// if the determinant is close to 0, the ray misses the triangle
    if (det < F_EPSILON) return false;

// ray and triangle are parallel if det is close to 0
    //if (fabs(det) < F_EPSILON   ) return false;

    float invDet = 1 / det;

    Vector3Bf tvec = ray.getOrigin() - m_vertex.x.m_position;
    float u = Vector3Bf::dotProduct(tvec,pvec) * invDet;
    if (u < 0 || u > 1) return false;

    Vector3Bf qvec = Vector3Bf::cross(tvec,v0v1);
    float v = Vector3Bf::dotProduct(ray.getDirection(),qvec) * invDet;
    if (v < 0 || u + v > 1) return false;

    distance = Vector3Bf::dotProduct(qvec,v0v2)  * invDet;
    normal=m_vertex.x.m_normal;
    return true;
#endif // MOOLER
#ifdef OTHER

    float a=m_vertex.x.m_position.x - m_vertex.y.m_position.x ;
    float b=m_vertex.x.m_position.x - m_vertex.z.m_position.x ;
    float c=ray.getDirection().x;
    float d=m_vertex.x.m_position.x - ray.getOrigin().x;

    float e=m_vertex.x.m_position.y - m_vertex.y.m_position.y ;
    float f=m_vertex.x.m_position.y - m_vertex.z.m_position.y ;
    float g=ray.getDirection().y;
    float h=m_vertex.x.m_position.y - ray.getOrigin().y;

    float i=m_vertex.x.m_position.z - m_vertex.y.m_position.z ;
    float j=m_vertex.x.m_position.z - m_vertex.z.m_position.z ;
    float k=ray.getDirection().z;
    float l=m_vertex.x.m_position.z - ray.getOrigin().z;

    float m=f*k -g*j;
    float n=h*k - g*l;
    float p=f*l-h*j;
    float q=g*i-e*k;
    float s=e*j-f*i;

    float inv_denim=1.0/(a*m+b*q+c*s);

    float e1=d*m-b*n-c*p;
    float beta=e1*inv_denim;

    if(beta<0.0)
    {
        return false;
    };
    float r=r=e*l-h*i;
    float e2=a*n+d*q+c*r;
    float gamma =e2*inv_denim;

    if(gamma<0.0)
    {
        return false;
    }
    if(beta+gamma>1.0)
    {
        return false;
    }
    float e3=a*p-b*r+d*s;
    float t=e3*inv_denim;
    if(t<F_EPSILON)
    {
        return false;

    }
    distance=t;
    return true;

#endif // OTHER

}
