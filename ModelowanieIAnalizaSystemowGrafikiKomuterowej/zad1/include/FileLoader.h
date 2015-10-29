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
    struct Material
    {
        IMaterial* mat;
        std::string name;
    };
    static Mesh* loadOBJ(std::string filename);
    static bool LoadMTL(char * mtlFilename,std::vector<IMaterial*> &materials);
};

#endif // FILELOADER_H
