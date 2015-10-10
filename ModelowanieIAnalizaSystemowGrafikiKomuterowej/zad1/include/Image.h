#ifndef __IMAGE_SAVER__
#define __IMAGE_SAVER__

//includes
#include <string>
#include <fstream>
#include <iostream>
#include "Vertex2Array.h"
#include "Vertex3Array.h"
#include "RenderTarget.h"
using namespace c;
class TGAImage : public RenderTarget
{

public:

    //Constructor
    TGAImage();

    //Overridden Constructor
    TGAImage(d_type::Bshort width, d_type::Bshort height,std::string filename);

    TGAImage(Vector2Bs size,std::string filename);

    void draw();
    void draw(const Drawable& drawable);
     void draw(const Vertex2<d_type::Bfloat>*,d_type::Bsize vertexCount,PrimitiveType type);

//General getters and setters


private:

    std::string m_filename;




};


#endif
