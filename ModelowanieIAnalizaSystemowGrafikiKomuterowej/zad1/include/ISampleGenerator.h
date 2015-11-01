#ifndef ISAMPLEGENERATOR_H
#define ISAMPLEGENERATOR_H
#include "Vector2.h"
#include "../src/algorithms.hpp"
#include <vector>
class ISampleGenerator
{
public:
    virtual void generateSamples(d_type::Bsize count)=0;
    std::vector<Vector2Bf> m_samples;
};

#endif // ISAMPLEGENERATOR_H
