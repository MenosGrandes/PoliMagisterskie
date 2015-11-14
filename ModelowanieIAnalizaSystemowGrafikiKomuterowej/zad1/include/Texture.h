#ifndef TEXTURE_H
#define TEXTURE_H
#include "Colour.h"
#include "Info.h"
class Texture
{
public:
    Texture();
    virtual ~Texture();
    virtual Colour getColour(const Info&info )const=0;
protected:
private:
};

#endif // TEXTURE_H
