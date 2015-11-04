#ifndef BOX_H
#define BOX_H
#include "Raycastable.h"
class Box : public IRaycastable
{
public:
    Box();
    Box(const Vector3Bf& min,const Vector3Bf& max);
    virtual ~Box();
    virtual d_type::BBool intersect(const Ray& ray,d_type::Bfloat & distance,Info &info) const;
    Vector3Bf getMin() const;
    void setMin(const Vector3Bf& min );
    Vector3Bf getMax() const;
    void setMax(const Vector3Bf& max);

private:
    Vector3Bf m_min,m_max;
};

#endif // BOX_H
