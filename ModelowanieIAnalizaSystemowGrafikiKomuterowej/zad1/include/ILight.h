#ifndef ILIGHT_H
#define ILIGHT_H
#include "Vector3.h"
#include "Colour.h"
#include "Info.h"
#include <vector>
class ILight
{
public:
    ILight();
    virtual ~ILight();
    virtual Vector3Bf getDirection(Info &info) =0;
    virtual Colour L(Info &info)
    {
        return Colour::Black;
    }
    void setShadows(d_type::BBool shadow)
    {
        m_shadows=shadow;
    }
    d_type::BBool castShadows()
    {
        return m_shadows;
    }
    virtual d_type::BBool inShadow(const Ray&ray, const Info&info)=0;

protected:
    d_type::BBool m_shadows;
};
typedef std::vector<ILight*> LightsVector;
#endif // ILIGHT_H
