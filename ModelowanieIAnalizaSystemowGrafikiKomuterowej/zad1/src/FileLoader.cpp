#include "FileLoader.h"

FileLoader::FileLoader()
{
    //ctor
}

FileLoader::~FileLoader()
{
    //dtor
}
Mesh * FileLoader::loadMesh(std::string filename)
{
    std::string extension="";
    size_t i = filename.rfind('.', filename.length());
    if (i != std::string::npos)
    {
        extension=(filename.substr(i+1, filename.length() - i));
    }

    if(extension == "obj")
    {
        return loadOBJ(filename);

    }
    else if(extension == "fbx")
    {

    }
    else if(extension == "geo")
    {

    }
    std::cout<<extension<<"\n";
}
Mesh* FileLoader::loadOBJ(std::string filename)
{
    Mesh * mesh = new Mesh();

    const char * path = filename.c_str();
    std::vector<Material> materials;
    std::vector<MaterialCounter> materialCounter;
    printf("Loading OBJ file %s...\n", path);

    std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
    std::vector<Vector3Bf> temp_vertices;
    std::vector<Vector2Bf> temp_uvs;
    std::vector<Vector3Bf> temp_normals;
    std::vector<Material>::iterator materialIterator=materials.begin();
    FILE * file = fopen(path, "r");
    if( file == NULL )
    {
        printf("Impossible to open the file ! Are you in the right path ? See Tutorial 1 for details\n");
        getchar();
        return nullptr;
    }

    while( 1 )
    {

        char lineHeader[128];
        // read the first word of the line
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break; // EOF = End Of File. Quit the loop.

        // else : parse lineHeader
        if ( strcmp( lineHeader, "mtllib" ) == 0 )
        {

            char c[100];
            fscanf(file,"%s",c);
            LoadMTL(c,materials);
            std::cout<<materials.size()<<"\n\n";
        }
        else if ( strcmp( lineHeader, "v" ) == 0 )
        {
            Vector3Bf vertex;
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
            temp_vertices.push_back(vertex);
        }
        else if ( strcmp( lineHeader, "usemtl" ) == 0 )
        {
            char c[100];
            fscanf(file,"%s",c);
            std::string name(c);

            std::vector<Material>::iterator i=std::find(materials.begin(),materials.end(),Material(name));
            if(i!=materials.end())
            {
                materialIterator=i;
                materialCounter.push_back(MaterialCounter(*i,0));


            }
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
                return nullptr;
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
            if(!materials.empty())
            {
                materialCounter.at(materialCounter.size()-1).counter++;

            }
        }
        else
        {
            // Probably a comment, eat up the rest of the line
            char stupidBuffer[1000000];
            fgets(stupidBuffer, 1000000, file);
        }

    }
    int counter=0;
    std::vector<Vertex3Bf> vertices;
    // For each vertex of each triangle

    // Material triMat=materials.at(0);



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
        vertices.push_back(Vertex3Bf(vertex,uv,normal));

        if(vertices.size() == 3)
        {
            Material material;
            if(!materials.empty() && !materialCounter.empty())
            {
                material=materialCounter.front().mat;
                --materialCounter.front().counter;
                if(materialCounter.front().counter==0)
                {
                    materialCounter.erase(materialCounter.begin());
                }
                RayTriangle* tri=new RayTriangle(vertices[0],vertices[1],vertices[2]);
                tri->setMaterial(material.mat);
               mesh->m_triangles.push_back(tri);

            }
            else
            {
                std::cout<<"asdsad";
                mesh->m_triangles.push_back(new RayTriangle(vertices[0],vertices[1],vertices[2]));//,new PerfectDifuse(Colour::randomColor())));

            }
            vertices.clear();
        }
        counter++;

    }
//    std::cout<<mesh->m_triangles.size()<<"\n";
//    std::cout<<materials.size()<<"\n";
//
    mesh->createBoundingBox();
    return mesh;
}

bool FileLoader::LoadMTL(char* mtlFilename,std::vector<Material> &materials)
{

    char folder[7];
    strcpy(folder,"models/");
    strncat(folder,mtlFilename,8);
    printf("Loading MTL file %s...\n", folder);

    FILE * file = fopen(folder, "r");
    if( file == NULL )
    {
        printf("Impossible to open the file ! Are you in the right path ? See Tutorial 1 for details\n");
        getchar();
        return nullptr;
    }

    while( 1 )
    {

        char lineHeader[128];
        // read the first word of the line
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break; // EOF = End Of File. Quit the loop.

        // else : parse lineHeader
        if ( strcmp( lineHeader, "newmtl" ) == 0 )
        {
            char c[100];
            fscanf(file,"%s",c);
            std::string d(c);
            Material material=Material(new IMaterial(),d);

            materials.push_back(material);
        }
        else if(strcmp( lineHeader, "Ka" ) == 0)
        {
            Vector3Bf c;
            fscanf(file, "%f %f %f\n", &c.x, &c.y,&c.z );
            Colour colour;
            colour.r=c.x*255;
            colour.g=c.y*255;
            colour.b=c.z*255;

            materials.at(materials.size()-1).mat->setColor(colour);
        }
        else
        {
            // Probably a comment, eat up the rest of the line
            char stupidBuffer[1000000];
            fgets(stupidBuffer, 1000000, file);
        }

    }
//    for(Material mat : materials)
//    {
//        std::cout<<(int)mat.mat->getColor().r<<" "<<(int)mat.mat->getColor().g<<" "<<(int)mat.mat->getColor().b<<" "<<mat.name<<"\n";
//    }
}

