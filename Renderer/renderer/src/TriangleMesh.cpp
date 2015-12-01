#include "TriangleMesh.h"

void render::TriangleMesh::loadOBJ(std::string filename)
{


    const char * path = filename.c_str();
    printf("Loading OBJ file RENDERER %s...\n", path);

    std::vector<Vector3Bi> vertexIndices, uvIndices, normalIndices;
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
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
            temp_vertices.push_back(vertex);
        }
        else if ( strcmp( lineHeader, "vt" ) == 0 )
        {
            Vector2Bf uv;
            fscanf(file, "%f %f \n", &uv.x, &uv.y );
            uv.y = -uv.y; // Invert V coordinate since we will only use DDS texture, which are inverted. Remove if you want to use TGA or BMP loaders.
            temp_uvs.push_back(uv);
        }
        else if ( strcmp( lineHeader, "vn" ) == 0 )
        {
            Vector3Bf normal;
            fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z );
            temp_normals.push_back(normal);
        }
        else if ( strcmp( lineHeader, "f" ) == 0 )
        {
            std::string vertex1, vertex2, vertex3;
            Vector3Bi vertexIndex, uvIndex, normalIndex;
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex.x, &uvIndex.x, &normalIndex.x, &vertexIndex.y, &uvIndex.y, &normalIndex.y, &vertexIndex.z, &uvIndex.z, &normalIndex.z );
            if (matches != 9)
            {
                printf("File can't be read by our simple parser :-( Try exporting with other options\n");
            }
//            vertexIndices.push_back(vertexIndex[0]);
//            vertexIndices.push_back(vertexIndex[1]);
//            vertexIndices.push_back(vertexIndex[2]);
//            uvIndices    .push_back(uvIndex[0]);
//            uvIndices    .push_back(uvIndex[1]);
//            uvIndices    .push_back(uvIndex[2]);
//            normalIndices.push_back(normalIndex[0]);
//            normalIndices.push_back(normalIndex[1]);
//            normalIndices.push_back(normalIndex[2]);


//Obj zczyna sie od 1 a w vectore jest od 0.


            int tmp = vertexIndex.x;
            vertexIndex.x = vertexIndex.y;
            vertexIndex.y = tmp;
            vertexIndex.x -= 1;
            vertexIndex.y -= 1;
            vertexIndex.z -= 1;
            uvIndex.x -= 1;
            uvIndex.y -= 1;
            uvIndex.z -= 1;
            normalIndex.x -= 1;
            normalIndex.y -= 1;
            normalIndex.z -= 1;

            vertexIndices.push_back(vertexIndex);
            uvIndices.push_back(uvIndex);
            normalIndices.push_back(normalIndex);


        }
        else
        {
            // Probably a comment, eat up the rest of the line
            char stupidBuffer[1000000];
            fgets(stupidBuffer, 1000000, file);
        }

    }


    m_triangleCount = vertexIndices.size();
    m_vertSize=temp_vertices.size();


    for (int i = 0; i < temp_vertices.size(); i++)
    {
        m_vertices.push_back( Vertex3Bf(temp_vertices[i], Vector3Bf(),Colour::randomColor()));
    }

    for (int i = 0; i < vertexIndices.size(); i++)
    {
        m_indices.push_back(vertexIndices[i]);
    }
}

void render::TriangleMesh::draw(VertexProcessor vp,RenderTarget rt)
{

    for(int i=0; i<m_triangleCount; i++)
    {

        rt.triangle(
            vp.tr(m_vertices[m_indices[i].x]),
            vp.tr(m_vertices[m_indices[i].y]),
            vp.tr(m_vertices[m_indices[i].z])
        );
    }


}
