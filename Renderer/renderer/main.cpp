#include "RenderTarget.h"
#include "VertexProcessor.h"
#include "TriangleMesh.h"

int main(int argc, char **argv)
{
Vector2Bi size(500,500);


VertexProcessor vp;
RenderTarget rt(size);


vp.setPerspective(60.0f,1.0f,Vector2Bf(0.1f,100.0f));
vp.setLookat(Vector3Bf(0,0,20.0f),Vector3Bf(0,0,0),Vector3Bf::Up);
vp.setIdentity();

render::TriangleMesh *tr =new render::TriangleMesh();
tr->loadOBJ("models/cube.obj");



    vp.setIdentity();
//    vp.multByRotation(90.0f,Vector3Bf(1.0f,1.0f,0.0f));
//    vp.multByTranslation(Vector3Bf(-3.0,0.f,0.0f));
    vp.transform();

	tr->draw(vp, rt);

    rt.drawToFile("dupa.tga");











    d_type::Bint a32;
    std::cin>>a32;

    delete tr;
    return 0;
}
