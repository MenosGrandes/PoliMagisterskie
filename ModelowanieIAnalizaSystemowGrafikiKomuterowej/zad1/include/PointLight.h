#ifndef POINTLIGHT_H
#define POINTLIGHT_H
#include "ILight.h"
#include <vector>
class PointLight : public ILight
{
public:
    PointLight(Vector3Bf pos,Colour c);
    virtual ~PointLight();
    void setPosition(const Vector3Bf &pos);
    Vector3Bf getPosition()const;
private:
    Vector3Bf m_position;
};
typedef std::vector<PointLight> PointLightVector;
#endif // POINTLIGHT_H
