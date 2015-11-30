#ifndef TRIANGLEMESH_H
#define TRIANGLEMESH_H
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include "Vertex3.h"
#include "VertexProcessor.h"
#include "RenderTarget.h"
using namespace d_type;
namespace render
{
class TriangleMesh
{
public:
    TriangleMesh() {}
    virtual ~TriangleMesh() {}
    void draw(VertexProcessor vp,RenderTarget rt);

 void loadOBJ(std::string filename);


    int m_vertSize,m_triangleCount;
    std::vector<Vertex3Bf> m_vertices;
    std::vector<d_type::Bint> m_indices;

};
}
#endif // TRIANGLEMESH_H
