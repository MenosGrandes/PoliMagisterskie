#ifndef JITTEREDSAMPLEGENERATOR_H
#define JITTEREDSAMPLEGENERATOR_H
#include "ISampleGenerator.h"
#include <random>

class JitteredSampleGenerator: public ISampleGenerator
{
public:
    JitteredSampleGenerator();
    virtual ~JitteredSampleGenerator();
    Vector2Bf * generateSamples(d_type::Bsize count);

protected:
private:
    std::random_device rd;

};

#endif // JITTEREDSAMPLEGENERATOR_H
