#ifndef JITTEREDSAMPLEGENERATOR_H
#define JITTEREDSAMPLEGENERATOR_H
#include "ISampleGenerator.h"

class JitteredSampleGenerator: public ISampleGenerator
{
    public:
        JitteredSampleGenerator();
        virtual ~JitteredSampleGenerator();
        Vector2Bf * generateSamples(d_type::Bsize count);

    protected:
    private:
};

#endif // JITTEREDSAMPLEGENERATOR_H
