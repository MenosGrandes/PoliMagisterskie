#include "TriangleMesh.h"

void render::TriangleMesh::loadOBJ(std::string filename)
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

    m_triangleCount = vertexIndices.size()/3;
    m_vertSize=temp_vertices.size()/3;

    for(int i=0; i<temp_vertices.size(); i++)
    {
        m_vertices.push_back(Vertex3Bf(temp_vertices[i],Vector3Bf(),Colour::randomColor()));

    }
    for(int i=0; i<vertexIndices.size(); i++)
    {
        m_indices.push_back(vertexIndices[i]);
    }

}

void render::TriangleMesh::draw(VertexProcessor vp,RenderTarget rt)
{

    for(int i=0; i<m_triangleCount*3; i++)
    {

        rt.triangle(
            vp.tr(m_vertices[m_indices[i]]),
            vp.tr(m_vertices[m_indices[i++]]),
            vp.tr(m_vertices[m_indices[i++]])
        );
    }


}
