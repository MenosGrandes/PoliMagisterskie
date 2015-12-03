#include "RenderTarget.h"
#include "VertexProcessor.h"
#include "TriangleMesh.h"

int main(int argc, char **argv)
{
    Vector2Bi size(800,800);


    VertexProcessor vp;
    RenderTarget rt(size);


    vp.setPerspective(60.0f,1.0f,Vector2Bf(0.1f,100000.0f));
    vp.setLookat(Vector3Bf(0,0,20.0f),Vector3Bf(0,0,0),Vector3Bf::Up);
    vp.setIdentity();

    render::TriangleMesh *tr =new render::TriangleMesh();
    tr->loadOBJ("models/cube.obj");

    render::TriangleMesh *tr2 =new render::TriangleMesh();
    tr2->loadOBJ("models/DRAGON.obj");

//	vp.setIdentity();
//	processor.MultByRotation(50.0f, float3(1.0f, -1.0f, 0.0f));
//	processor.MultByTranslation(float3(0.0f, 5.0f, -3.0f));
//	//processor.MultByScale(float3(1.5f,1.5f, 1.5f));
//	processor.transformObjToProj();
//	mesh.Draw(rast, processor);



    vp.setIdentity();
    vp.multByScale(Vector3Bf(0.2f,0.2f,0.2f));

    vp.multByRotation(50.0f,Vector3Bf(1.0f,-1.0f,0.0f));
    vp.multByTranslation(Vector3Bf(0.0,5.f,-3.0f));

    vp.transform();

    tr->draw(vp, rt);

///////////////////
    vp.setIdentity();
//    vp.multByScale(Vector3Bf(0.2f,0.2f,0.2f));

    vp.multByRotation(50.0f,Vector3Bf(1.0f,-1.0f,0.0f));
    vp.multByTranslation(Vector3Bf(0.0,5.f,-3.0f));

    vp.transform();

    tr2->draw(vp, rt);

    rt.drawToFile("dupa.tga");











    d_type::Bint a32;
    std::cin>>a32;

    delete tr;
    return 0;
}
