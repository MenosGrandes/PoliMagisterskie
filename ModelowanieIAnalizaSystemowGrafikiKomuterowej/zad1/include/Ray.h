#ifndef RAY_H
#define RAY_H
#include "Vector3.h"
#include <vector>
#include <limits>
#define DESTINATION 0
#define DIRECTION 1


class Ray
{
public:
    Ray():m_origin(),m_direction(),m_destination()
    {
    }


    Ray(Vector3Bf origin,Vector3Bf vec,bool destORDir):m_origin(origin)
    {
        if(destORDir == DESTINATION)
        {
            m_destination=vec;
            m_direction=m_destination-m_origin;
        }
        else
        {
            m_direction=vec;
        }

    }
    //GETTERS
    Vector3Bf getOrigin() const
    {
        return m_origin;
    }
    Vector3Bf getDirection() const
    {
        return m_direction;
    }
    Vector3Bf getDestination() const
    {
        return m_destination;
    }

    //SETTERS
    void setOrigin(const Vector3Bf val)
    {
        m_origin = val;
    }
    void setDirection(const Vector3Bf val)
    {
        m_direction = val;
    }
    void setDestination(const Vector3Bf val)
    {
        m_destination = val;
    }


protected:
private:
    Vector3Bf m_origin,m_direction, m_destination;

};

#endif // RAY_H
