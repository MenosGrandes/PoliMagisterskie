#ifndef RECTMAPPING_H
#define RECTMAPPING_H
#include "IMapping.h"
#include "Plane.h"
class RectMapping : public IMapping
{
public:
    RectMapping();
    RectMapping(const Plane* plane,Vector2Bf scale):m_plane(plane),m_scale(scale){};

    void getTexelCoord(const Vector3Bf &localHitPoint, const d_type::Bint m_width, const d_type::Bint m_height, d_type::Bint& row, d_type::Bint& column) const
    {

        Vector3Bf uAxis=Vector3Bf(m_plane->getNormal().y,m_plane->getNormal().z,-m_plane->getNormal().x);
        Vector3Bf vAxis=Vector3Bf::cross(uAxis,m_plane->getNormal());

        d_type::Bfloat u=Vector3Bf::dotProduct(localHitPoint,uAxis)*m_scale.x;
        d_type::Bfloat v =Vector3Bf::dotProduct(localHitPoint,vAxis)*m_scale.y;
        column =(int)((m_width-1)*u);
        row =(int)((m_height-1)*v);
    }
    virtual ~RectMapping();
protected:
private:
    const Plane * m_plane;
    Vector2Bf m_scale;
};

#endif // RECTMAPPING_H
