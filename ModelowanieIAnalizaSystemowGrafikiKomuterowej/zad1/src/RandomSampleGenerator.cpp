#include "RandomSampleGenerator.h"


RandomSampleGenerator::~RandomSampleGenerator()
{
    //dtor
}

RandomSampleGenerator::RandomSampleGenerator()
{

}

Vector2Bf* RandomSampleGenerator::generateSamples(d_type::Bsize count)
{


    Vector2Bf* samples = new Vector2Bf[count];

    RandomGenFloat *r=new RandomGenFloat(0,1);

    for(d_type::Bsize i=0; i<count; i++)
    {
        samples[i]=Vector2Bf(r->generateRandomFloat(),r->generateRandomFloat());
    }

    delete r;
    return samples;
}
