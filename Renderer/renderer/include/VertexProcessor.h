#ifndef VERTEXPROCESSOR_H
#define VERTEXPROCESSOR_H
#include "Vertex3.h"
#include "Vector2.h"
#include "Matrix4.h"
#include "Fragment.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include <vector>
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

    void setIdentity();
    void transform();
    Vertex3Bf tr(Vertex3Bf v);
    void addLight(ILight * light);
protected:
private:
    Matrix4Bfloat view2proj,world2view,obj2world,obj2proj,obj2view;
    std::vector<ILight*> m_lights;
};

#endif // VERTEXPROCESSOR_H
