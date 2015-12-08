#ifndef PHOTONMAPPING_H
#define PHOTONMAPPING_H
#include "PhotonMap.h"
#include "ILight.h"
#include <vector>
class PhotonMapping
{
    public:
        PhotonMapping();
        virtual ~PhotonMapping();
        void constructMap() ;
    protected:
    private:
        d_type::Buint maxPhotonPerLight;
        PhotonMap *m_globalMap;
        PhotonMap * m_causticMap;
        void emitPhotons();
};

#endif // PHOTONMAPPING_H
