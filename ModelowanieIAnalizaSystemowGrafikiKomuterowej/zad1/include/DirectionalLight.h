#ifndef DIRECTIONALLIGHT_H
#define DIRECTIONALLIGHT_H
#include "ILight.h"

class DirectionalLight : public ILight
{
public:
    DirectionalLight();
    virtual ~DirectionalLight();
    Vector3Bf getDirection(Info &info)
    {
        return m_direction;
    }
    Colour L(Info &info)
    {
        return (m_ls *m_colour);
    }

    d_type::Bfloat m_ls;
    Colour m_colour;
    Vector3Bf m_direction;
};

#endif // DIRECTIONALLIGHT_H
