#include "VertexProcessor.h"

VertexProcessor::VertexProcessor()
{
    this->view2proj=Matrix4Bfloat::Identity;
    this->world2view=Matrix4Bfloat::Identity;
    this->obj2world=Matrix4Bfloat::Identity;
    this->obj2proj=Matrix4Bfloat::Identity;
}

VertexProcessor::~VertexProcessor()
{
    //dtor
}
void VertexProcessor::setPerspective(d_type::Bfloat fovy, d_type::Bfloat aspect, const Vector2Bf& nearfar)
{
    ///KOLUMNOWO MAM!!!!
    fovy *= M_PI/ 360;
    d_type::Bfloat f=cosf(fovy)/sinf(fovy);

    view2proj=Matrix4Bfloat(
                  Vector4Bf(f/aspect,0,0,0), //1,0,0,0
                  Vector4Bf(0,f,0,0), //0,2.4190,0,0
                  Vector4Bf(0,0,(nearfar.y+nearfar.x)/(nearfar.x-nearfar.y),(2*nearfar.y*nearfar.x)/(nearfar.x-nearfar.y)),// 0,0,-1.000002,-1
                  Vector4Bf(0,0,-1,0)//0,0,-0.2,0
              );

//std::cout<<"setPerspective\n "<<view2proj;
}

void VertexProcessor::setLookat( Vector3Bf eye,  Vector3Bf center, Vector3Bf up)
{
    //DOBRZE LICZY
    Vector3Bf f= center - eye; // dobrze
    Vector3Bf::normalize(f);// dobrze
    Vector3Bf::normalize(up);// dobrze
    Vector3Bf s= Vector3Bf::cross(f,up);// dobrze
    Vector3Bf u= Vector3Bf::cross(s,f);// dobrze
   // std::cout<<f<<"\n"<<up<<"\n";
    world2view = Matrix4Bfloat(
                     Vector4Bf(s.x,s.y,s.z,-eye.x), //1,0,0,0
                     Vector4Bf(u.x,u.y,u.z,-eye.y), //0,1,0,0
                     Vector4Bf(-f.x,-f.y,-f.z,-eye.z), // 0,0,1,0
                     Vector4Bf(0,0,0,1)//0,0,-10,1
                 );
                //std::cout<<"w2v "<<world2view<<"\n";

}
void VertexProcessor::multByTranslation(const Vector3Bf& vec)
{
    Matrix4Bfloat m(
        Vector4Bf(1,0,0,vec.x),
        Vector4Bf(0,1,0,vec.y),
        Vector4Bf(0,0,1,vec.z),
        Vector4Bf(0,0,0,1)
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
            v.x*v.y*(1-c)-v.z*s,
            v.x*v.z*(1-c)+v.y*s,
            0

        ),
        Vector4Bf(
            v.y*v.x*(1-c)+v.z*s,
            v.y*v.y*(1-c)+c,
            v.y*v.z*(1-c)-v.x*s,
            0

        ),
        Vector4Bf(
            v.x*v.z*(1-c)-v.y*s,
            v.y*v.z*(1-c)+v.x*s,
            v.z*v.z*(1-c)+c,
            0
        ),
        Vector4Bf(0,0,0,1)
    );

//    std::cout<<m<<"\n";
    obj2world*=m;//*obj2world;

}
Vector3Bf VertexProcessor::addTriangle(Vector3Bf tr)
{
    Vector4Bf r = obj2proj*Vector4Bf(tr.x,tr.y,tr.z,1);


    return Vector3Bf(r.x/r.w,r.y/r.w,r.z/r.w);
//Vector4Bf r = obj2proj*Vector4Bf(tr.x,tr.y,tr.z,1);
//return Vector3Bf(r.x,r.y,r.z);
}
void VertexProcessor::addTriangle(render::Triangle* tri)
{
    Vector4Bf r(0,0,0,0) ;
    r= obj2proj*Vector4Bf(tri->first.x,tri->first.y,tri->first.z,1);
    tri->first = Vector3Bf(r.x/r.w,r.y/r.w,r.z/r.w);
    r = obj2proj*Vector4Bf(tri->second.x,tri->second.y,tri->second.z,1);
    tri->second = Vector3Bf(r.x/r.w,r.y/r.w,r.z/r.w);

    r = obj2proj*Vector4Bf(tri->third.x,tri->third.y,tri->third.z,1);
    tri->third = Vector3Bf(r.x/r.w,r.y/r.w,r.z/r.w);

}
void VertexProcessor::addTriangle(render::TriangleMesh * tri)
{

    std::vector<render::Triangle*> triangles=tri->getTriangles();
    const d_type::Bsize vectorSize=triangles.size();
    for(d_type::Buint i=0;i<vectorSize;i++)
    {
        //addTriangle(triangles[i]);
        triangles[i]->first=addTriangle(triangles[i]->first);
        triangles[i]->second=addTriangle(triangles[i]->second);
        triangles[i]->third=addTriangle(triangles[i]->third);
//    Vector4Bf r= obj2proj*Vector4Bf(triangles.at(i)->first.x,triangles.at(i)->first.y,triangles.at(i)->first.z,1);
//    triangles[i]->first = Vector3Bf(r.x/r.w,r.y/r.w,r.z/r.w);
//    r=Vector4Bf(0,0,0,0);
//
//    r = obj2proj*Vector4Bf(triangles.at(i)->second.x,triangles.at(i)->second.y,triangles.at(i)->second.z,1);
//    triangles[i]->second = Vector3Bf(r.x/r.w,r.y/r.w,r.z/r.w);
//    r=Vector4Bf(0,0,0,0);
//
//    r = obj2proj*Vector4Bf(triangles.at(i)->third.x,triangles.at(i)->third.y,triangles.at(i)->third.z,1);
//    triangles[i]->third = Vector3Bf(r.x/r.w,r.y/r.w,r.z/r.w);
    }
}


void VertexProcessor::setIdentity()
{
    obj2world= Matrix4Bfloat::Identity;
}

void VertexProcessor::transform()
{
//    Matrix4Bfloat obj2view= ;
    obj2proj = view2proj*(world2view*obj2world);


}
