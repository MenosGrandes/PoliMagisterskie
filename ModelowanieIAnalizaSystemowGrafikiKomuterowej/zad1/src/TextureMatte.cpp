#include "TextureMatte.h"

TextureMatte::TextureMatte():m_diffuse(new TextureLambertian()),m_ambient(new TextureLambertian())
{    m_type=MATERIAL_TYPE::TEXTURE_MATT;
    //ctor
}

TextureMatte::~TextureMatte()
{
    //dtor
}
