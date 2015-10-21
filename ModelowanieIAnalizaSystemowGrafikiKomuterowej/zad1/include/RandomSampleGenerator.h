#ifndef RANDOMSAMPLEGENERATOR_H
#define RANDOMSAMPLEGENERATOR_H
#include "ISampleGenerator.h"

class RandomSampleGenerator: public ISampleGenerator
{
    public:
        RandomSampleGenerator(d_type::Buint seed);
         Vector2Bf * generateSamples(d_type::Bsize count);

        virtual ~RandomSampleGenerator();
    protected:
    private:
};

#endif // RANDOMSAMPLEGENERATOR_H
