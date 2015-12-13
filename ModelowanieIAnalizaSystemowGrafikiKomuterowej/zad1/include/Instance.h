#ifndef INSTANCE_H
#define INSTANCE_H
#include "Raycastable.h"
#include "Box.h"
#include "Info.h"
#include "Matrix4.h"
class Instance : public IRaycastable
{
public:
    Instance();
    virtual ~Instance();

    Instance(const IRaycastable* obj_ptr);

    Instance(const Instance& instance);


    void
    computeBoundingBox(void);

    virtual Box
    getBoundingBox(void) const;

    virtual d_type::BBool
    shadowHit(const Ray& ray, d_type::Bfloat& tmin) const;

    virtual d_type::BBool
    intersect(const Ray& ray, d_type::Bfloat& tmin, Info& sr) const;

    void translate(const d_type::Bfloat dx, const d_type::Bfloat dy, const d_type::Bfloat dz);

    void rotateX(const d_type::Bfloat theta);

    void rotateY(const d_type::Bfloat theta);

    void rotateZ(const d_type::Bfloat theta);

    void  shear(const d_type::Bfloat xy, const d_type::Bfloat xz, const d_type::Bfloat yx, const d_type::Bfloat yz, const d_type::Bfloat zx, const d_type::Bfloat zy);

    void  scale(const d_type::Bfloat x_scale, const d_type::Bfloat y_scale, const d_type::Bfloat z_scale);

    void  scale(const d_type::Bfloat s);

    void reflectAcrossXaxis();

    void  reflectAcrossYaxis();

    void  reflectAcrossZaxis();

    void transformTexture(const bool trans);


protected:
private:
    const IRaycastable * m_object;
    Matrix4 m_invMatrix;
    d_type::BBool m_transformoTexture;
    static Matrix4 m_forwardMatrix;
    Box m_bbox;
};

#endif // INSTANCE_H
