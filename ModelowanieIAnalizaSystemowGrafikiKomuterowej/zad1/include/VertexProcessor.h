#ifndef VERTEXPROCESSOR_H
#define VERTEXPROCESSOR_H

#include "Matrix4.h"
#include "Triangle.h"
#include "Camera.h"
class VertexProcessor
{
public:
    VertexProcessor();
    virtual ~VertexProcessor();
    void setPerspective(d_type::Bfloat fovy, d_type::Bfloat aspect, const Vector2Bf& nearfar);
    void setLookat( Vector3Bf eye,  Vector3Bf center, Vector3Bf up);
    void multByTranslation(const Vector3Bf& vec);
    void multByScale(const Vector3Bf& vec);
    void multByRotation(d_type::Bfloat a,Vector3Bf vec);
    Vector3Bf addTriangle(Vector3Bf tr);
    //for camera
    void setPerspective(d_type::Bfloat aspect,const Camera& camera);
    void setIdentity();
    void transform();
protected:
private:
    Matrix4Bfloat view2proj,world2view,obj2world,obj2proj;
};

#endif // VERTEXPROCESSOR_H
