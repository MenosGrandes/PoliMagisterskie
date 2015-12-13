#ifndef PHOTON_H
#define PHOTON_H
#include "Vector3.h"
#include "Colour.h"
#include <iostream>
class Photon
{
public:
    Photon();
    virtual ~Photon();

    Vector3Bf m_position,m_direction;
    Colour m_power; // kolor * intensywnosc swiatla
    d_type::Bint m_phi,m_theta,m_KDflag;



////            std::cout<<this->m_position<<" "<<photon.m_position<<"\n";
//             if(m_position.distance(photon.m_position)>0.0f)
//            {
//            return true;
//            }
//            else
//            {
//            return false;
//            }


};
    struct photonComp
    {
        inline bool operator() (const Photon& struct1, const Photon& struct2)
        {
            return (struct1.m_position<struct2.m_position);
        }
    };
#endif // PHOTON_H
