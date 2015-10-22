#include "VertexProcessor.h"

VertexProcessor::VertexProcessor()
{
    this->view2proj=Matrix4Bfloat::Identity;
    this->world2view=Matrix4Bfloat::Identity;
    this->obj2world=Matrix4Bfloat::Identity;
}

VertexProcessor::~VertexProcessor()
{
    //dtor
}
void VertexProcessor::setPerspective(d_type::Bfloat fovy, d_type::Bfloat aspect, const Vector2Bf& nearfar)
{

	fovy *= M_PI/ 360;
    d_type::Bfloat f=cosf(fovy)/sinf(fovy);
    view2proj=Matrix4Bfloat(
                  Vector4Bf(f/aspect,0,0,0),
                  Vector4Bf(0,f,0,0),
                  Vector4Bf(0,0,(nearfar.x+nearfar.y)/(nearfar.x-nearfar.y),-1),
                  Vector4Bf(0,0,(2*nearfar.x*nearfar.y)/(nearfar.x-nearfar.y),0)
              );


}

void VertexProcessor::setLookat( Vector3Bf eye,  Vector3Bf center, Vector3Bf up)
{
    Vector3Bf f= center - eye;
    Vector3Bf::normalize(f);
    Vector3Bf::normalize(up);
    Vector3Bf s= Vector3Bf::cross(f,up);
    Vector3Bf u= Vector3Bf::cross(s,f);
    world2view = Matrix4Bfloat(
                     Vector4Bf(s.x,u.x,-f.x,0),
                     Vector4Bf(s.y,u.y,-f.y,0),
                     Vector4Bf(s.z,u.z,-f.z,0),
                     Vector4Bf(-eye.x,-eye.y,-eye.z,1)
                 );

}
void VertexProcessor::multByTranslation(const Vector3Bf& vec)
{
    Matrix4Bfloat m(
        Vector4Bf(1,0,0,0),
        Vector4Bf(0,1,0,0),
        Vector4Bf(0,0,1,0),
        Vector4Bf(vec.x,vec.y,vec.z,1)
    );

    obj2world*=m;
}

void VertexProcessor::multByScale(const Vector3Bf& vec)
{
    Matrix4Bfloat m(
        Vector4Bf(vec.x,0,0,0),
        Vector4Bf(0,vec.y,0,0),
        Vector4Bf(0,0,vec.z,0),
        Vector4Bf(0,0,0,1)
    );

    obj2world*=m;
}
void VertexProcessor::multByRotation(d_type::Bfloat a, Vector3Bf v)
{
    d_type::Bfloat s=sinf(a*M_PI/180),c=cosf(a*M_PI/180);
    Vector3Bf::normalize(v);

    Matrix4Bfloat m(
        Vector4Bf(
            v.x*v.x*(1-c)+c,
            v.y*v.x*(1-c)+v.z*s,
            v.x*v.z*(1-c)-v.y*s,
            0
        ),
        Vector4Bf(
            v.x*v.y*(1-c)-v.z*s,
            v.y*v.y*(1-c)+c,
            v.y*v.z*(1-c)+v.x*s,
            0
        ),
        Vector4Bf(
            v.x*v.z*(1-c)+v.y*s,
            v.y*v.z*(1-c)-v.x*s,
            v.z*v.z*(1-c)+c,
            0
        ),
        Vector4Bf(0,0,0,1)
    );
    obj2world*=m;

}
Vector3Bf VertexProcessor::addTriangle(Vector3Bf tr)
{
    Vector4Bf r = obj2proj*Vector4Bf(tr.x,tr.y,tr.z,1);
    return Vector3Bf(r.x/r.w,r.y/r.w,r.z/r.w);
}


void VertexProcessor::setIdentity()
{
    obj2world= Matrix4Bfloat::Identity;
}

void VertexProcessor::transform()
{
    Matrix4Bfloat obj2view = world2view*obj2world;
    obj2proj = view2proj*obj2view;
}
