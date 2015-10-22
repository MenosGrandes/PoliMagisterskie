#ifndef SAMPLER_H
#define SAMPLER_H
#include "ISampleDistributor.h"
#include "ISampleGenerator.h"
#include <list>

class Sampler
{
    public:
        Sampler(ISampleDistributor * distributor,ISampleGenerator * generator,d_type::Bint sampleCt,d_type::Bint setCt);
        Vector2Bf single();
        virtual ~Sampler();
    private:
    std::list<Vector2Bf*> sets;
    d_type::Bint sampleNdx;
    d_type::Bint setNdx;


};

#endif // SAMPLER_H
