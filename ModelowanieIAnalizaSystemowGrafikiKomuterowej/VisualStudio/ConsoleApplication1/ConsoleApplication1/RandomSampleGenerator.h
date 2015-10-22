#ifndef RANDOMSAMPLEGENERATOR_H
#define RANDOMSAMPLEGENERATOR_H
#include "ISampleGenerator.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
class RandomSampleGenerator: public ISampleGenerator
{
public:
    RandomSampleGenerator();
    Vector2Bf * generateSamples(d_type::Bsize count);

    virtual ~RandomSampleGenerator();
protected:
private:
};

#endif // RANDOMSAMPLEGENERATOR_H
