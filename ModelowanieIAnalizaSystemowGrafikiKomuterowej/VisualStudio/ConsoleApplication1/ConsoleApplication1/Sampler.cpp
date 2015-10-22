#include "Sampler.h"

Sampler::Sampler(ISampleDistributor* distributor, ISampleGenerator* generator, d_type::Bint sampleCt, d_type::Bint setCt)
{
    for(d_type::Bsize i=0; i<setCt; i++)
    {

    }



}

Vector2Bf Sampler::single()
{
	/*
    Vector2Bf sample=sets[setNdx];
    sampleNdx++;
    if(sampleNdx>=sets[setNdx].size())
    {
        sampleNdx =0;
        setNdx=
    }
	*/
	return Vector2Bf();
}

Sampler::~Sampler()
{

}
