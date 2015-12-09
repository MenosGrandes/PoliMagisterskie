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
        if(m_photonMap.size()%(maxPhotons/100)==0)
        {
            std::cout<<m_photonMap.size()<<"\n";
        }
    }
    for(int i=0; i<m_photonMap.size(); i++)
    {
        m_photonMap[i].m_power= m_photonMap[i].m_power*(1/m_photonMap.size());
    }


//dopoki mapafotonowa nie pelna,
    //losuj pozycje z -1 do 1
    //dpoki x*x + y*y + z*z <1
//ustaw kierunek na x,y,z
//pozycja fotonu = pozycja swiatla
//poczatkowa energia swiatla = color swiatla * intensywnosc swiatla
//przesledz fotony



}
/**
Przesylam foton oraz pozycje swiatla, czyli miejsce z ktorego ma foton wyleciec
*/
void PhotonMap::tracePhoton(Photon p,  Vector3Bf direction)
{

//    std::cout<<m_photonMap.size()<<"\n";
    int maxReflextion = 4;
    int reflection=0;
    bool addedPhoton=false;
    // Dopoki foton nie zostal zaabsorbowany albo nie odbil sie maksymalna ilosc razy rob.
    while(maxReflextion<reflection || addedPhoton==false)
    {
//        std::cout<<addedPhoton<<"       "<<reflection<<"       \n";

//wyslij foton z pozycji swiatla do pozycji wylosowanek
        Ray photonRay = Ray(direction,p.m_position,DIRECTION);


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
                //absorb
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
                    p.m_lastPosition=p.m_position;
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
std::vector<Photon> PhotonMap::getNearestPhotons(const Vector3Bf& centerOfSphere, d_type::Buint howMuchPhotons, d_type::Bfloat radius) const
{

    std::vector<Photon> v_tmp;
    const d_type::Bsize photonSize = m_photonMap.size();
    for(int i=0; i<photonSize; i++)
    {
        if(v_tmp.size()<=howMuchPhotons)
        {
            const Vector3Bf  distance = centerOfSphere - m_photonMap[i].m_position;
            const d_type::Bfloat fDist= Vector3Bf::dotProduct(distance,distance);
            if(fDist < radius*radius)
            {
                v_tmp.push_back(m_photonMap[i]);

            }
        }
        else
        {
            break;
        }

    }
    return v_tmp;
}
Colour PhotonMap::radiance(const Vector3Bf& hitPoint, const Vector3Bf& normalInHitPoint, const Vector3Bf& directionToObserver)
{
    const std::vector<Photon> nearestPhotons = getNearestPhotons(hitPoint,100,0.10f);
    //find distance to the farthest Photon from nearestPhotons
    d_type::Bfloat distanceToFarthestPhoton=0;
    for(int i=0; i<nearestPhotons.size(); i++)
    {
        const d_type::Bfloat tmp_distance=Vector3Bf::distance(hitPoint,nearestPhotons[i].m_position);
        if(tmp_distance>distanceToFarthestPhoton)
        {
            distanceToFarthestPhoton=tmp_distance;
        }
    }


    Colour E= Colour::Black;
    for(int i=0; i<nearestPhotons.size(); i++)
    {
        E+=nearestPhotons[i].m_power;
    }


    return (E/(M_PI * (distanceToFarthestPhoton*distanceToFarthestPhoton)));
}
void PhotonMap::mapPhotons()
{
//        Colour finalColour=Colour::Black;
//    const d_type::Buint simple_count=m_rt.m_sampler->getSampleCount();
//
//    for(Bint x=0; x<m_rt.m_renderTanger->getSize().x; x++)
//    {
//        for(Bint y=0; y<m_rt.m_renderTanger->getSize().y; y++)
//        {
//            finalColour=Colour::Black;
//
//
//            for(d_type::Bint i=0; i<simple_count; i++)
//            {
//                const Vector2Bf sample = m_rt.m_sampler->single();
//                Vector2Bf picCoord(
//                    ((x+sample.x) / m_rt.m_renderTanger->getSize().x)*2 -1,
//                    ((y+sample.y) / m_rt.m_renderTanger->getSize().y)*2 -1
//                );
//
//                //ray=m_camera->recalculateRay(picCoord);
//
//                finalColour+=radiance(picCoord,Vector3Bf::Up,Vector3Bf::Up); //shadeRay(ray);///m_sampler->getSampleCount();
//
//            }
//            finalColour/=simple_count;
//            m_rt.m_renderTanger->setPixel(Colour::maxToOne(finalColour),x,y);
//
//        }
//
//
//
//
//    }
}

//przesledz fotony
//potraktuj foton jak promien, sprawdz czy w cos trafilo
// jezeli w cos trafilo i jest to phong to losuj czy ma odbic, czy absorbuje
