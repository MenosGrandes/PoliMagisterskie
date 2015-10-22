#ifndef ISAMPLEGENERATOR_H
#define ISAMPLEGENERATOR_H
#include "Vector2.h"
#include "algorithms.hpp"
class ISampleGenerator
{
public:
    virtual Vector2Bf * generateSamples(d_type::Bsize count)=0;

};

#endif // ISAMPLEGENERATOR_H
