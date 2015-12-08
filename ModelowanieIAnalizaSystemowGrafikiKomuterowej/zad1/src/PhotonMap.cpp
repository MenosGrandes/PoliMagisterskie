#include "PhotonMap.h"

PhotonMap::PhotonMap():m_rt()
{
    //ctor
}

PhotonMap::~PhotonMap()
{
    //dtor
}
PhotonMap::PhotonMap(int maxPhotons,RayTracer rayTr)
{
    m_maxPhotons=maxPhotons;
    m_rt=rayTr;
    Vector3Bf position;
    const PointLight * light = static_cast<PointLight*>(rayTr.getLights().at(0));
    while(m_photonMap.size() < m_maxPhotons)
    {
        do
        {
            position = Vector3Bf(
                           ((rand()%10000 -5000.0)/5000.0),
                           ((rand()%10000 -5000.0)/5000.0),
                           ((rand()%10000 -5000.0)/5000.0)
                       );
        }
        while(position.lengthSquared()<1);
//        std::cout<<position<<"\n";
        Photon p = Photon();
        p.m_position=position;

        p.m_power=light->m_intensittivity *light->m_colour;
        tracePhoton(p,light->m_location);
//        std::cout<<m_photonMap.size()<<" size\n";
    }


//dopoki mapafotonowa nie pelna,
    //losuj pozycje z -1 do 1
    //dpoki x*x + y*y + z*z <1
//ustaw kierunek na x,y,z
//pozycja fotonu = pozycja swiatla
//poczatkowa energia swiatla = color swiatla * intensywnosc swiatla
//przesledz fotony



}

void PhotonMap::tracePhoton(Photon p,  Vector3Bf direction)
{

    std::cout<<m_photonMap.size()<<"\n";
    int maxReflextion = 4;
    int reflection=0;
    bool addedPhoton=false;
    while(maxReflextion<reflection || addedPhoton==false)
    {
        std::cout<<addedPhoton<<"       "<<reflection<<"       \n";

        Ray photonRay = Ray(p.m_position,direction,DIRECTION);
//Vector3Bf origin,Vector3Bf vec,bool destORDir


        d_type::Bfloat minDistance=std::numeric_limits<d_type::Bfloat>::max();
        d_type::Bfloat hitDistance=0.0f;
        Vector3Bf localHitPoint=Vector3Bf(0,0,0);
        Vector3Bf normal=Vector3Bf(0,0,0);

        Info info(Vector3Bf(0,0,0),Vector3Bf(0,0,0),false,(&m_rt));



        for(d_type::Bsize i=0; i<m_rt.m_objectVector.size(); i++)
        {
            if(m_rt.m_objectVector[i]->intersect(photonRay,hitDistance,info) && hitDistance< minDistance)
            {
                info.m_hit=true;
                normal=info.m_normal;
                minDistance=hitDistance;
                info.m_hitPoint=photonRay.getOrigin()+photonRay.getDirection()*minDistance;
                localHitPoint=info.m_localHitPoint;
                info.m_material=m_rt.m_objectVector[i]->getMaterial();
            }


        }
        if(info.m_hit)
        {
            info.m_t=minDistance;
            info.m_normal=normal;
            info.m_localHitPoint=localHitPoint;
            d_type::Buint probability = rand() %1000;

            switch(info.m_material->m_type)
            {

            case MATERIAL_TYPE::PHONG :
                const PhongMaterial * phong = static_cast<PhongMaterial*>(info.m_material);

                if(probability%2==0)
                {
                    const d_type::Bfloat colourAVG=phong->m_diffuse->m_cd.getAVG();

                    p.m_power=Colour(
                                  p.m_power.r*phong->m_diffuse->m_cd.r/colourAVG,
                                  p.m_power.g*phong->m_diffuse->m_cd.g/colourAVG,
                                  p.m_power.b*phong->m_diffuse->m_cd.b/colourAVG
                              );
                    p.m_position=info.m_hitPoint;

                    m_photonMap.push_back(p);
                    addedPhoton=true;
                    break;
                }//reflect
                else
                {


                    do
                    {
                        direction = Vector3Bf(
                                        ((rand()%10000 -5000.0)/5000.0),
                                        ((rand()%10000 -5000.0)/5000.0),
                                        ((rand()%10000 -5000.0)/5000.0)
                                    );
                    }
                    while(direction.lengthSquared()<1);


                    const d_type::Bfloat colourAVG=phong->m_diffuse->m_cd.getAVG();

                    p.m_power=Colour(
                                  p.m_power.r*phong->m_diffuse->m_cd.r/colourAVG,
                                  p.m_power.g*phong->m_diffuse->m_cd.g/colourAVG,
                                  p.m_power.b*phong->m_diffuse->m_cd.b/colourAVG
                              );

                    p.m_position=info.m_hitPoint;
                    reflection++;
                }
                break;
//            case MATERIAL_TYPE::DIELECTRIC :
//                break;
//            case MATERIAL_TYPE::MATTE :
//                //absorb
//                if(probability%2==0)
//                {
//                    p.m_power=info.m_material->shade(info);
//                    m_photonMap.push_back(p);
//                    addedPhoton=true;
//                    break;
//                }//reflect
//                else
//                {
//                    const MatteMaterial * matte = static_cast<MatteMaterial*>(info.m_material);
//
//
//                    do
//                    {
//                        direction = Vector3Bf(
//                                        ((rand()%10000 -5000.0)/5000.0),
//                                        ((rand()%10000 -5000.0)/5000.0),
//                                        ((rand()%10000 -5000.0)/5000.0)
//                                    );
//                    }
//                    while(direction.lengthSquared()<1);
//                    reflection++;
//
//                    const d_type::Bfloat colourAVG=matte->m_diffuse->m_cd.getAVG();
//
//                    p.m_power=Colour(
//                                  p.m_power.r*matte->m_diffuse->m_cd.r/colourAVG,
//                                  p.m_power.g*matte->m_diffuse->m_cd.g/colourAVG,
//                                  p.m_power.b*matte->m_diffuse->m_cd.b/colourAVG
//                              );
//
//                    p.m_position=info.m_hitPoint;
//                }
//                break;
//            case MATERIAL_TYPE::REFLECTIVE :
////
////
////                direction= Vector3Bf::reflect(info.m_normal,direction);
//////                direction = 2*(Vector3Bf::dotProduct(info.m_normal,direction)*info.m_normal - direction;
////                reflection++;
////                p.m_power=info.m_material->shade(info);
////                p.m_position=info.m_hitPoint;
//                break;
//            case MATERIAL_TYPE::TRANSPARENT :
//                break;
//            case MATERIAL_TYPE::TEXTURE_MATT :
////
////               //absorb
////                if(probability%2==0)
////                {
////                    p.m_power=info.m_material->shade(info);
////                    m_photonMap.push_back(p);
////                    addedPhoton=true;
////                    break;
////                }//reflect
////                else
////                {
////                    const TextureMatte * matte = static_cast<TextureMatte*>(info.m_material);
////
////
////                    do
////                    {
////                        direction = Vector3Bf(
////                                        ((rand()%10000 -5000.0)/5000.0),
////                                        ((rand()%10000 -5000.0)/5000.0),
////                                        ((rand()%10000 -5000.0)/5000.0)
////                                    );
////                    }
////                    while(direction.lengthSquared()<1);
////                    reflection++;
////
////                    const d_type::Bfloat colourAVG=matte.m_diffuse   .m_diffuse->m_cd.getAVG();
////
////                    p.m_power=Colour(
////                                  p.m_power.r*matte.m_diffuse->m_cd.r/colourAVG,
////                                  p.m_power.g*matte.m_diffuse->m_cd.g/colourAVG,
////                                  p.m_power.b*matte.m_diffuse->m_cd.b/colourAVG
////                              );
////
////                    p.m_position=info.m_hitPoint;
////
////
////                break;
////            case MATERIAL_TYPE::TEXTURE_PHONG :
////                //absorb
////                if(probability%2==0)
////                {
////                    p.m_power=info.m_material->shade(info);
////                    m_photonMap.push_back(p);
////                    addedPhoton=true;
////                    break;
////                }//reflect
////                else
////                {
////                    do
////                    {
////                        direction = Vector3Bf(
////                                        ((rand()%10000 -5000.0)/5000.0),
////                                        ((rand()%10000 -5000.0)/5000.0),
////                                        ((rand()%10000 -5000.0)/5000.0)
////                                    );
////                    }
////                    while(direction.lengthSquared()<1);
////                    reflection++;
////                }
////
////
////
////
//                break;


            }

        }
        else
        {
            break;
        }

    }


}

//przesledz fotony
//potraktuj foton jak promien, sprawdz czy w cos trafilo
// jezeli w cos trafilo i jest to phong to losuj czy ma odbic, czy absorbuje
