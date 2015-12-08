#ifndef PHOTON_H
#define PHOTON_H
#include "Vector3.h"
#include "Colour.h"
class Photon
{
    public:
        Photon();
        virtual ~Photon();

        Vector3Bf m_position;
        Colour m_power; // kolor * intensywnosc swiatla
        d_type::Bint m_phi,m_theta,m_KDflag;
};

#endif // PHOTON_H
