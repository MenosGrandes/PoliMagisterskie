#ifndef FILELOADER_H
#define FILELOADER_H
#include "Mesh.h"
#include <string>
#include <stdio.h>
#include <string.h>
class FileLoader
{
    public:
        FileLoader();
        virtual ~FileLoader();
       static  Mesh &loadMesh(std::string filename);

    protected:
    private:
static bool loadOBJ(std::string filename,Mesh &m);

};

#endif // FILELOADER_H
