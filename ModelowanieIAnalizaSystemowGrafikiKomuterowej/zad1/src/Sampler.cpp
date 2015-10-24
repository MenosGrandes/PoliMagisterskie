#include "Sampler.h"

Sampler::Sampler(ISampleDistributor* distributor, ISampleGenerator* generator, d_type::Bint sampleCt, d_type::Bint setCt):m_sampleCount(sampleCt)
{
    for(d_type::Bsize i=0; i<setCt; i++)
    {
        Vector2Bf * samples=generator->generateSamples(m_sampleCount);


        for(d_type::Buint i=0; i<m_sampleCount; i++)
        {
            samples[i]=distributor->mapSample(samples[i]);
        }

        m_sets.push_back(samples);

    }

    delete distributor;
    delete generator;

}

Vector2Bf Sampler::single()
{

    std::mt19937 re(rd());
    std::uniform_int_distribution<d_type::Bint> ui(0, m_sampleCount);


    Vector2Bf sample=m_sets[m_setNdx][m_sampleNdx];
    m_sampleNdx++;
    if(m_sampleNdx>=m_sampleCount)
    {
        m_sampleNdx =0;
        m_setNdx=ui(re);
        //setNdx=
    }
}

Sampler::~Sampler()
{

}
