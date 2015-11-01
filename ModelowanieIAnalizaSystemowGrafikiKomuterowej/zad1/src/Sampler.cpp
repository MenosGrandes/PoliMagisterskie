#include "Sampler.h"

Sampler::Sampler(ISampleDistributor* distributor, ISampleGenerator* generator, d_type::Bint sampleCt, d_type::Bint setCt):m_sampleCount(sampleCt),m_setNdx(0),m_sampleNdx(0)
{
    for(d_type::Bsize i=0; i<setCt; ++i)
    {
        generator->generateSamples(m_sampleCount);
        std::vector<Vector2Bf> samples =generator->m_samples;


        for(d_type::Buint i=0; i<samples.size(); ++i )
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

//    std::mt19937 re(rd());
//    std::uniform_int_distribution<d_type::Bint> ui(0, m_sets.size()-1);
std::vector<Vector2Bf> s= m_sets.at(m_setNdx);

    Vector2Bf sample=s[m_sampleNdx];
    m_sampleNdx++;
    if(m_sampleNdx>=m_sampleCount)
    {
        m_sampleNdx =0;

        //m_setNdx=ui(re);

    }
    return sample;
}

Sampler::~Sampler()
{

}
