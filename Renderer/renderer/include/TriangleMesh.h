#ifndef TRIANGLEMESH_H
#define TRIANGLEMESH_H
#include "Triangle.h"
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <algorithm>    // std::find
using namespace d_type;
namespace render
{
class TriangleMesh
{
public:
    TriangleMesh() {}
    virtual ~TriangleMesh() {}

    std::vector<Triangle *> getTriangles()
    {
        return m_triangles;
    }
    void loadOBJ(std::string filename)
    {


        const char * path = filename.c_str();
        printf("Loading OBJ file RENDERER %s...\n", path);

        std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
        std::vector<Vector3Bf> temp_vertices;
        std::vector<Vector2Bf> temp_uvs;
        std::vector<Vector3Bf> temp_normals;
        FILE * file = fopen(path, "r");
        if( file == NULL )
        {
            printf("Impossible to open the file ! Are you in the right path ? See Tutorial 1 for details\n");

        }

        while( 1 )
        {

            char lineHeader[128];
            // read the first word of the line
            int res = fscanf(file, "%s", lineHeader);
            if (res == EOF)
            {
                break;   // EOF = End Of File. Quit the loop.
            }

            if ( strcmp( lineHeader, "v" ) == 0 )
            {
                Vector3Bf vertex;
                fscanf(file, "%lf %lf %lf\n", &vertex.x, &vertex.y, &vertex.z );
                temp_vertices.push_back(vertex);
            }
            else if ( strcmp( lineHeader, "vt" ) == 0 )
            {
                Vector2Bf uv;
                fscanf(file, "%lf %lf \n", &uv.x, &uv.y );
                uv.y = -uv.y; // Invert V coordinate since we will only use DDS texture, which are inverted. Remove if you want to use TGA or BMP loaders.
                temp_uvs.push_back(uv);
            }
            else if ( strcmp( lineHeader, "vn" ) == 0 )
            {
                Vector3Bf normal;
                fscanf(file, "%lf %lf %lf\n", &normal.x, &normal.y, &normal.z );
                temp_normals.push_back(normal);
            }
            else if ( strcmp( lineHeader, "f" ) == 0 )
            {
                std::string vertex1, vertex2, vertex3;
                unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
                int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
                if (matches != 9)
                {
                    printf("File can't be read by our simple parser :-( Try exporting with other options\n");
                }
                vertexIndices.push_back(vertexIndex[0]);
                vertexIndices.push_back(vertexIndex[1]);
                vertexIndices.push_back(vertexIndex[2]);
                uvIndices    .push_back(uvIndex[0]);
                uvIndices    .push_back(uvIndex[1]);
                uvIndices    .push_back(uvIndex[2]);
                normalIndices.push_back(normalIndex[0]);
                normalIndices.push_back(normalIndex[1]);
                normalIndices.push_back(normalIndex[2]);

            }
            else
            {
                // Probably a comment, eat up the rest of the line
                char stupidBuffer[1000000];
                fgets(stupidBuffer, 1000000, file);
            }

        }
        int counter=0;
        std::vector<Vector3Bf> vertices;
        // For each vertex of each triangle

//     Material triMat=materials.at(0);



        for( unsigned int i=0; i<vertexIndices.size(); i++ )
        {

            // std::cout<<materials.size()<<"\n";
            unsigned int vertexIndex = vertexIndices[i];
            unsigned int uvIndex = uvIndices[i];
            unsigned int normalIndex = normalIndices[i];

            // Get the attributes thanks to the index
            Vector3Bf vertex = temp_vertices[ vertexIndex-1 ];
            Vector2Bf uv = temp_uvs[ uvIndex-1 ];
            Vector3Bf normal = temp_normals[ normalIndex-1 ];

            // Put the attributes in buffers
            vertices.push_back(vertex);

            if(vertices.size() == 3)
            {


                m_triangles.push_back(new render::Triangle(vertices[0],vertices[1],vertices[2]));//,new PerfectDifuse(Colour::randomColor())));
                vertices.clear();
            }
            counter++;

        }
    }
private:
    std::vector<Triangle *> m_triangles;
};
}
#endif // TRIANGLEMESH_H
