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







#define PHOTON_MAPPING





int main(int argc, char **argv)
{

    srand(time(0));
    CheckCPU cpu;
    std::cout<<"There are "<<cpu.getNumberOfCores()<<" cores in CPU.\n";



    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    Vector2Bs img_size=Vector2Bs(500,500);


    RenderTarget *file = new RenderTarget(img_size);
    file->setCleanColour(Colour::Black);

    ICamera * orto=new OrtagonalCamera(Vector3Bf(0,0,0),0,Vector2Bf(10,10));
    // X Z Y
    ICamera *persp = new PerspectiveCamera(Vector3Bf(-1, 5.5, 160),
                                           Vector3Bf(1, 4, 0),
                                           Vector3Bf::Up,
                                          10,
                                           Vector2Bf(1,1));


    Sampler * s= new Sampler(new SquareSampleDistributor(),new RandomSampleGenerator(),4,1);
    RayTracer *rt = new RayTracer(persp,file,s);
    rt->setDepth(0);

//Image * im=new Image("file.tga");
//file->drawToFile(im->getPixels());
//



//#define FRESNEL
#ifdef CHAPTER15
    {
        DirectionalLight * dirLight=new DirectionalLight();
        Vector3Bf direction = Vector3Bf(100,100,200);
        Vector3Bf::normalize(direction);
        dirLight->m_direction=direction;
        dirLight->m_colour=Colour::White;
        dirLight->m_ls=3.0f;
        dirLight->setShadows(false);
        rt->addLight(dirLight);



        // four spheres centered on the x axis


        float a = 0.75;  // scaling factor for yellow, orange, and light green

        Colour yellow(a * 1, a * 1, 0);								// yellow
        Colour brown(0.71, 0.40, 0.16);								// brown
        Colour dark_green(0.0, 0.41, 0.41);							// dark_green
        Colour orange(a * 1, a * 0.75, 0);							// orange
        Colour green(0, 0.6, 0.3);									// green
        Colour light_green(a * 0.65, a * 1, a * 0.30);				// light green
        Colour dark_yellow(0.61, 0.61, 0);							// dark yellow
        Colour light_purple(0.65, 0.3, 1);							// light purple
        Colour dark_purple(0.5, 0, 1);								// dark purple


        // PhongMaterial materials' reflection coefficients

        float ka 	= 0.25;
        float kd 	= 0.75;
        float ks 	= 0.1;
        float exp 	= 10.0f;


        // spheres

        PhongMaterial* PhongMaterial_ptr1 = new PhongMaterial;
        PhongMaterial_ptr1->setKa(ka);
        PhongMaterial_ptr1->setKd(kd);
        PhongMaterial_ptr1->setKs(ks);
        PhongMaterial_ptr1->setExponent(exp);
        PhongMaterial_ptr1->setCd(yellow);

        Sphere*	sphere_ptr1 = new Sphere(Vector3Bf(5, 3, 0), 30);
        sphere_ptr1->setMaterial(PhongMaterial_ptr1);	   							// yellow
        rt->addObject(sphere_ptr1);


        PhongMaterial* PhongMaterial_ptr2 = new PhongMaterial;
        PhongMaterial_ptr2->setKa(ka);
        PhongMaterial_ptr2->setKd(kd);
        PhongMaterial_ptr2->setKs(ks);
        PhongMaterial_ptr2->setExponent(exp);
        PhongMaterial_ptr2->setCd(brown);

        Sphere*	sphere_ptr2 = new Sphere(Vector3Bf(45, -7, -60), 20);
        sphere_ptr2->setMaterial(PhongMaterial_ptr2);								// brown
        rt->addObject(sphere_ptr2);


        PhongMaterial* PhongMaterial_ptr3 = new PhongMaterial;
        PhongMaterial_ptr3->setKa(ka);
        PhongMaterial_ptr3->setKd(kd);
        PhongMaterial_ptr3->setKs(ks);
        PhongMaterial_ptr3->setExponent(exp);
        PhongMaterial_ptr3->setCd(dark_green);

        Sphere*	sphere_ptr3 = new Sphere(Vector3Bf(40, 43, -100), 17);
        sphere_ptr3->setMaterial(PhongMaterial_ptr3);								// dark green
        rt->addObject(sphere_ptr3);


        PhongMaterial* PhongMaterial_ptr4 = new PhongMaterial;
        PhongMaterial_ptr4->setKa(ka);
        PhongMaterial_ptr4->setKd(kd);
        PhongMaterial_ptr4->setKs(ks);
        PhongMaterial_ptr4->setExponent(exp);
        PhongMaterial_ptr4->setCd(orange);

        Sphere*	sphere_ptr4 = new Sphere(Vector3Bf(-20, 28, -15), 20);
        sphere_ptr4->setMaterial(PhongMaterial_ptr4);								// orange
        rt->addObject(sphere_ptr4);


        PhongMaterial* PhongMaterial_ptr5 = new PhongMaterial;
        PhongMaterial_ptr5->setKa(ka);
        PhongMaterial_ptr5->setKd(kd);
        PhongMaterial_ptr5->setKs(ks);
        PhongMaterial_ptr5->setExponent(exp);
        PhongMaterial_ptr5->setCd(green);

        Sphere*	sphere_ptr5 = new Sphere(Vector3Bf(-25, -7, -35), 27);
        sphere_ptr5->setMaterial(PhongMaterial_ptr5);								// green
        rt->addObject(sphere_ptr5);


        PhongMaterial* PhongMaterial_ptr6 = new PhongMaterial;
        PhongMaterial_ptr6->setKa(ka);
        PhongMaterial_ptr6->setKd(kd);
        PhongMaterial_ptr6->setKs(ks);
        PhongMaterial_ptr6->setExponent(exp);
        PhongMaterial_ptr6->setCd(light_green);

        Sphere*	sphere_ptr6 = new Sphere(Vector3Bf(20, -27, -35), 25);
        sphere_ptr6->setMaterial(PhongMaterial_ptr6);								// light green
        rt->addObject(sphere_ptr6);


        PhongMaterial* PhongMaterial_ptr7 = new PhongMaterial;
        PhongMaterial_ptr7->setKa(ka);
        PhongMaterial_ptr7->setKd(kd);
        PhongMaterial_ptr7->setKs(ks);
        PhongMaterial_ptr7->setExponent(exp);
        PhongMaterial_ptr7->setCd(green);

        Sphere*	sphere_ptr7 = new Sphere(Vector3Bf(35, 18, -35), 22);
        sphere_ptr7->setMaterial(PhongMaterial_ptr7);   							// green
        rt->addObject(sphere_ptr7);


        PhongMaterial* PhongMaterial_ptr8 = new PhongMaterial;
        PhongMaterial_ptr8->setKa(ka);
        PhongMaterial_ptr8->setKd(kd);
        PhongMaterial_ptr8->setKs(ks);
        PhongMaterial_ptr8->setExponent(exp);
        PhongMaterial_ptr8->setCd(brown);

        Sphere*	sphere_ptr8 = new Sphere(Vector3Bf(-57, -17, -50), 15);
        sphere_ptr8->setMaterial(PhongMaterial_ptr8);								// brown
        rt->addObject(sphere_ptr8);


        PhongMaterial* PhongMaterial_ptr9 = new PhongMaterial;
        PhongMaterial_ptr9->setKa(ka);
        PhongMaterial_ptr9->setKd(kd);
        PhongMaterial_ptr9->setKs(ks);
        PhongMaterial_ptr9->setExponent(exp);
        PhongMaterial_ptr9->setCd(light_green);

        Sphere*	sphere_ptr9 = new Sphere(Vector3Bf(-47, 16, -80), 23);
        sphere_ptr9->setMaterial(PhongMaterial_ptr9);								// light green
        rt->addObject(sphere_ptr9);


        PhongMaterial* PhongMaterial_ptr10 = new PhongMaterial;
        PhongMaterial_ptr10->setKa(ka);
        PhongMaterial_ptr10->setKd(kd);
        PhongMaterial_ptr10->setKs(ks);
        PhongMaterial_ptr10->setExponent(exp);
        PhongMaterial_ptr10->setCd(dark_green);

        Sphere*	sphere_ptr10 = new Sphere(Vector3Bf(-15, -32, -60), 22);
        sphere_ptr10->setMaterial(PhongMaterial_ptr10);     						// dark green
        rt->addObject(sphere_ptr10);


        PhongMaterial* PhongMaterial_ptr11 = new PhongMaterial;
        PhongMaterial_ptr11->setKa(ka);
        PhongMaterial_ptr11->setKd(kd);
        PhongMaterial_ptr11->setKs(ks);
        PhongMaterial_ptr11->setExponent(exp);
        PhongMaterial_ptr11->setCd(dark_yellow);

        Sphere*	sphere_ptr11 = new Sphere(Vector3Bf(-35, -37, -80), 22);
        sphere_ptr11->setMaterial(PhongMaterial_ptr11);							// dark yellow
        rt->addObject(sphere_ptr11);


        PhongMaterial* PhongMaterial_ptr12 = new PhongMaterial;
        PhongMaterial_ptr12->setKa(ka);
        PhongMaterial_ptr12->setKd(kd);
        PhongMaterial_ptr12->setKs(ks);
        PhongMaterial_ptr12->setExponent(exp);
        PhongMaterial_ptr12->setCd(dark_yellow);

        Sphere*	sphere_ptr12 = new Sphere(Vector3Bf(10, 43, -80), 22);
        sphere_ptr12->setMaterial(PhongMaterial_ptr12);							// dark yellow
        rt->addObject(sphere_ptr12);


        PhongMaterial* PhongMaterial_ptr13 = new PhongMaterial;
        PhongMaterial_ptr13->setKa(ka);
        PhongMaterial_ptr13->setKd(kd);
        PhongMaterial_ptr13->setKs(ks);
        PhongMaterial_ptr13->setExponent(exp);
        PhongMaterial_ptr13->setCd(dark_yellow);

        Sphere*	sphere_ptr13 = new Sphere(Vector3Bf(30, -7, -80), 10);
        sphere_ptr13->setMaterial(PhongMaterial_ptr13);
        rt->addObject(sphere_ptr13);											// dark yellow (hidden)


        PhongMaterial* PhongMaterial_ptr14 = new PhongMaterial;
        PhongMaterial_ptr14->setKa(ka);
        PhongMaterial_ptr14->setKd(kd);
        PhongMaterial_ptr14->setKs(ks);
        PhongMaterial_ptr14->setExponent(exp);
        PhongMaterial_ptr14->setCd(dark_green);

        Sphere*	sphere_ptr14 = new Sphere(Vector3Bf(-40, 48, -110), 18);
        sphere_ptr14->setMaterial(PhongMaterial_ptr14); 							// dark green
        rt->addObject(sphere_ptr14);


        PhongMaterial* PhongMaterial_ptr15 = new PhongMaterial;
        PhongMaterial_ptr15->setKa(ka);
        PhongMaterial_ptr15->setKd(kd);
        PhongMaterial_ptr15->setKs(ks);
        PhongMaterial_ptr15->setExponent(exp);
        PhongMaterial_ptr15->setCd(brown);

        Sphere*	sphere_ptr15 = new Sphere(Vector3Bf(-10, 53, -120), 18);
        sphere_ptr15->setMaterial(PhongMaterial_ptr15); 							// brown
        rt->addObject(sphere_ptr15);


        PhongMaterial* PhongMaterial_ptr16 = new PhongMaterial;
        PhongMaterial_ptr16->setKa(ka);
        PhongMaterial_ptr16->setKd(kd);
        PhongMaterial_ptr16->setKs(ks);
        PhongMaterial_ptr16->setExponent(exp);
        PhongMaterial_ptr16->setCd(light_purple);

        Sphere*	sphere_ptr16 = new Sphere(Vector3Bf(-55, -52, -100), 10);
        sphere_ptr16->setMaterial(PhongMaterial_ptr16);							// light purple
        rt->addObject(sphere_ptr16);


        PhongMaterial* PhongMaterial_ptr17 = new PhongMaterial;
        PhongMaterial_ptr17->setKa(ka);
        PhongMaterial_ptr17->setKd(kd);
        PhongMaterial_ptr17->setKs(ks);
        PhongMaterial_ptr17->setExponent(exp);
        PhongMaterial_ptr17->setCd(brown);

        Sphere*	sphere_ptr17 = new Sphere(Vector3Bf(5, -52, -100), 15);
        sphere_ptr17->setMaterial(PhongMaterial_ptr17);							// browm
        rt->addObject(sphere_ptr17);


        PhongMaterial* PhongMaterial_ptr18 = new PhongMaterial;
        PhongMaterial_ptr18->setKa(ka);
        PhongMaterial_ptr18->setKd(kd);
        PhongMaterial_ptr18->setKs(ks);
        PhongMaterial_ptr18->setExponent(exp);
        PhongMaterial_ptr18->setCd(dark_purple);

        Sphere*	sphere_ptr18 = new Sphere(Vector3Bf(-20, -57, -120), 15);
        sphere_ptr18->setMaterial(PhongMaterial_ptr18);							// dark purple
        rt->addObject(sphere_ptr18);


        PhongMaterial* PhongMaterial_ptr19 = new PhongMaterial;
        PhongMaterial_ptr19->setKa(ka);
        PhongMaterial_ptr19->setKd(kd);
        PhongMaterial_ptr19->setKs(ks);
        PhongMaterial_ptr19->setExponent(exp);
        PhongMaterial_ptr19->setCd(dark_green);

        Sphere*	sphere_ptr19 = new Sphere(Vector3Bf(55, -27, -100), 17);
        sphere_ptr19->setMaterial(PhongMaterial_ptr19);							// dark green
        rt->addObject(sphere_ptr19);


        PhongMaterial* PhongMaterial_ptr20 = new PhongMaterial;
        PhongMaterial_ptr20->setKa(ka);
        PhongMaterial_ptr20->setKd(kd);
        PhongMaterial_ptr20->setKs(ks);
        PhongMaterial_ptr20->setExponent(exp);
        PhongMaterial_ptr20->setCd(brown);

        Sphere*	sphere_ptr20 = new Sphere(Vector3Bf(50, -47, -120), 15);
        sphere_ptr20->setMaterial(PhongMaterial_ptr20);							// browm
        rt->addObject(sphere_ptr20);


        PhongMaterial* PhongMaterial_ptr21 = new PhongMaterial;
        PhongMaterial_ptr21->setKa(ka);
        PhongMaterial_ptr21->setKd(kd);
        PhongMaterial_ptr21->setKs(ks);
        PhongMaterial_ptr21->setExponent(exp);
        PhongMaterial_ptr21->setCd(light_purple);

        Sphere*	sphere_ptr21 = new Sphere(Vector3Bf(70, -42, -150), 10);
        sphere_ptr21->setMaterial(PhongMaterial_ptr21);							// light purple
        rt->addObject(sphere_ptr21);


        PhongMaterial* PhongMaterial_ptr22 = new PhongMaterial;
        PhongMaterial_ptr22->setKa(ka);
        PhongMaterial_ptr22->setKd(kd);
        PhongMaterial_ptr22->setKs(ks);
        PhongMaterial_ptr22->setExponent(exp);
        PhongMaterial_ptr22->setCd(light_purple);

        Sphere*	sphere_ptr22 = new Sphere(Vector3Bf(5, 73, -130), 12);
        sphere_ptr22->setMaterial(PhongMaterial_ptr22);							// light purple
        rt->addObject(sphere_ptr22);


        PhongMaterial* PhongMaterial_ptr23 = new PhongMaterial;
        PhongMaterial_ptr23->setKa(ka);
        PhongMaterial_ptr23->setKd(kd);
        PhongMaterial_ptr23->setKs(ks);
        PhongMaterial_ptr23->setExponent(exp);
        PhongMaterial_ptr23->setCd(dark_purple);

        Sphere*	sphere_ptr23 = new Sphere(Vector3Bf(66, 21, -130), 13);
        sphere_ptr23->setMaterial(PhongMaterial_ptr23);							// dark purple
        rt->addObject(sphere_ptr23);


        PhongMaterial* PhongMaterial_ptr24 = new PhongMaterial;
        PhongMaterial_ptr24->setKa(ka);
        PhongMaterial_ptr24->setKd(kd);
        PhongMaterial_ptr24->setKs(ks);
        PhongMaterial_ptr24->setExponent(exp);
        PhongMaterial_ptr24->setCd(light_purple);

        Sphere*	sphere_ptr24 = new Sphere(Vector3Bf(72, -12, -140), 12);
        sphere_ptr24->setMaterial(PhongMaterial_ptr24);							// light purple
        rt->addObject(sphere_ptr24);


        PhongMaterial* PhongMaterial_ptr25 = new PhongMaterial;
        PhongMaterial_ptr25->setKa(ka);
        PhongMaterial_ptr25->setKd(kd);
        PhongMaterial_ptr25->setKs(ks);
        PhongMaterial_ptr25->setExponent(exp);
        PhongMaterial_ptr25->setCd(green);

        Sphere*	sphere_ptr25 = new Sphere(Vector3Bf(64, 5, -160), 11);
        sphere_ptr25->setMaterial(PhongMaterial_ptr25);					 		// green
        rt->addObject(sphere_ptr25);


        PhongMaterial* PhongMaterial_ptr26 = new PhongMaterial;
        PhongMaterial_ptr26->setKa(ka);
        PhongMaterial_ptr26->setKd(kd);
        PhongMaterial_ptr26->setKs(ks);
        PhongMaterial_ptr26->setExponent(exp);
        PhongMaterial_ptr26->setCd(light_purple);

        Sphere*	sphere_ptr26 = new Sphere(Vector3Bf(55, 38, -160), 12);
        sphere_ptr26->setMaterial(PhongMaterial_ptr26);							// light purple
        rt->addObject(sphere_ptr26);


        PhongMaterial* PhongMaterial_ptr27 = new PhongMaterial;
        PhongMaterial_ptr27->setKa(ka);
        PhongMaterial_ptr27->setKd(kd);
        PhongMaterial_ptr27->setKs(ks);
        PhongMaterial_ptr27->setExponent(exp);
        PhongMaterial_ptr27->setCd(light_purple);

        Sphere*	sphere_ptr27 = new Sphere(Vector3Bf(-73, -2, -160), 12);
        sphere_ptr27->setMaterial(PhongMaterial_ptr27);							// light purple
        rt->addObject(sphere_ptr27);


        PhongMaterial* PhongMaterial_ptr28 = new PhongMaterial;
        PhongMaterial_ptr28->setKa(ka);
        PhongMaterial_ptr28->setKd(kd);
        PhongMaterial_ptr28->setKs(ks);
        PhongMaterial_ptr28->setExponent(exp);
        PhongMaterial_ptr28->setCd(dark_purple);

        Sphere*	sphere_ptr28 = new Sphere(Vector3Bf(30, -62, -140), 15);
        sphere_ptr28->setMaterial(PhongMaterial_ptr28); 							// dark purple
        rt->addObject(sphere_ptr28);



        PhongMaterial* PhongMaterial_ptr29 = new PhongMaterial;
        PhongMaterial_ptr29->setKa(ka);
        PhongMaterial_ptr29->setKd(kd);
        PhongMaterial_ptr29->setKs(ks);
        PhongMaterial_ptr29->setExponent(exp);
        PhongMaterial_ptr29->setCd(dark_purple);

        Sphere*	sphere_ptr29 = new Sphere(Vector3Bf(25, 63, -140), 15);
        sphere_ptr29->setMaterial(PhongMaterial_ptr29);							// dark purple
        rt->addObject(sphere_ptr29);


        PhongMaterial* PhongMaterial_ptr30 = new PhongMaterial;
        PhongMaterial_ptr30->setKa(ka);
        PhongMaterial_ptr30->setKd(kd);
        PhongMaterial_ptr30->setKs(ks);
        PhongMaterial_ptr30->setExponent(exp);
        PhongMaterial_ptr30->setCd(dark_purple);

        Sphere*	sphere_ptr30 = new Sphere(Vector3Bf(-60, 46, -140), 15);
        sphere_ptr30->setMaterial(PhongMaterial_ptr30); 							// dark purple
        rt->addObject(sphere_ptr30);


        PhongMaterial* PhongMaterial_ptr31 = new PhongMaterial;
        PhongMaterial_ptr31->setKa(ka);
        PhongMaterial_ptr31->setKd(kd);
        PhongMaterial_ptr31->setKs(ks);
        PhongMaterial_ptr31->setExponent(exp);
        PhongMaterial_ptr31->setCd(light_purple);

        Sphere*	sphere_ptr31 = new Sphere(Vector3Bf(-30, 68, -130), 12);
        sphere_ptr31->setMaterial(PhongMaterial_ptr31); 							// light purple
        rt->addObject(sphere_ptr31);


        PhongMaterial* PhongMaterial_ptr32 = new PhongMaterial;
        PhongMaterial_ptr32->setKa(ka);
        PhongMaterial_ptr32->setKd(kd);
        PhongMaterial_ptr32->setKs(ks);
        PhongMaterial_ptr32->setExponent(exp);
        PhongMaterial_ptr32->setCd(green);

        Sphere*	sphere_ptr32 = new Sphere(Vector3Bf(58, 56, -180), 11);
        sphere_ptr32->setMaterial(PhongMaterial_ptr32);							//  green
        rt->addObject(sphere_ptr32);


        PhongMaterial* PhongMaterial_ptr33 = new PhongMaterial;
        PhongMaterial_ptr33->setKa(ka);
        PhongMaterial_ptr33->setKd(kd);
        PhongMaterial_ptr33->setKs(ks);
        PhongMaterial_ptr33->setExponent(exp);
        PhongMaterial_ptr33->setCd(green);

        Sphere*	sphere_ptr33 = new Sphere(Vector3Bf(-63, -39, -180), 11);
        sphere_ptr33->setMaterial(PhongMaterial_ptr33);							// green
        rt->addObject(sphere_ptr33);


        PhongMaterial* PhongMaterial_ptr34 = new PhongMaterial;
        PhongMaterial_ptr34->setKa(ka);
        PhongMaterial_ptr34->setKd(kd);
        PhongMaterial_ptr34->setKs(ks);
        PhongMaterial_ptr34->setExponent(exp);
        PhongMaterial_ptr34->setCd(light_purple);

        Sphere*	sphere_ptr34 = new Sphere(Vector3Bf(46, 68, -200), 10);
        sphere_ptr34->setMaterial(PhongMaterial_ptr34);							// light purple
        rt->addObject(sphere_ptr34);


        PhongMaterial* PhongMaterial_ptr35 = new PhongMaterial;
        PhongMaterial_ptr35->setKa(ka);
        PhongMaterial_ptr35->setKd(kd);
        PhongMaterial_ptr35->setKs(ks);
        PhongMaterial_ptr35->setExponent(exp);
        PhongMaterial_ptr35->setCd(light_purple);

        Sphere*	sphere_ptr35 = new Sphere(Vector3Bf(-3, -72, -130), 12);
        sphere_ptr35->setMaterial(PhongMaterial_ptr35);							// light purple
        rt->addObject(sphere_ptr35);
        PhongMaterial_ptr1->setCs(Colour::White);
        PhongMaterial_ptr2->setCs(Colour::White);
        PhongMaterial_ptr3->setCs(Colour::White);
        PhongMaterial_ptr4->setCs(Colour::White);
        PhongMaterial_ptr5->setCs(Colour::White);
        PhongMaterial_ptr6->setCs(Colour::White);
        PhongMaterial_ptr7->setCs(Colour::White);
        PhongMaterial_ptr8->setCs(Colour::White);
        PhongMaterial_ptr9->setCs(Colour::White);
        PhongMaterial_ptr10->setCs(Colour::White);
        PhongMaterial_ptr11->setCs(Colour::White);
        PhongMaterial_ptr12->setCs(Colour::White);
        PhongMaterial_ptr13->setCs(Colour::White);
        PhongMaterial_ptr14->setCs(Colour::White);
        PhongMaterial_ptr15->setCs(Colour::White);
        PhongMaterial_ptr16->setCs(Colour::White);
        PhongMaterial_ptr17->setCs(Colour::White);
        PhongMaterial_ptr18->setCs(Colour::White);
        PhongMaterial_ptr19->setCs(Colour::White);
        PhongMaterial_ptr20->setCs(Colour::White);
        PhongMaterial_ptr21->setCs(Colour::White);
        PhongMaterial_ptr22->setCs(Colour::White);
        PhongMaterial_ptr23->setCs(Colour::White);
        PhongMaterial_ptr24->setCs(Colour::White);
        PhongMaterial_ptr25->setCs(Colour::White);
        PhongMaterial_ptr26->setCs(Colour::White);
        PhongMaterial_ptr27->setCs(Colour::White);
        PhongMaterial_ptr28->setCs(Colour::White);
        PhongMaterial_ptr29->setCs(Colour::White);
        PhongMaterial_ptr30->setCs(Colour::White);
        PhongMaterial_ptr31->setCs(Colour::White);
        PhongMaterial_ptr32->setCs(Colour::White);
        PhongMaterial_ptr33->setCs(Colour::White);
        PhongMaterial_ptr34->setCs(Colour::White);
        PhongMaterial_ptr35->setCs(Colour::White);
    }
#endif // CHAPTER15
#ifdef CHAPTER16
{
  {
        PointLight * dirLight=new PointLight();
        Vector3Bf direction = Vector3Bf(100,100,200);
//        Vector3Bf::normalize(direction);
        dirLight->m_location=direction;
        dirLight->m_colour=Colour::White;
        dirLight->m_ls=3.0f;
        dirLight->setShadows(true);
        rt->addLight(dirLight);



        // four spheres centered on the x axis


        float a = 0.75;  // scaling factor for yellow, orange, and light green

        Colour yellow(a * 1, a * 1, 0);								// yellow
        Colour brown(0.71, 0.40, 0.16);								// brown
        Colour dark_green(0.0, 0.41, 0.41);							// dark_green
        Colour orange(a * 1, a * 0.75, 0);							// orange
        Colour green(0, 0.6, 0.3);									// green
        Colour light_green(a * 0.65, a * 1, a * 0.30);				// light green
        Colour dark_yellow(0.61, 0.61, 0);							// dark yellow
        Colour light_purple(0.65, 0.3, 1);							// light purple
        Colour dark_purple(0.5, 0, 1);								// dark purple


        // PhongMaterial materials' reflection coefficients

        float ka 	= 0.25;
        float kd 	= 0.75;
        float ks 	= 0.1;
        float exp 	= 10.0f;


        // spheres

        PhongMaterial* PhongMaterial_ptr1 = new PhongMaterial;
        PhongMaterial_ptr1->setKa(ka);
        PhongMaterial_ptr1->setKd(kd);
        PhongMaterial_ptr1->setKs(ks);
        PhongMaterial_ptr1->setExponent(exp);
        PhongMaterial_ptr1->setCd(yellow);

        Sphere*	sphere_ptr1 = new Sphere(Vector3Bf(5, 3, 0), 30);
        sphere_ptr1->setMaterial(PhongMaterial_ptr1);	   							// yellow
        rt->addObject(sphere_ptr1);


        PhongMaterial* PhongMaterial_ptr2 = new PhongMaterial;
        PhongMaterial_ptr2->setKa(ka);
        PhongMaterial_ptr2->setKd(kd);
        PhongMaterial_ptr2->setKs(ks);
        PhongMaterial_ptr2->setExponent(exp);
        PhongMaterial_ptr2->setCd(brown);

        Sphere*	sphere_ptr2 = new Sphere(Vector3Bf(45, -7, -60), 20);
        sphere_ptr2->setMaterial(PhongMaterial_ptr2);								// brown
        rt->addObject(sphere_ptr2);


        PhongMaterial* PhongMaterial_ptr3 = new PhongMaterial;
        PhongMaterial_ptr3->setKa(ka);
        PhongMaterial_ptr3->setKd(kd);
        PhongMaterial_ptr3->setKs(ks);
        PhongMaterial_ptr3->setExponent(exp);
        PhongMaterial_ptr3->setCd(dark_green);

        Sphere*	sphere_ptr3 = new Sphere(Vector3Bf(40, 43, -100), 17);
        sphere_ptr3->setMaterial(PhongMaterial_ptr3);								// dark green
        rt->addObject(sphere_ptr3);


        PhongMaterial* PhongMaterial_ptr4 = new PhongMaterial;
        PhongMaterial_ptr4->setKa(ka);
        PhongMaterial_ptr4->setKd(kd);
        PhongMaterial_ptr4->setKs(ks);
        PhongMaterial_ptr4->setExponent(exp);
        PhongMaterial_ptr4->setCd(orange);

        Sphere*	sphere_ptr4 = new Sphere(Vector3Bf(-20, 28, -15), 20);
        sphere_ptr4->setMaterial(PhongMaterial_ptr4);								// orange
        rt->addObject(sphere_ptr4);


        PhongMaterial* PhongMaterial_ptr5 = new PhongMaterial;
        PhongMaterial_ptr5->setKa(ka);
        PhongMaterial_ptr5->setKd(kd);
        PhongMaterial_ptr5->setKs(ks);
        PhongMaterial_ptr5->setExponent(exp);
        PhongMaterial_ptr5->setCd(green);

        Sphere*	sphere_ptr5 = new Sphere(Vector3Bf(-25, -7, -35), 27);
        sphere_ptr5->setMaterial(PhongMaterial_ptr5);								// green
        rt->addObject(sphere_ptr5);


        PhongMaterial* PhongMaterial_ptr6 = new PhongMaterial;
        PhongMaterial_ptr6->setKa(ka);
        PhongMaterial_ptr6->setKd(kd);
        PhongMaterial_ptr6->setKs(ks);
        PhongMaterial_ptr6->setExponent(exp);
        PhongMaterial_ptr6->setCd(light_green);

        Sphere*	sphere_ptr6 = new Sphere(Vector3Bf(20, -27, -35), 25);
        sphere_ptr6->setMaterial(PhongMaterial_ptr6);								// light green
        rt->addObject(sphere_ptr6);


        PhongMaterial* PhongMaterial_ptr7 = new PhongMaterial;
        PhongMaterial_ptr7->setKa(ka);
        PhongMaterial_ptr7->setKd(kd);
        PhongMaterial_ptr7->setKs(ks);
        PhongMaterial_ptr7->setExponent(exp);
        PhongMaterial_ptr7->setCd(green);

        Sphere*	sphere_ptr7 = new Sphere(Vector3Bf(35, 18, -35), 22);
        sphere_ptr7->setMaterial(PhongMaterial_ptr7);   							// green
        rt->addObject(sphere_ptr7);


        PhongMaterial* PhongMaterial_ptr8 = new PhongMaterial;
        PhongMaterial_ptr8->setKa(ka);
        PhongMaterial_ptr8->setKd(kd);
        PhongMaterial_ptr8->setKs(ks);
        PhongMaterial_ptr8->setExponent(exp);
        PhongMaterial_ptr8->setCd(brown);

        Sphere*	sphere_ptr8 = new Sphere(Vector3Bf(-57, -17, -50), 15);
        sphere_ptr8->setMaterial(PhongMaterial_ptr8);								// brown
        rt->addObject(sphere_ptr8);


        PhongMaterial* PhongMaterial_ptr9 = new PhongMaterial;
        PhongMaterial_ptr9->setKa(ka);
        PhongMaterial_ptr9->setKd(kd);
        PhongMaterial_ptr9->setKs(ks);
        PhongMaterial_ptr9->setExponent(exp);
        PhongMaterial_ptr9->setCd(light_green);

        Sphere*	sphere_ptr9 = new Sphere(Vector3Bf(-47, 16, -80), 23);
        sphere_ptr9->setMaterial(PhongMaterial_ptr9);								// light green
        rt->addObject(sphere_ptr9);


        PhongMaterial* PhongMaterial_ptr10 = new PhongMaterial;
        PhongMaterial_ptr10->setKa(ka);
        PhongMaterial_ptr10->setKd(kd);
        PhongMaterial_ptr10->setKs(ks);
        PhongMaterial_ptr10->setExponent(exp);
        PhongMaterial_ptr10->setCd(dark_green);

        Sphere*	sphere_ptr10 = new Sphere(Vector3Bf(-15, -32, -60), 22);
        sphere_ptr10->setMaterial(PhongMaterial_ptr10);     						// dark green
        rt->addObject(sphere_ptr10);


        PhongMaterial* PhongMaterial_ptr11 = new PhongMaterial;
        PhongMaterial_ptr11->setKa(ka);
        PhongMaterial_ptr11->setKd(kd);
        PhongMaterial_ptr11->setKs(ks);
        PhongMaterial_ptr11->setExponent(exp);
        PhongMaterial_ptr11->setCd(dark_yellow);

        Sphere*	sphere_ptr11 = new Sphere(Vector3Bf(-35, -37, -80), 22);
        sphere_ptr11->setMaterial(PhongMaterial_ptr11);							// dark yellow
        rt->addObject(sphere_ptr11);


        PhongMaterial* PhongMaterial_ptr12 = new PhongMaterial;
        PhongMaterial_ptr12->setKa(ka);
        PhongMaterial_ptr12->setKd(kd);
        PhongMaterial_ptr12->setKs(ks);
        PhongMaterial_ptr12->setExponent(exp);
        PhongMaterial_ptr12->setCd(dark_yellow);

        Sphere*	sphere_ptr12 = new Sphere(Vector3Bf(10, 43, -80), 22);
        sphere_ptr12->setMaterial(PhongMaterial_ptr12);							// dark yellow
        rt->addObject(sphere_ptr12);


        PhongMaterial* PhongMaterial_ptr13 = new PhongMaterial;
        PhongMaterial_ptr13->setKa(ka);
        PhongMaterial_ptr13->setKd(kd);
        PhongMaterial_ptr13->setKs(ks);
        PhongMaterial_ptr13->setExponent(exp);
        PhongMaterial_ptr13->setCd(dark_yellow);

        Sphere*	sphere_ptr13 = new Sphere(Vector3Bf(30, -7, -80), 10);
        sphere_ptr13->setMaterial(PhongMaterial_ptr13);
        rt->addObject(sphere_ptr13);											// dark yellow (hidden)


        PhongMaterial* PhongMaterial_ptr14 = new PhongMaterial;
        PhongMaterial_ptr14->setKa(ka);
        PhongMaterial_ptr14->setKd(kd);
        PhongMaterial_ptr14->setKs(ks);
        PhongMaterial_ptr14->setExponent(exp);
        PhongMaterial_ptr14->setCd(dark_green);

        Sphere*	sphere_ptr14 = new Sphere(Vector3Bf(-40, 48, -110), 18);
        sphere_ptr14->setMaterial(PhongMaterial_ptr14); 							// dark green
        rt->addObject(sphere_ptr14);


        PhongMaterial* PhongMaterial_ptr15 = new PhongMaterial;
        PhongMaterial_ptr15->setKa(ka);
        PhongMaterial_ptr15->setKd(kd);
        PhongMaterial_ptr15->setKs(ks);
        PhongMaterial_ptr15->setExponent(exp);
        PhongMaterial_ptr15->setCd(brown);

        Sphere*	sphere_ptr15 = new Sphere(Vector3Bf(-10, 53, -120), 18);
        sphere_ptr15->setMaterial(PhongMaterial_ptr15); 							// brown
        rt->addObject(sphere_ptr15);


        PhongMaterial* PhongMaterial_ptr16 = new PhongMaterial;
        PhongMaterial_ptr16->setKa(ka);
        PhongMaterial_ptr16->setKd(kd);
        PhongMaterial_ptr16->setKs(ks);
        PhongMaterial_ptr16->setExponent(exp);
        PhongMaterial_ptr16->setCd(light_purple);

        Sphere*	sphere_ptr16 = new Sphere(Vector3Bf(-55, -52, -100), 10);
        sphere_ptr16->setMaterial(PhongMaterial_ptr16);							// light purple
        rt->addObject(sphere_ptr16);


        PhongMaterial* PhongMaterial_ptr17 = new PhongMaterial;
        PhongMaterial_ptr17->setKa(ka);
        PhongMaterial_ptr17->setKd(kd);
        PhongMaterial_ptr17->setKs(ks);
        PhongMaterial_ptr17->setExponent(exp);
        PhongMaterial_ptr17->setCd(brown);

        Sphere*	sphere_ptr17 = new Sphere(Vector3Bf(5, -52, -100), 15);
        sphere_ptr17->setMaterial(PhongMaterial_ptr17);							// browm
        rt->addObject(sphere_ptr17);


        PhongMaterial* PhongMaterial_ptr18 = new PhongMaterial;
        PhongMaterial_ptr18->setKa(ka);
        PhongMaterial_ptr18->setKd(kd);
        PhongMaterial_ptr18->setKs(ks);
        PhongMaterial_ptr18->setExponent(exp);
        PhongMaterial_ptr18->setCd(dark_purple);

        Sphere*	sphere_ptr18 = new Sphere(Vector3Bf(-20, -57, -120), 15);
        sphere_ptr18->setMaterial(PhongMaterial_ptr18);							// dark purple
        rt->addObject(sphere_ptr18);


        PhongMaterial* PhongMaterial_ptr19 = new PhongMaterial;
        PhongMaterial_ptr19->setKa(ka);
        PhongMaterial_ptr19->setKd(kd);
        PhongMaterial_ptr19->setKs(ks);
        PhongMaterial_ptr19->setExponent(exp);
        PhongMaterial_ptr19->setCd(dark_green);

        Sphere*	sphere_ptr19 = new Sphere(Vector3Bf(55, -27, -100), 17);
        sphere_ptr19->setMaterial(PhongMaterial_ptr19);							// dark green
        rt->addObject(sphere_ptr19);


        PhongMaterial* PhongMaterial_ptr20 = new PhongMaterial;
        PhongMaterial_ptr20->setKa(ka);
        PhongMaterial_ptr20->setKd(kd);
        PhongMaterial_ptr20->setKs(ks);
        PhongMaterial_ptr20->setExponent(exp);
        PhongMaterial_ptr20->setCd(brown);

        Sphere*	sphere_ptr20 = new Sphere(Vector3Bf(50, -47, -120), 15);
        sphere_ptr20->setMaterial(PhongMaterial_ptr20);							// browm
        rt->addObject(sphere_ptr20);


        PhongMaterial* PhongMaterial_ptr21 = new PhongMaterial;
        PhongMaterial_ptr21->setKa(ka);
        PhongMaterial_ptr21->setKd(kd);
        PhongMaterial_ptr21->setKs(ks);
        PhongMaterial_ptr21->setExponent(exp);
        PhongMaterial_ptr21->setCd(light_purple);

        Sphere*	sphere_ptr21 = new Sphere(Vector3Bf(70, -42, -150), 10);
        sphere_ptr21->setMaterial(PhongMaterial_ptr21);							// light purple
        rt->addObject(sphere_ptr21);


        PhongMaterial* PhongMaterial_ptr22 = new PhongMaterial;
        PhongMaterial_ptr22->setKa(ka);
        PhongMaterial_ptr22->setKd(kd);
        PhongMaterial_ptr22->setKs(ks);
        PhongMaterial_ptr22->setExponent(exp);
        PhongMaterial_ptr22->setCd(light_purple);

        Sphere*	sphere_ptr22 = new Sphere(Vector3Bf(5, 73, -130), 12);
        sphere_ptr22->setMaterial(PhongMaterial_ptr22);							// light purple
        rt->addObject(sphere_ptr22);


        PhongMaterial* PhongMaterial_ptr23 = new PhongMaterial;
        PhongMaterial_ptr23->setKa(ka);
        PhongMaterial_ptr23->setKd(kd);
        PhongMaterial_ptr23->setKs(ks);
        PhongMaterial_ptr23->setExponent(exp);
        PhongMaterial_ptr23->setCd(dark_purple);

        Sphere*	sphere_ptr23 = new Sphere(Vector3Bf(66, 21, -130), 13);
        sphere_ptr23->setMaterial(PhongMaterial_ptr23);							// dark purple
        rt->addObject(sphere_ptr23);


        PhongMaterial* PhongMaterial_ptr24 = new PhongMaterial;
        PhongMaterial_ptr24->setKa(ka);
        PhongMaterial_ptr24->setKd(kd);
        PhongMaterial_ptr24->setKs(ks);
        PhongMaterial_ptr24->setExponent(exp);
        PhongMaterial_ptr24->setCd(light_purple);

        Sphere*	sphere_ptr24 = new Sphere(Vector3Bf(72, -12, -140), 12);
        sphere_ptr24->setMaterial(PhongMaterial_ptr24);							// light purple
        rt->addObject(sphere_ptr24);


        PhongMaterial* PhongMaterial_ptr25 = new PhongMaterial;
        PhongMaterial_ptr25->setKa(ka);
        PhongMaterial_ptr25->setKd(kd);
        PhongMaterial_ptr25->setKs(ks);
        PhongMaterial_ptr25->setExponent(exp);
        PhongMaterial_ptr25->setCd(green);

        Sphere*	sphere_ptr25 = new Sphere(Vector3Bf(64, 5, -160), 11);
        sphere_ptr25->setMaterial(PhongMaterial_ptr25);					 		// green
        rt->addObject(sphere_ptr25);


        PhongMaterial* PhongMaterial_ptr26 = new PhongMaterial;
        PhongMaterial_ptr26->setKa(ka);
        PhongMaterial_ptr26->setKd(kd);
        PhongMaterial_ptr26->setKs(ks);
        PhongMaterial_ptr26->setExponent(exp);
        PhongMaterial_ptr26->setCd(light_purple);

        Sphere*	sphere_ptr26 = new Sphere(Vector3Bf(55, 38, -160), 12);
        sphere_ptr26->setMaterial(PhongMaterial_ptr26);							// light purple
        rt->addObject(sphere_ptr26);


        PhongMaterial* PhongMaterial_ptr27 = new PhongMaterial;
        PhongMaterial_ptr27->setKa(ka);
        PhongMaterial_ptr27->setKd(kd);
        PhongMaterial_ptr27->setKs(ks);
        PhongMaterial_ptr27->setExponent(exp);
        PhongMaterial_ptr27->setCd(light_purple);

        Sphere*	sphere_ptr27 = new Sphere(Vector3Bf(-73, -2, -160), 12);
        sphere_ptr27->setMaterial(PhongMaterial_ptr27);							// light purple
        rt->addObject(sphere_ptr27);


        PhongMaterial* PhongMaterial_ptr28 = new PhongMaterial;
        PhongMaterial_ptr28->setKa(ka);
        PhongMaterial_ptr28->setKd(kd);
        PhongMaterial_ptr28->setKs(ks);
        PhongMaterial_ptr28->setExponent(exp);
        PhongMaterial_ptr28->setCd(dark_purple);

        Sphere*	sphere_ptr28 = new Sphere(Vector3Bf(30, -62, -140), 15);
        sphere_ptr28->setMaterial(PhongMaterial_ptr28); 							// dark purple
        rt->addObject(sphere_ptr28);



        PhongMaterial* PhongMaterial_ptr29 = new PhongMaterial;
        PhongMaterial_ptr29->setKa(ka);
        PhongMaterial_ptr29->setKd(kd);
        PhongMaterial_ptr29->setKs(ks);
        PhongMaterial_ptr29->setExponent(exp);
        PhongMaterial_ptr29->setCd(dark_purple);

        Sphere*	sphere_ptr29 = new Sphere(Vector3Bf(25, 63, -140), 15);
        sphere_ptr29->setMaterial(PhongMaterial_ptr29);							// dark purple
        rt->addObject(sphere_ptr29);


        PhongMaterial* PhongMaterial_ptr30 = new PhongMaterial;
        PhongMaterial_ptr30->setKa(ka);
        PhongMaterial_ptr30->setKd(kd);
        PhongMaterial_ptr30->setKs(ks);
        PhongMaterial_ptr30->setExponent(exp);
        PhongMaterial_ptr30->setCd(dark_purple);

        Sphere*	sphere_ptr30 = new Sphere(Vector3Bf(-60, 46, -140), 15);
        sphere_ptr30->setMaterial(PhongMaterial_ptr30); 							// dark purple
        rt->addObject(sphere_ptr30);


        PhongMaterial* PhongMaterial_ptr31 = new PhongMaterial;
        PhongMaterial_ptr31->setKa(ka);
        PhongMaterial_ptr31->setKd(kd);
        PhongMaterial_ptr31->setKs(ks);
        PhongMaterial_ptr31->setExponent(exp);
        PhongMaterial_ptr31->setCd(light_purple);

        Sphere*	sphere_ptr31 = new Sphere(Vector3Bf(-30, 68, -130), 12);
        sphere_ptr31->setMaterial(PhongMaterial_ptr31); 							// light purple
        rt->addObject(sphere_ptr31);


        PhongMaterial* PhongMaterial_ptr32 = new PhongMaterial;
        PhongMaterial_ptr32->setKa(ka);
        PhongMaterial_ptr32->setKd(kd);
        PhongMaterial_ptr32->setKs(ks);
        PhongMaterial_ptr32->setExponent(exp);
        PhongMaterial_ptr32->setCd(green);

        Sphere*	sphere_ptr32 = new Sphere(Vector3Bf(58, 56, -180), 11);
        sphere_ptr32->setMaterial(PhongMaterial_ptr32);							//  green
        rt->addObject(sphere_ptr32);


        PhongMaterial* PhongMaterial_ptr33 = new PhongMaterial;
        PhongMaterial_ptr33->setKa(ka);
        PhongMaterial_ptr33->setKd(kd);
        PhongMaterial_ptr33->setKs(ks);
        PhongMaterial_ptr33->setExponent(exp);
        PhongMaterial_ptr33->setCd(green);

        Sphere*	sphere_ptr33 = new Sphere(Vector3Bf(-63, -39, -180), 11);
        sphere_ptr33->setMaterial(PhongMaterial_ptr33);							// green
        rt->addObject(sphere_ptr33);


        PhongMaterial* PhongMaterial_ptr34 = new PhongMaterial;
        PhongMaterial_ptr34->setKa(ka);
        PhongMaterial_ptr34->setKd(kd);
        PhongMaterial_ptr34->setKs(ks);
        PhongMaterial_ptr34->setExponent(exp);
        PhongMaterial_ptr34->setCd(light_purple);

        Sphere*	sphere_ptr34 = new Sphere(Vector3Bf(46, 68, -200), 10);
        sphere_ptr34->setMaterial(PhongMaterial_ptr34);							// light purple
        rt->addObject(sphere_ptr34);


        PhongMaterial* PhongMaterial_ptr35 = new PhongMaterial;
        PhongMaterial_ptr35->setKa(ka);
        PhongMaterial_ptr35->setKd(kd);
        PhongMaterial_ptr35->setKs(ks);
        PhongMaterial_ptr35->setExponent(exp);
        PhongMaterial_ptr35->setCd(light_purple);

        Sphere*	sphere_ptr35 = new Sphere(Vector3Bf(-3, -72, -130), 12);
        sphere_ptr35->setMaterial(PhongMaterial_ptr35);							// light purple
        rt->addObject(sphere_ptr35);
        PhongMaterial_ptr1->setCs(Colour::White);
        PhongMaterial_ptr2->setCs(Colour::White);
        PhongMaterial_ptr3->setCs(Colour::White);
        PhongMaterial_ptr4->setCs(Colour::White);
        PhongMaterial_ptr5->setCs(Colour::White);
        PhongMaterial_ptr6->setCs(Colour::White);
        PhongMaterial_ptr7->setCs(Colour::White);
        PhongMaterial_ptr8->setCs(Colour::White);
        PhongMaterial_ptr9->setCs(Colour::White);
        PhongMaterial_ptr10->setCs(Colour::White);
        PhongMaterial_ptr11->setCs(Colour::White);
        PhongMaterial_ptr12->setCs(Colour::White);
        PhongMaterial_ptr13->setCs(Colour::White);
        PhongMaterial_ptr14->setCs(Colour::White);
        PhongMaterial_ptr15->setCs(Colour::White);
        PhongMaterial_ptr16->setCs(Colour::White);
        PhongMaterial_ptr17->setCs(Colour::White);
        PhongMaterial_ptr18->setCs(Colour::White);
        PhongMaterial_ptr19->setCs(Colour::White);
        PhongMaterial_ptr20->setCs(Colour::White);
        PhongMaterial_ptr21->setCs(Colour::White);
        PhongMaterial_ptr22->setCs(Colour::White);
        PhongMaterial_ptr23->setCs(Colour::White);
        PhongMaterial_ptr24->setCs(Colour::White);
        PhongMaterial_ptr25->setCs(Colour::White);
        PhongMaterial_ptr26->setCs(Colour::White);
        PhongMaterial_ptr27->setCs(Colour::White);
        PhongMaterial_ptr28->setCs(Colour::White);
        PhongMaterial_ptr29->setCs(Colour::White);
        PhongMaterial_ptr30->setCs(Colour::White);
        PhongMaterial_ptr31->setCs(Colour::White);
        PhongMaterial_ptr32->setCs(Colour::White);
        PhongMaterial_ptr33->setCs(Colour::White);
        PhongMaterial_ptr34->setCs(Colour::White);
        PhongMaterial_ptr35->setCs(Colour::White);
    }
}
#endif CHAPTER16
#ifdef CHAPTER1610
{


PointLight* light_ptr2 = new PointLight();
	light_ptr2->m_location=Vector3Bf(100, 50, 150);
	light_ptr2->m_ls=3.0;
	light_ptr2->setShadows(true);
	rt->addLight(light_ptr2);

	MatteMaterial* MatteMaterial_ptr1 = new MatteMaterial();
	MatteMaterial_ptr1->setKa(0.25);
	MatteMaterial_ptr1->setKd(0.65);
	MatteMaterial_ptr1->setCd(Colour::Yellow);	  				// yellow
	Sphere*	sphere_ptr1 = new Sphere(Vector3Bf(10, -5, 0), 27);
	sphere_ptr1->setMaterial(MatteMaterial_ptr1);
	rt->addObject(sphere_ptr1);

	MatteMaterial* MatteMaterial_ptr2 = new MatteMaterial();
	MatteMaterial_ptr2->setKa(0.15);
	MatteMaterial_ptr2->setKd(0.85);
	MatteMaterial_ptr2->setCd(Colour(0.71, 0.40, 0.16));   		// brown
	Sphere*	sphere_ptr2 = new Sphere(Vector3Bf(-25, 10, -35), 27);
	sphere_ptr2->setMaterial(MatteMaterial_ptr2);
	rt->addObject(sphere_ptr2);

	MatteMaterial* MatteMaterial_ptr3 = new MatteMaterial();
	MatteMaterial_ptr3->setKa(0.15);
	MatteMaterial_ptr3->setKd(0.5);
	MatteMaterial_ptr3->setCd(Colour(0, 0.4, 0.2));				// dark green
	Plane* plane_ptr = new Plane(Vector3Bf(0, 0, -50), Vector3Bf(0, 0, 1));
	plane_ptr->setMaterial(MatteMaterial_ptr3);
	rt->addObject(plane_ptr);
}
#endif // CHAPTER1610
#ifdef CUBESHADOW
{
//    PointLight* light_ptr2 = new PointLight();
//	light_ptr2->m_location=Vector3Bf(100, 50, 150);
//	light_ptr2->m_ls=3.0;
//	light_ptr2->setShadows(false);
//	rt->addLight(light_ptr2);
//
//Mesh * m = FileLoader::loadMesh("models/cube.obj");
//rt->addObject(m);
//
//	MatteMaterial* MatteMaterial_ptr2 = new MatteMaterial();
//	MatteMaterial_ptr2->setKa(0.15);
//	MatteMaterial_ptr2->setKd(0.85);
//	MatteMaterial_ptr2->setCd(Colour(0.71, 0.40, 0.16));   		// brown
//	Sphere*	sphere_ptr2 = new Sphere(Vector3Bf(0, 0, 0), 1);
//	sphere_ptr2->setMaterial(MatteMaterial_ptr2);
//	rt->addObject(sphere_ptr2);
//
//	MatteMaterial* MatteMaterial_ptr3 = new MatteMaterial();
//	MatteMaterial_ptr3->setKa(0.15);
//	MatteMaterial_ptr3->setKd(0.5);
//	MatteMaterial_ptr3->setCd(Colour(0, 0.4, 0.2));				// dark green
//	Plane* plane_ptr = new Plane(Vector3Bf(0,-2,0),Vector3Bf(0,1,0));
//	plane_ptr->setMaterial(MatteMaterial_ptr3);
//	rt->addObject(plane_ptr);

//   MatteMaterial* mat=new MatteMaterial();
//    mat->setKa(0.25f);
//    mat->setKd(0.6f);
//    mat->setCd(Colour::Red);
//
//
//    MatteMaterial* mat2=new MatteMaterial();
//    mat2->setKa(0.5);
//    mat2->setKd(0.15f);
//    mat2->setCd(Colour::Green);
//
//    IRaycastable * plane= new Plane(Vector3Bf(0,-2,0),Vector3Bf(0,1,0));
//
//
//    PhongMaterial* mat3=new PhongMaterial();
//    mat3->setKa(0.25f);
//    mat3->setKd(0.6f);
//    mat3->setKs(0.5f);
//    mat3->setCd(Colour::Red);
//    mat3->setExponent(0.6f);
//
//
//    plane->setMaterial(mat2);
//    rt->addObject(plane);
//
//
//
//    IRaycastable *sphere3=new Sphere(Vector3Bf(12,0,3)  , 2);
//    sphere3->setMaterial(mat3);
//
//   rt->addObject(sphere3);

    Mesh * m =FileLoader::loadMesh(("models/cube.obj"));

    rt->addObject(m);

    Ambient*ambient= new Ambient(0.5f,Colour::White);
    rt->setAmbientLight(ambient);

    PointLight * light= new PointLight();
    light->m_location=Vector3Bf(0,10,10);
    light->m_ls=3.00f;
    light->m_colour=Colour::White;
    light->setShadows(false);
    rt->addLight(light);
}
#endif // CUBESHADOW
#ifdef TEXTURE
{


Plane * p = new Plane(Vector3Bf(0,-2,0),Vector3Bf(0,1,0));
TextureMatte * mM = new TextureMatte();
mM->setCd(new ImageTexture(new Image("textures/plane.tga"),new RectMapping(p,Vector2Bf(0.001,0.001))));
mM->setKa(0.4f);
mM->setKd(0.5f);
p->setMaterial(mM);
rt->addObject(p);




Sphere * s =new Sphere(Vector3Bf(0,5,0),2);
TexturePhong *m = new TexturePhong();
m->setCd(new ImageTexture(new Image("textures/earth.tga"),new SpericalMapping(s)));
m->setCs(Colour::White);
m->setKa(0.45);
m->setKd(0.34);
m->setExponent(10.0f);
m->setKs(0.1f);
s->setMaterial(m);

rt->addObject(s);


Sphere * s2 =new Sphere(Vector3Bf(5,3,0),2);
TexturePhong *m2 = new TexturePhong();
m2->setCd(new ImageTexture(new Image("textures/mars.tga"),new SpericalMapping(s2)));
m2->setCs(Colour::White);
m2->setKa(0.45);
m2->setKd(0.34);
m2->setExponent(10.0f);
m2->setKs(0.1f);
s2->setMaterial(m2);

rt->addObject(s2);

PointLight * pl = new PointLight();
pl->m_ls=3.0f;
pl->setShadows(false);
pl->m_location=Vector3Bf(0,0,6);
rt->addLight(pl);
}
#endif
#ifdef MIRROR
{

//    ICamera *persp = new PerspectiveCamera(Vector3Bf(50, 10, 40),
//                                           Vector3Bf(0, 0,0),
//                                           Vector3Bf::Up,
//                                          150,
//                                           Vector2Bf(1,1));


    Ambient*ambient= new Ambient(1.0f,Colour::White);
    rt->setAmbientLight(ambient);
PointLight* light_ptr = new PointLight();
	light_ptr->m_location=Vector3Bf(0, 20, 20);
	light_ptr->m_ls=(5.0);
	light_ptr->setShadows(false);
	rt->addLight(light_ptr);


	// the four spheres

	float ka = 0.75;
	float kd = 0.75;
	float ks = 0.1;
	float e = 20.0;
	float kr = 1;

	ReflectiveMaterial* ReflectiveMaterial_ptr1 = new ReflectiveMaterial;
	ReflectiveMaterial_ptr1->setKa(ka);
	ReflectiveMaterial_ptr1->setKd(kd);
	ReflectiveMaterial_ptr1->setKs(ks);
	ReflectiveMaterial_ptr1->setCd(Colour(0.168, 0.171, 0.009));    	// pink
	ReflectiveMaterial_ptr1->setCr(Colour::White);
	ReflectiveMaterial_ptr1->setExponent(e);
	ReflectiveMaterial_ptr1->setKr(kr);

	Sphere* sphere_ptr1 = new Sphere(Vector3Bf(0.0, 1.414, 0.0), 0.866);
	sphere_ptr1->setMaterial(ReflectiveMaterial_ptr1);
	rt->addObject(sphere_ptr1);
	//std::cout<<ReflectiveMaterial_ptr1->getCs()<<"\n";


	ReflectiveMaterial* ReflectiveMaterial_ptr2 = new ReflectiveMaterial;
	ReflectiveMaterial_ptr2->setKa(ka);
	ReflectiveMaterial_ptr2->setKd(kd);
	ReflectiveMaterial_ptr2->setCd(Colour(0.094, 0.243, 0.029));   	// green
	ReflectiveMaterial_ptr2->setKs(ks);
	ReflectiveMaterial_ptr2->setExponent(e);
	ReflectiveMaterial_ptr2->setKr(kr);
	ReflectiveMaterial_ptr2->setCr(Colour::White);

	Sphere* sphere_ptr2 = new Sphere(Vector3Bf(0.0, 0.0, 1.0), 0.866);
	sphere_ptr2->setMaterial(ReflectiveMaterial_ptr2);
	rt->addObject(sphere_ptr2);
//
//
	ReflectiveMaterial* ReflectiveMaterial_ptr3 = new ReflectiveMaterial;
	ReflectiveMaterial_ptr3->setKa(ka);
	ReflectiveMaterial_ptr3->setKd(kd);
	ReflectiveMaterial_ptr3->setCd(Colour(0.243, 0.018, 0.164));     	// red
	ReflectiveMaterial_ptr3->setKs(ks);
	ReflectiveMaterial_ptr3->setExponent(e);
	ReflectiveMaterial_ptr3->setKr(kr);
	ReflectiveMaterial_ptr3->setCr(Colour::White);
	Sphere* sphere_ptr3 = new Sphere(Vector3Bf(0.866, 0.0, -0.5), 0.866);
	sphere_ptr3->setMaterial(ReflectiveMaterial_ptr3);
	rt->addObject(sphere_ptr3);


	ReflectiveMaterial* ReflectiveMaterial_ptr4 = new ReflectiveMaterial;
	ReflectiveMaterial_ptr4->setKa(ka);
	ReflectiveMaterial_ptr4->setKd(kd);
	ReflectiveMaterial_ptr4->setCd(Colour(0.094, 0.1, 0.243));    		// blue
	ReflectiveMaterial_ptr4->setKs(ks);
	ReflectiveMaterial_ptr4->setExponent(e);
	ReflectiveMaterial_ptr4->setKr(kr);
	ReflectiveMaterial_ptr4->setCr(Colour::White);

	Sphere* sphere_ptr4 = new Sphere(Vector3Bf(-0.866, 0.0, -0.5), 0.866);
	sphere_ptr4->setMaterial(ReflectiveMaterial_ptr4);
	rt->addObject(sphere_ptr4);

rt->setDepth(12);
}
#endif // MIRROR
#ifdef TRANSPARENT_EX
	{


	PointLight* light_ptr1 = new PointLight;
	light_ptr1->m_location=Vector3Bf(40, 50, 0);
	light_ptr1->m_ls=(4.5);
	light_ptr1->setShadows(false);
	rt->addLight(light_ptr1);

	TransparentMaterial * glass= new TransparentMaterial();
	glass->setKs(0.2);
	glass->setExp(2000.0);
	glass->setIndexRef(1.0f);
	glass->setKr(0.1);
	glass->setTransmissionCoof(1.46);
   // glass->setCd(Colour::White);
   // glass->setCr(Colour::White);
	Sphere * sp= new Sphere(Vector3Bf(0.0, 4.5, 0.0), 3.0);
	sp->setMaterial(glass);
	rt->addObject(sp);



ReflectiveMaterial*	reflective_ptr = new ReflectiveMaterial;
	reflective_ptr->setKa(0.3);
	reflective_ptr->setKd(0.3);
	reflective_ptr->setCd(Colour::Red);
	reflective_ptr->setKs(0.2);
	reflective_ptr->setExponent(2000.0);
	reflective_ptr->setKr(0.25);
	//reflective_ptr->setCr(Colour::White);

	Sphere* sphere_ptr2 = new Sphere(Vector3Bf(4, 4, -6), 3);
	sphere_ptr2->setMaterial(reflective_ptr);
	//rt->addObject(sphere_ptr2);

Plane * p = new Plane(Vector3Bf(0,-2,0),Vector3Bf(0,1,0));
TextureMatte * mM = new TextureMatte();
mM->setCd(new ImageTexture(new Image("textures/plane.tga"),new RectMapping(p,Vector2Bf(0.001,0.001))));
mM->setKa(0.4f);
mM->setKd(0.5f);
p->setMaterial(mM);
rt->addObject(p);

rt->setDepth(3);
}
#endif // TRANSPARENT_SPHERE
#ifdef FRESNEL
{


	PointLight* light_ptr1 = new PointLight;
	light_ptr1->m_location=Vector3Bf(40, 50, 0);
	light_ptr1->m_ls=(4.5);
	light_ptr1->setShadows(false);
	rt->addLight(light_ptr1);

	DielectricMaterial * glass= new DielectricMaterial();
	glass->setKs(0.2);
	glass->setExp(2000.0);
	glass->setRefractionIN(1.5);
	glass->setRefractionOUT(1.0);
	glass->setCfIn(Colour::White);
	glass->setCfOut(Colour::White);
//	glass->setKr(0.1);
    glass->setCd(Colour::White);
//    glass->setCr(Colour::White);
	Sphere * sp= new Sphere(Vector3Bf(0.0, 4.5, 0.0), 3.0);
	sp->setMaterial(glass);
	rt->addObject(sp);



ReflectiveMaterial*	reflective_ptr = new ReflectiveMaterial;
	reflective_ptr->setKa(0.3);
	reflective_ptr->setKd(0.3);
	reflective_ptr->setCd(Colour::Red);
	reflective_ptr->setKs(0.2);
	reflective_ptr->setExponent(2000.0);
	reflective_ptr->setKr(0.25);
	reflective_ptr->setCr(Colour::White);

	Sphere* sphere_ptr2 = new Sphere(Vector3Bf(4, 4, -6), 3);
	sphere_ptr2->setMaterial(reflective_ptr);
	rt->addObject(sphere_ptr2);

Plane * p = new Plane(Vector3Bf(0,-2,0),Vector3Bf(0,1,0));
TextureMatte * mM = new TextureMatte();
mM->setCd(new ImageTexture(new Image("textures/plane.tga"),new RectMapping(p,Vector2Bf(0.001,0.001))));
mM->setKa(0.4f);
mM->setKd(0.5f);
p->setMaterial(mM);
rt->addObject(p);

rt->setDepth(2);
}
#endif // FRESNEL
#ifdef PHOTON_MAPPING
PointLight* light_ptr1 = new PointLight;
	light_ptr1->m_location=Vector3Bf(40, 50, 0);
	light_ptr1->m_ls=(4.5);
	light_ptr1->setShadows(false);
	rt->addLight(light_ptr1);

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

        float ka 	= 0.25;
        float kd 	= 0.75;
        float ks 	= 0.1;
        float exp 	= 10.0f;


        // spheres

        PhongMaterial* PhongMaterial_ptr1 = new PhongMaterial;
        PhongMaterial_ptr1->setKa(ka);
        PhongMaterial_ptr1->setKd(kd);
        PhongMaterial_ptr1->setKs(ks);
        PhongMaterial_ptr1->setExponent(exp);
        PhongMaterial_ptr1->setCd(Colour::Yellow);


	Sphere * sp= new Sphere(Vector3Bf(5.0, 4.5, 0.0), 3.0);
	sp->setMaterial(PhongMaterial_ptr1);
	rt->addObject(sp);

	Sphere * sp2= new Sphere(Vector3Bf(0.0, 14.5, 0.0), 3.0);
	sp2->setMaterial(PhongMaterial_ptr1);
	rt->addObject(sp2);

	Sphere * sp3= new Sphere(Vector3Bf(-4.0, 4.5, 3.0), 3.0);
	sp3->setMaterial(PhongMaterial_ptr1);
	rt->addObject(sp3);

	Sphere * sp4= new Sphere(Vector3Bf(10.0, 1.5, 0.0), 1.0);
	sp4->setMaterial(PhongMaterial_ptr1);
	rt->addObject(sp4);

	Sphere * sp5= new Sphere(Vector3Bf(0.0, 4.5, 0.0), 0.4);
	sp5->setMaterial(PhongMaterial_ptr1);
	rt->addObject(sp5);


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
#endif // PHOTON_MAPPING


#ifdef RAY_TRACE
rt->rayTrace();
#endif // RAY_TRACE
#ifdef PHOTON_MAPPING
PhotonMap * photonMap = new PhotonMap(10000,*rt);
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



