#ifndef VERTEXPROCESSOR_H
#define VERTEXPROCESSOR_H

#include "Matrix4.h"
#include "Triangle.h"
class VertexProcessor
{
public:
    VertexProcessor();
    virtual ~VertexProcessor();
    void setPerspective(d_type::Bfloat fovy,d_type::Bfloat aspect, Vector2Bf nearfar);
    void setLookat(Vector3Bf eye,Vector3Bf center,Vector3Bf up);
    void multByTranslation(Vector3Bf vec);
    void multByScale(Vector3Bf vec);
    void multByRotation(d_type::Bfloat a,Vector3Bf vec);
    void addTriangle();
protected:
private:
    Matrix4Bfloat view2proj,world2view,obj2world;
};

#endif // VERTEXPROCESSOR_H
