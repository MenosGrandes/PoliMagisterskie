#ifndef PHOTONMAP_H
#define PHOTONMAP_H
#include <vector>
#include "Photon.h"
#include "PointLight.h"
#include "RayTracer.h"
#include "PhongMaterial.h"
#include "MatteMaterial.h"
class PhotonMap
{
    public:
        PhotonMap();
        PhotonMap(int maxPhotons,RayTracer rayTr);
        virtual ~PhotonMap();
        void tracePhoton(Photon p);
std::vector<Photon> getNearestPhotons(const Vector3Bf& centerOfSphere, const d_type::Buint howMuchPhotons, const d_type::Bfloat radius) const;
        Colour radiance(const Vector3Bf & hitPoint,const Vector3Bf & normalInHitPoint,const Vector3Bf & directionToObserver);
        void mapPhotons();
    protected:
    private:
        std::vector<Photon> m_photonMap;
        d_type::Buint m_storedPhotons;
        d_type::Buint m_maxPhotons;
        RayTracer m_rt;
};

#endif // PHOTONMAP_H
