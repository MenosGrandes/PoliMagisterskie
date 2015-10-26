#ifndef SAMPLER_H
#define SAMPLER_H
#include "ISampleDistributor.h"
#include "ISampleGenerator.h"
#include <vector>
#include <random>
class Sampler
{
public:
    Sampler(ISampleDistributor * distributor,ISampleGenerator * generator,d_type::Bint sampleCt,d_type::Bint setCt);
    Vector2Bf single();
    virtual ~Sampler();
    d_type::Bint getSampleCount()const
    {
        return m_sampleCount;
    }
private:
    std::vector<Vector2Bf*> m_sets;
    d_type::Bint m_sampleNdx,m_setNdx,m_sampleCount;

    std::random_device rd;


};

#endif // SAMPLER_H
