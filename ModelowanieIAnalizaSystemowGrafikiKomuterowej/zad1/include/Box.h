#ifndef BOX_H
#define BOX_H
#include "Vector3.h"
#include "Ray.h"
class Box
{
public:
    d_type::Bfloat x0, x1, y0, y1, z0, z1;

    Box(void);

    Box(const d_type::Bfloat x0, const d_type::Bfloat x1,
        const d_type::Bfloat y0, const d_type::Bfloat y1,
        const d_type::Bfloat z0, const d_type::Bfloat z1);

    Box(const Vector3Bf p0, const Vector3Bf p1);

    Box(const Box& bbox);

    Box&
    operator=(const Box& bbox);

    Box*
    clone(void) const;

    ~Box(void);

    bool
    hit(const Ray& ray) const;

    bool
    inside(const Vector3Bf& p) const;


};

#endif // BOX_H
