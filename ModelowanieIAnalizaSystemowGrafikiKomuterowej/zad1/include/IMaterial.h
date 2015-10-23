#ifndef IMATERIAL_H
#define IMATERIAL_H
#include "Colour.h"

class IMaterial
{
    public:
        IMaterial(Colour material);
        virtual ~IMaterial();
        Colour getColor()
        {
            return m_color;
        }
    protected:
    Colour m_color;

};

#endif // IMATERIAL_H
