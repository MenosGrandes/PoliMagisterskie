#ifndef RANDOMSAMPLEGENERATOR_H
#define RANDOMSAMPLEGENERATOR_H
#include "ISampleGenerator.h"
#include <random>
class RandomSampleGenerator: public ISampleGenerator
{
public:
    RandomSampleGenerator();
    void generateSamples(d_type::Bsize count);

    virtual ~RandomSampleGenerator();
protected:
private:
    std::random_device rd;

};

#endif // RANDOMSAMPLEGENERATOR_H
