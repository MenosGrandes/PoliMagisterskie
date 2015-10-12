#ifndef RAY_H
#define RAY_H
#include "Vector3.h"

//DEFINES TO RAY
#define RAY_MISS 0
#define RAY_HIT_POINT 1
#define RAY_HIT_POINTS 2


class Ray
{
public:
    Ray():m_origin(),m_direction(),m_destination(),m_distance(0) {}

    Ray(Vector3Bf origin,Vector3Bf direction,Vector3Bf destination=Vector3Bf()):m_origin(origin),m_direction(direction),m_destination(destination) {}

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
    Vector3Bf m_origin;
    Vector3Bf m_direction;
    Vector3Bf m_destination;
    d_type::Bfloat m_distance;

};

#endif // RAY_H
