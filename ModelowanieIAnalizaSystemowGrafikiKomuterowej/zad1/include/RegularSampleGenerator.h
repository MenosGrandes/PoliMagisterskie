#ifndef REGULARSAMPLEGENERATOR_H
#define REGULARSAMPLEGENERATOR_H
#include "ISampleGenerator.h"



class RegularSampleGenerator : public ISampleGenerator
{
    public:
        RegularSampleGenerator();
        virtual ~RegularSampleGenerator();
        Vector2Bf * generateSamples(d_type::Bsize count);

    protected:
    private:
};

#endif // REGULARSAMPLEGENERATOR_H
