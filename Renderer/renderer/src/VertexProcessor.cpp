#include "VertexProcessor.h"

VertexProcessor::VertexProcessor()
{
    this->view2proj=Matrix4Bfloat::Identity;
    this->world2view=Matrix4Bfloat::Identity;
    this->obj2world=Matrix4Bfloat::Identity;
    this->obj2proj=Matrix4Bfloat::Identity;
    this->obj2view=Matrix4Bfloat::Identity;
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



void VertexProcessor::setIdentity()
{
    obj2world= Matrix4Bfloat::Identity;
}

void VertexProcessor::transform()
{
    obj2view= (world2view*obj2world);
    obj2proj = view2proj*obj2view;


}
Vertex3Bf VertexProcessor::tr(Vertex3Bf v)
{
    Fragment frag;
    ILight * light= new DirectionalLight(Vector3Bf(0,0,30));

    Vector4Bf p = obj2proj*Vector4Bf(v.m_position.x,v.m_position.y,v.m_position.z,1);

    // Przekszta³cenia do wyliczenia wiat³a
    Vector4Bf lp = obj2view * Vector4Bf(-v.m_position.x,-v.m_position.y,-v.m_position.z,1);
    Vector4Bf n = obj2view * Vector4Bf(v.m_normal.x,v.m_normal.y,v.m_normal.z,1);

    frag.m_position = v.m_position;
    frag.m_normal = Vector3Bf(n.x / n.w, n.y / n.w, n.z / n.w);
    Vector3Bf::normalize(frag.m_normal);//	frag.normal.Normalize();
    frag.m_negativePosToView = Vector3Bf(lp.x / lp.w, lp.y / lp.w, lp.z / lp.w);

   Vector3Bf colour = light->calculate(frag);
   std::cout<<colour<<"\n";
   Colour c(colour.x,colour.y,colour.z);
    //cout << L;
    return Vertex3Bf(Vector3Bf(p.x / p.w, p.y / p.w, p.z / p.w),
                  v.m_normal,
                  v.m_color);
}
