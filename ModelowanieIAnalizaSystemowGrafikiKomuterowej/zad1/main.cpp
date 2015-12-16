#include "Matrix4.h"
#include "Vertex2.h"
#include <cstdio>
#include <iostream>
#include <array>
#include <limits>
#include <chrono>
#include <ctime>
#include <vector>
#include <string>
#include <sstream>


#include "Sphere.h"
#include "Plane.h"
#include "OrtagonalCamera.h"
#include "PerspectiveCamera.h"

#include "RayTracer.h"
#include "RandomSampleGenerator.h"
#include "Sampler.h"
#include "SquareSampleDistributor.h"
#include "RegularSampleGenerator.h"
#include "DiskSampleDistributor.h"
#include "JitteredSampleGenerator.h"
#include "FileLoader.h"
#include "MultiJitteringSampleGenerator.h"
#include "PointLight.h"
#include "MatteMaterial.h"
#include "PhongMaterial.h"
#include "CheckCPU.h"
#include "DirectionalLight.h"
#include "Image.h"
#include "ImageTexture.h"
#include "TextureMatte.h"
#include "SpericalMapping.h"
#include "TexturePhong.h"
#include "RectMapping.h"
#include "Instance.h"
#include "ReflectiveMaterial.h"
#include "TransparentMaterial.h"
#include "DielectricMaterial.h"
#include "PhotonMap.h"







//#define FRESNEL
//#define RAY_TRACE
#define PHOTON_MAPPING1
#define PHOTON_MAPPING


int main(int argc, char **argv)
{

    srand(time(0));
    CheckCPU cpu;
    std::cout<<"There are "<<cpu.getNumberOfCores()<<" cores in CPU.\n";

float asd21=0.001;
std::cout<<asd21<<"\n";

std::cout.precision(17);
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    Vector2Bs img_size=Vector2Bs(100,100);


    RenderTarget *file = new RenderTarget(img_size);
    file->setCleanColour(Colour::Black);

    ICamera * orto=new OrtagonalCamera(Vector3Bf(0,0,0),0,Vector2Bf(10,10));
    // X Z Y
    ICamera *persp = new PerspectiveCamera(Vector3Bf(0, 0, 30),
                                           Vector3Bf(0, 0, 0),
                                           Vector3Bf::Up,
                                          1,
                                           Vector2Bf(1,1));


    Sampler * s= new Sampler(new SquareSampleDistributor(),new RandomSampleGenerator(),4,1);
    RayTracer *rt = new RayTracer(persp,file,s);
    rt->setDepth(0);

//Image * im=new Image("file.tga");
//file->drawToFile(im->getPixels());
//




Vector3Bf ligtPos=Vector3Bf(10,10,20);


PointLight* light_ptr1 = new PointLight;
	light_ptr1->m_location=ligtPos;
	light_ptr1->m_ls=(4.5);
	light_ptr1->setShadows(false);
	light_ptr1->m_intensittivity=10000;
	light_ptr1->m_colour=Colour::White;
	rt->addLight(light_ptr1);

//CORNELL BOX


        float ka 	= 0.25;
        float kd 	= 0.75;
        float ks 	= 0.1;
        float exp 	= 10.0f;

Plane * pl1= new Plane(Vector3Bf(0,-2,0),Vector3Bf(0,1,0));

        PhongMaterial* PhongMaterial_ptr = new PhongMaterial;
        PhongMaterial_ptr->setKa(ka);
        PhongMaterial_ptr->setKd(kd);
        PhongMaterial_ptr->setKs(ks);
        PhongMaterial_ptr->setExponent(exp);
        PhongMaterial_ptr->setCd(Colour::Red);

pl1->setMaterial(PhongMaterial_ptr);
rt->addObject(pl1);


Plane * pl2= new Plane(Vector3Bf(0,20,0),Vector3Bf(0,1,0));

        PhongMaterial* PhongMaterial_ptr2 = new PhongMaterial;
        PhongMaterial_ptr2->setKa(ka);
        PhongMaterial_ptr2->setKd(kd);
        PhongMaterial_ptr2->setKs(ks);
        PhongMaterial_ptr2->setExponent(exp);
        PhongMaterial_ptr2->setCd(Colour::Green);


pl2->setMaterial(PhongMaterial_ptr2);
rt->addObject(pl2);


Plane * pl3= new Plane(Vector3Bf(-20,0,0),Vector3Bf(1,0,0));

        PhongMaterial* PhongMaterial_ptr3 = new PhongMaterial;
        PhongMaterial_ptr3->setKa(ka);
        PhongMaterial_ptr3->setKd(kd);
        PhongMaterial_ptr3->setKs(ks);
        PhongMaterial_ptr3->setExponent(exp);
        PhongMaterial_ptr3->setCd(Colour::Blue);


pl3->setMaterial(PhongMaterial_ptr3);
rt->addObject(pl3);


Plane * pl4= new Plane(Vector3Bf(20,0,0),Vector3Bf(1,0,0));

        PhongMaterial* PhongMaterial_ptr4 = new PhongMaterial;
        PhongMaterial_ptr4->setKa(ka);
        PhongMaterial_ptr4->setKd(kd);
        PhongMaterial_ptr4->setKs(ks);
        PhongMaterial_ptr4->setExponent(exp);
        PhongMaterial_ptr4->setCd(Colour::White);


pl4->setMaterial(PhongMaterial_ptr4);
rt->addObject(pl4);


Plane * pl5= new Plane(Vector3Bf(-20,0,0),Vector3Bf(0,0,1));

        PhongMaterial* PhongMaterial_ptr5 = new PhongMaterial;
        PhongMaterial_ptr5->setKa(ka);
        PhongMaterial_ptr5->setKd(kd);
        PhongMaterial_ptr5->setKs(ks);
        PhongMaterial_ptr5->setExponent(exp);
        PhongMaterial_ptr5->setCd(Colour::Gray);


pl5->setMaterial(PhongMaterial_ptr5);
rt->addObject(pl5);

//	DielectricMaterial * glass= new DielectricMaterial();
//	glass->setKs(0.2);
//	glass->setExp(2000.0);
//	glass->setRefractionIN(1.5);
//	glass->setRefractionOUT(1.0);
//	glass->setCfIn(Colour::White);
//	glass->setCfOut(Colour::White);
////	glass->setKr(0.1);
//    glass->setCd(Colour::White);
//    glass->setCr(Colour::White);


//         spheres

        PhongMaterial* PhongMaterial_ptr1 = new PhongMaterial;
        PhongMaterial_ptr1->setKa(ka);
        PhongMaterial_ptr1->setKd(kd);
        PhongMaterial_ptr1->setKs(ks);
        PhongMaterial_ptr1->setExponent(exp);
        PhongMaterial_ptr1->setCd(Colour::Yellow);


//	Sphere * sp= new Sphere(ligtPos, 1.0);
//	sp->setMaterial(PhongMaterial_ptr1);
//	rt->addObject(sp);

	Sphere * sp2= new Sphere(Vector3Bf(5,5,15), 1.0);
	sp2->setMaterial(PhongMaterial_ptr1);
	rt->addObject(sp2);

		Sphere * sp3= new Sphere(Vector3Bf(-5,5,10), 2.0);
	sp3->setMaterial(PhongMaterial_ptr1);
	rt->addObject(sp3);

//	Sphere * sp3= new Sphere(Vector3Bf(-4.0, 4.5, 3.0), 3.0);
//	sp3->setMaterial(PhongMaterial_ptr1);
//	rt->addObject(sp3);
//
//	Sphere * sp4= new Sphere(Vector3Bf(10.0, 1.5, 0.0), 1.0);
//	sp4->setMaterial(PhongMaterial_ptr1);
//	rt->addObject(sp4);
//
//	Sphere * sp5= new Sphere(Vector3Bf(0.0, 4.5, 0.0), 0.4);
//	sp5->setMaterial(PhongMaterial_ptr1);
//	rt->addObject(sp5);


//ReflectiveMaterial*	reflective_ptr = new ReflectiveMaterial;
//	reflective_ptr->setKa(0.3);
//	reflective_ptr->setKd(0.3);
//	reflective_ptr->setCd(Colour::Red);
//	reflective_ptr->setKs(0.2);
//	reflective_ptr->setExponent(2000.0);
//	reflective_ptr->setKr(0.25);
//	reflective_ptr->setCr(Colour::White);

//	Sphere* sphere_ptr2 = new Sphere(Vector3Bf(4, 4, -6), 3);
//	rt->addObject(sphere_ptr2);

//Plane * p = new Plane(Vector3Bf(0,-2,0),Vector3Bf(0,1,0));
//TextureMatte * mM = new TextureMatte();
//mM->setCd(new ImageTexture(new Image("textures/plane.tga"),new RectMapping(p,Vector2Bf(0.001,0.001))));
//mM->setKa(0.4f);
//mM->setKd(0.5f);
//p->setMaterial(mM);
//rt->addObject(p);

//rt->setDepth(2);

#ifdef RAY_TRACE
rt->rayTrace();
#endif // RAY_TRACE
#ifdef PHOTON_MAPPING
PhotonMap * photonMap = new PhotonMap(100000,*rt);
photonMap->mapPhotons();
#endif
//Image* img=new Image("foto2.tga");
//file->drawToFile(img->getPixels(),img->getHres(),img->getVres());


    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
    file->drawToFile("foto.tga");
    delete file;
    d_type::Bint a432;
    std::cin>>a432;
    return 0;
}



