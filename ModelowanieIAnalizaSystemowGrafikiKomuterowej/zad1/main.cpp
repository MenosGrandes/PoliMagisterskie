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

// #define RENDERER
#define FOTO

using namespace d_type;
#ifdef RENDERER
#include "RenderTarget.h"
#include "VertexProcessor.h"
#include "TriangleMesh.h"
#include <SFML/Graphics.hpp>
#endif // RENDERER

#ifdef FOTO
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
#include "RayTriangle.h"
#include "FileLoader.h"
#include "MultiJitteringSampleGenerator.h"
#include "PointLight.h"
#include "MatteMaterial.h"
#include "PhongMaterial.h"
#include "CheckCPU.h"
#include "DirectionalLight.h"
#include "Image.h"
#else

#endif // FOTO


#ifdef FOTO
#define DRAWRAY
#define ZAD3OBJECTS
#define ZAD2OBJECTS
#define ZAD4OBJECTS
#define CLOCK
int main(int argc, char **argv)
{
    CheckCPU cpu;
    std::cout<<"There are "<<cpu.getNumberOfCores()<<" cores in CPU.\n";


#ifdef CLOCK
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
#endif // CLOCK

#ifdef ZAD1
    std::cout<<"R1\n";

    Sphere *s= new Sphere(Vector3Bf(),10  );


    Ray r1=Ray(Vector3Bf(0,0,-20),Vector3Bf(0,0,0),DESTINATION);
    Vector3BfVector r1V=s->intersect(r1);
    for(Vector3Bf n :r1V)
    {
        std::cout<<n<<"\n";
    }
////////////////////////////////////////////////////////
    std::cout<<"R2\n";

    Ray r2=Ray(Vector3Bf(0,0,-20),Vector3Bf(0,10,-20),DIRECTION);
    Vector3BfVector r2V=s->intersect(r2);
    for(Vector3Bf n :r2V)
    {
        std::cout<<n<<"\n";
    }
//////////////////////////////////////////////////////////
    std::cout<<"R3\n";
    Ray r3=Ray(Vector3Bf(-10,0,-20),Vector3Bf(-10,0,20),DESTINATION);
    Vector3BfVector r3V=s->intersect(r3);
    for(Vector3Bf n :r3V)
    {
        std::cout<<n<<"\n";
    }
////////////////////////////////////////////////////////
    std::cout<<"Plane1\n";
    Plane *p=new Plane(Vector3Bf(0,0,0),Vector3Bf(0,cosf(ToRadians::toRadians(45)),cosf(ToRadians::toRadians(45))));
    Vector3BfVector r4V=p->intersect(r2);
    for(Vector3Bf n :r4V)
    {
        std::cout<<n<<"\n";
    }
#endif // ZAD1
#ifdef DRAWRAY













    Vector2Bs img_size=Vector2Bs(800,800);


    RenderTarget *file = new RenderTarget(img_size);
    file->setCleanColour(Colour::Black);

    ICamera * orto=new OrtagonalCamera(Vector3Bf(0,0,0),0,Vector2Bf(10,10));
    // X Z Y
    ICamera *persp = new PerspectiveCamera(Vector3Bf(0,0,1000),
                                           Vector3Bf(0,0,0),
                                           Vector3Bf::Up,
                                           10,
                                           Vector2Bf(1,1));


    Sampler * s= new Sampler(new SquareSampleDistributor(),new RandomSampleGenerator(),4,1);
    RayTracer *rt = new RayTracer(persp,file,s);


//Image * im=new Image("file.tga");
//file->drawToFile(im->getPixels());
//




#define CHAPTER15
#ifdef CHAPTER15
{
DirectionalLight * dirLight=new DirectionalLight();
Vector3Bf direction = Vector3Bf(100,100,200);
Vector3Bf::normalize(direction);
dirLight->m_direction=direction;
dirLight->m_colour=Colour::White;
dirLight->m_ls=3.0f;
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





#endif // ZAD2

#ifdef DRAWRAY
    rt->rayTrace();
#endif // DRAWRAY




#ifdef CLOCK

    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
#endif // CLOCK


#ifdef DRAWRAY
    file->drawToFile("file.tga");
    delete file;
#endif // ZAD2
    d_type::Bint a432;
    std::cin>>a432;
    return 0;
}
#endif
#ifdef RENDERER
float getFPS(const sf::Time& time)
{
    return (1000000.0f / time.asMicroseconds());
}
int main(int argc, char **argv)
{





    Vector2Bs img_size=Vector2Bs(500,500);






    RenderTarget *file = new RenderTarget(img_size);







    std::array<render::TriangleFloat*,2> triangleArray;
    render::TriangleFloat *triangle= new render::TriangleFloat(Vector3Bf(-0.5f,0.1f,5),Vector3Bf(0.1f,-0.5f,1.0f),Vector3Bf(-0.5f,-0.5f,2.0));
//    render::TriangleFloat *triangle2= new render::TriangleFloat(Vector3Bf(1,-0.1f,3),Vector3Bf(-0.4f,-1.0f,10),Vector3Bf(-0.5f,0.1f,2));


    render::TriangleFloat *triangle2= new render::TriangleFloat(Vector3Bf(0,0,0),Vector3Bf(0.5f,0.5f,0),Vector3Bf(0.5f,0,0));

    triangleArray[0]=triangle;
    triangleArray[1]=triangle2;


///NAJPIERW z -1 -1
///potem obliczanie kamery
///i potem kanoniczne

    render::TriangleMesh *mesh= new render::TriangleMesh();
    mesh->loadOBJ("models/teapod.obj");

    VertexProcessor *vp= new VertexProcessor();

//    vp->setIdentity();
//    vp->setLookat(Vector3Bf(0,10,50),Vector3Bf(0,0,0),Vector3Bf(0,1,0));
//    vp->setPerspective(45,1,Vector2Bf(0.1f,10000));
//    vp->transform();
//    vp->addTriangle(triangle2);
//    vp->addTriangle(triangle);
//    vp->addTriangle(mesh);
//
//
//    for(Bsize i=0; i<triangleArray.size(); i++)
//    {
//        triangleArray[i]->init(img_size);
//    }
//    for(render::TriangleFloat * tri : mesh->getTriangles())
//    {
//        tri->init(img_size);
//    }
//
//
//    for(render::TriangleFloat * tri : mesh->getTriangles())
//    {
//       file->draw(*tri);
//    }
//    file->draw(*triangle2);
//    file->draw(*triangle);
//
    file->drawToFile("file.tga");



    sf::RenderWindow window(sf::VideoMode(img_size.x, img_size.y), "RENDERER!");




    sf::Texture texture;
    if (!texture.create(img_size.x, img_size.y))
    {
        std::cout<<"ERROR WITH TEXTURE\n";
    }








    sf::Sprite sprite(texture);

    sf::Uint8 * pixels = new sf::Uint8[img_size.x*img_size.y*4];
    sf::Clock FPSClock;
    std::stringstream ss;
    file->rewritePixelForTexture(pixels);
    texture.update(pixels);
    d_type::Bfloat angle=180;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Q)
                {
                    angle+=50;
                    std::cout<<angle<<"\n";;
                }
            }
        }
        vp->setIdentity();
        vp->setLookat(Vector3Bf(0,10,50),Vector3Bf(0,0,0),Vector3Bf(0,1,0));
        vp->setPerspective(45,1,Vector2Bf(0.1f,20));
        vp->multByRotation(54,Vector3Bf(0,1,0));
//        std::cout<<angle<<"\n";
        vp->transform();
        vp->addTriangle(mesh);



        for(render::TriangleFloat * tri : mesh->getTriangles())
        {
            tri->init(img_size);
            file->draw(*tri);
        }
//    for(Bsize i=0; i<triangleArray.size(); i++)
//    {
//        triangleArray[i]->init(img_size);
//        file->draw(*triangleArray[i]);
//    }

        texture.update(pixels);

        file->rewritePixelForTexture(pixels);

        window.clear();
        window.draw(sprite);
        //texture.update(window);
        window.display();

//        std::cout<<getFPS(FPSClock.restart())<<"\n";

//       window.setTitle(ss.str());
//       ss.str("");


    }







    d_type::Bint a32;
    std::cin>>a32;
    return 0;
}
#endif // RENDERER

