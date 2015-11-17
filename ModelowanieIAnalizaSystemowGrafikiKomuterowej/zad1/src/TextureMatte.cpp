#include "TextureMatte.h"

TextureMatte::TextureMatte():m_diffuse(new TextureLambertian()),m_ambient(new TextureLambertian())
{
    //ctor
}

TextureMatte::~TextureMatte()
{
    //dtor
}
