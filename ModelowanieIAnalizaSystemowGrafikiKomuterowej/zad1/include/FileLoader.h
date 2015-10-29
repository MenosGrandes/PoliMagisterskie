#ifndef FILELOADER_H
#define FILELOADER_H
#include "Mesh.h"
#include <string>
#include <stdio.h>
#include <string.h>
#include "PerfectDifuse.h"
class FileLoader
{
public:
    FileLoader();
    virtual ~FileLoader();
    static Mesh*  loadMesh(std::string filename);

protected:
private:
    static Mesh* loadOBJ(std::string filename);
    struct MaterialForTriangle
    {
        d_type::Bchar materialName[13];
        d_type::Buint triangleSize;
    };
};

#endif // FILELOADER_H
