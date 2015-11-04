#ifndef FILELOADER_H
#define FILELOADER_H
#include <string>
#include <stdio.h>
#include <string.h>
#include <algorithm>    // std::find
#include "Mesh.h"
class FileLoader
{
public:
    FileLoader();
    virtual ~FileLoader();
    static Mesh*  loadMesh(std::string filename);

protected:
private:
    class Material
    {
    public:
        Material(IMaterial * _mat,std::string _name):mat(_mat),name(_name) {}
        Material() {}
        Material(std::string name):name(name) {}
        IMaterial* mat;
        std::string name;
        bool operator==(const Material & rhs) const
        {
            return this->name == rhs.name;
        }

    };
    class MaterialCounter
    {
    public:
        Material mat;
        d_type::Buint counter;
        MaterialCounter(Material _mat,d_type::Buint _counter):mat(_mat),counter(_counter) {}

        bool operator==(const MaterialCounter & rhs) const
        {
            return this->mat.name == rhs.mat.name;
        }
    };


    static Mesh* loadOBJ(std::string filename);
    static bool LoadMTL(char * mtlFilename,std::vector<Material> &materials);
};

#endif // FILELOADER_H
