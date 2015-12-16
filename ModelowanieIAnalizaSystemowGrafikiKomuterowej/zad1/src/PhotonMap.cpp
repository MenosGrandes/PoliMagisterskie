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
    m_rt=RayTracer(rayTr);
    Vector3Bf direction;
    const PointLight * light = static_cast<PointLight*>(rayTr.getLights().at(0));
    while(m_photonMap.size() < m_maxPhotons)
    {
        do
        {
            direction = Vector3Bf(
                            ((rand()%10000 -5000.0)/5000.0),
                            ((rand()%10000 -5000.0)/5000.0),
                            ((rand()%10000 -5000.0)/5000.0)
                        );
        }
        while(direction.lengthSquared()>1);
//        std::cout<<direction<<"\n";
        Photon p = Photon();
        p.m_position=light->m_location; // pozycja fotonu == pozycja swiatla

        p.m_power=light->m_colour*light->m_intensittivity ;
//        std::cout<<p.m_power<<"\n";
        p.m_direction=direction;// kierunek fotonu == kierunek wylosowany
        tracePhoton(p);
//        if(m_photonMap.size()!=0)
//        {
//            std::cout<<m_photonMap.size()<<"\n";
//        }
//std::cout<<m_photonMap.size()<<"\n";
    }
    for(int i=0; i<m_photonMap.size(); i++)
    {
        m_photonMap[i].m_power= m_photonMap[i].m_power/m_photonMap.size();
//                std::cout<<m_photonMap[i].m_power<<"\n";
//std::cout<<m_photonMap[i].m_position<<"\n";

    }
//std::sort(m_photonMap.begin(),m_photonMap.end(),photonComp());
    std::cout<<"TRACE PHOTONS DONE\n";
//dopoki mapafotonowa nie pelna,    light->m_intensittivity=1000;

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
void PhotonMap::tracePhoton(Photon p)
{

//std::cout<<"\tTrace Photon\n";
//    std::cout<<m_photonMap.size()<<"\n";
    Vector3Bf direction;
//    std::cout<<m_photonMap.size()<<"\n";
    int maxReflextion = 4;
    int reflection=0;
    bool addedPhoton=false;
    // Dopoki foton nie zostal zaabsorbowany albo nie odbil sie maksymalna ilosc razy rob.
    while(maxReflextion<reflection || addedPhoton==false)
    {
//        std::cout<<addedPhoton<<"       "<<reflection<<"       \n";
//std::cout<<"reflection "<<reflection<<"\n";
//wyslij foton z pozycji swiatla do pozycji wylosowanek
        Ray photonRay = Ray(p.m_position,p.m_direction,DIRECTION);

//        std::cout<<reflection<<"\n";
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
            d_type::Buint probability = rand() %100+1;

            switch(info.m_material->m_type)
            {

            case MATERIAL_TYPE::PHONG :
            {
//                std::cout<<"PHONG HIT";
                const PhongMaterial * phong = static_cast<PhongMaterial*>(info.m_material);
                //absorb
                if(probability<50)
                {


//                    std::cout<<" absorb\n";

                    p.m_position=info.m_hitPoint;

                    m_photonMap.push_back(p);
                    addedPhoton=true;
//                    std::cout<<"added";
                    break;
                }//reflect
                else
                {

//                std::cout<<" reflect\n";


//    double f = (double)rand() / RAND_MAX;
                    do
                    {
                        direction = Vector3Bf(
                                        ((rand()%10000 -5000.0)/5000.0),
                                        ((rand()%10000 -5000.0)/5000.0),
                                        ((rand()%10000 -5000.0)/5000.0)
                                    );
                    }
                    while(direction.lengthSquared()>1);
//std::cout<<direction<<"\n";

                    p.m_direction=direction;
                    p.m_position=info.m_hitPoint;
                    reflection++;
                    m_photonMap.push_back(p);
//kolor sie zle liczy bo jak jest 0.33333 to wychodzi ze 0.3333 * 100= 300
                    const d_type::Bfloat colourAVG=phong->m_diffuse->m_cd.getAVG();
//                std::cout<<phong->m_diffuse->m_cd<<"\n";
                    p.m_power=Colour(
                                  (p.m_power.r*phong->m_diffuse->m_cd.r)/colourAVG,
                                  (p.m_power.g*phong->m_diffuse->m_cd.g)/colourAVG,
                                  (p.m_power.b*phong->m_diffuse->m_cd.b)/colourAVG
                              );
//            std::cout<<p.m_power<<"\n";
                }
                break;
            }
            case MATERIAL_TYPE::DIELECTRIC :

                do
                {
                    direction = Vector3Bf(
                                    ((rand()%10000 -5000.0)/5000.0),
                                    ((rand()%10000 -5000.0)/5000.0),
                                    ((rand()%10000 -5000.0)/5000.0)
                                );
                }
                while(direction.lengthSquared()>1);
//std::cout<<direction<<"\n";

                p.m_direction=direction;
                p.m_position=info.m_hitPoint;
                reflection++;
                break;


            case MATERIAL_TYPE::REFLECTIVE :
                do
                {
                    direction = Vector3Bf(
                                    ((rand()%10000 -5000.0)/5000.0),
                                    ((rand()%10000 -5000.0)/5000.0),
                                    ((rand()%10000 -5000.0)/5000.0)
                                );
                }
                while(direction.lengthSquared()>1);
//std::cout<<direction<<"\n";

                p.m_direction=direction;
                p.m_position=info.m_hitPoint;
                reflection++;
                break;
            case MATERIAL_TYPE::TRANSPARENT :
                do
                {
                    direction = Vector3Bf(
                                    ((rand()%10000 -5000.0)/5000.0),
                                    ((rand()%10000 -5000.0)/5000.0),
                                    ((rand()%10000 -5000.0)/5000.0)
                                );
                }
                while(direction.lengthSquared()>1);
//std::cout<<direction<<"\n";

                p.m_direction=direction;
                p.m_position=info.m_hitPoint;
                reflection++;
                break;

            }

        }
        else
        {
//            std::cout<<"NO HIT\n";
            break;
        }

    }


}
std::vector<Photon> PhotonMap::getNearestPhotons(const Vector3Bf& centerOfSphere, const d_type::Buint howMuchPhotons, const d_type::Bfloat radius) const
{
    std::vector<Photon> v_tmp;
    const d_type::Bsize photonSize = m_photonMap.size();
    for(int i=0; i<photonSize; i++)
    {
        if(v_tmp.size()<=howMuchPhotons)
        {
//            const Vector3Bf  distance = centerOfSphere - m_photonMap[i].m_position;
            const d_type::Bfloat fDist= Vector3Bf::distance(centerOfSphere,m_photonMap[i].m_position);
            if(fDist < radius*radius)
            {
                v_tmp.push_back(m_photonMap[i]);

            }
        }
    }
//    if(v_tmp.size()>0){
//    std::cout<<v_tmp.size()<<" size\n";
//    }
    return v_tmp;
}
Colour PhotonMap::radiance(const Vector3Bf& hitPoint, const Vector3Bf& normalInHitPoint, const Vector3Bf& directionToObserver)
{
    const std::vector<Photon> nearestPhotons = getNearestPhotons(hitPoint,1000,0.3f);
    Colour E= Colour(0,0,0);

    if(nearestPhotons.size()>0)
    {
        //find distance to the farthest Photon from nearestPhotons
        d_type::Bfloat distanceToFarthestPhoton=0.0f;
        for(int i=0; i<nearestPhotons.size(); i++)
        {
            const d_type::Bfloat tmp_distance=Vector3Bf::distance(nearestPhotons[i].m_position,hitPoint);
//        std::cout<<tmp_distance<<"\n";
            if(tmp_distance>distanceToFarthestPhoton)
            {
                distanceToFarthestPhoton=tmp_distance;
            }
        }
//
//std::cout<<"!@!@!@!@!@!@@!\n";
//    std::cout<<distanceToFarthestPhoton<<"\n";

        for(int i=0; i<nearestPhotons.size(); i++)
        {
            E+=nearestPhotons[i].m_power;
//        std::cout<<nearestPhotons[i].m_power<<"\n";
        }
        //std::cout<<E<<" BEFORE\n";
        E=(E/(M_PI * (distanceToFarthestPhoton*distanceToFarthestPhoton)));
        //  std::cout<<E<<" AFTER\n";
//    std::cout<<"POWER :"<<E<<"\n";

    }
    return  E;

}
void PhotonMap::mapPhotons()
{
    Ray ray;

    Colour finalColour=Colour::Black;


    for(Bint x=0; x<m_rt.m_renderTanger->getSize().x; x++)
    {
        for(Bint y=0; y<m_rt.m_renderTanger->getSize().y; y++)
        {
            finalColour=Colour::Black;


//            for(d_type::Bint i=0; i<simple_count; i++)
//            {
//                const Vector2Bf sample = m_rt.m_sampler->single();
            Vector2Bf picCoord(
                ((x+0.5f) / (d_type::Bfloat)m_rt.m_renderTanger->getSize().x)*2.f -1.f,
                ((y+0.5f) / (d_type::Bfloat)m_rt.m_renderTanger->getSize().y)*2.f -1.f
            );

            ray=m_rt.m_camera->recalculateRay(picCoord);




            d_type::Bfloat minDistance=std::numeric_limits<d_type::Bfloat>::max();
            d_type::Bfloat hitDistance=0.0f;
            Vector3Bf localHitPoint=Vector3Bf(0,0,0);
            Vector3Bf normal=Vector3Bf(0,0,0);

            Info info(Vector3Bf(0,0,0),Vector3Bf(0,0,0),false,(&m_rt));



            for(d_type::Bsize i=0; i<m_rt.m_objectVector.size(); i++)
            {
                if(m_rt.m_objectVector[i]->intersect(ray,hitDistance,info) && hitDistance< minDistance)
                {
                    info.m_hit=true;
                    normal=info.m_normal;
                    minDistance=hitDistance;
                    info.m_hitPoint=ray.getOrigin()+ray.getDirection()*minDistance;
                    localHitPoint=info.m_localHitPoint;
                    info.m_material=m_rt.m_objectVector[i]->getMaterial();
                }


            }
            if(info.m_hit)
            {
                info.m_t=minDistance;
                info.m_normal=normal;
                info.m_localHitPoint=localHitPoint;

                switch (info.m_material->m_type )
                {

                case MATERIAL_TYPE::PHONG :
                    finalColour+=radiance(info.m_hitPoint,Vector3Bf::Up,Vector3Bf::Up); //shadeRay(ray);///m_sampler->getSampleCount();

                    break;

//                default :
//
//                    finalColour=Colour::Black;
//                    break;
                }

            }

            //sprawdz czy trafiles cos rayem z kamery
            // sprawdz tym obiektu, jezeli nie dyfuzyjny zwroc czarny a jezeli dyfuzyjny





            m_rt.m_renderTanger->setPixel(Colour::clampColour(finalColour),x,y);

        }



        std::cout<<(d_type::Bfloat)((x*m_rt.m_renderTanger->getSize().x + m_rt.m_renderTanger->getSize().y )*100.0f)/(m_rt.m_renderTanger->getSizePixels())<<"\n";

    }
}

//przesledz fotony
//potraktuj foton jak promien, sprawdz czy w cos trafilo
// jezeli w cos trafilo i jest to phong to losuj czy ma odbic, czy absorbuje
