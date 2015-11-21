
#include "RenderTarget.h"
#include "VertexProcessor.h"
#include "Triangle.h"
#include "TriangleMesh.h"
int main(int argc, char **argv)
{





    Vector2Bs img_size=Vector2Bs(500,500);






    RenderTarget *file = new RenderTarget(img_size);



///NAJPIERW z -1 -1
///potem obliczanie kamery
///i potem kanoniczne

    render::TriangleMesh *mesh= new render::TriangleMesh();
    mesh->loadOBJ("models/cube.obj");

    VertexProcessor *vp= new VertexProcessor();
//
//
    vp->setIdentity();
    vp->setLookat(Vector3Bf(0,0,50),Vector3Bf(0,0,0),Vector3Bf(0,1,0));
    vp->setPerspective(45,1,Vector2Bf(0.1f,10000));
    vp->multByRotation(45,Vector3Bf(0,1,0));
    vp->transform();

    vp->addTriangle(mesh);

    for(render::TriangleFloat * tri : mesh->getTriangles())
    {
        tri->init(img_size);
        file->draw(*tri);
    }



    file->drawToFile("file.tga");



    d_type::Bint a32;
    std::cin>>a32;
    return 0;
}
