#ifndef FRAGMENT_H
#define FRAGMENT_H
#include "Vertex3.h"

class Fragment : public Vertex3Bf
{
    public:
        Fragment();
        virtual ~Fragment();
        Vector3Bf m_negativePosToView;
};

#endif // FRAGMENT_H
