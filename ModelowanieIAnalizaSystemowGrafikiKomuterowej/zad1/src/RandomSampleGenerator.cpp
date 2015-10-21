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
    std::random_device rd;
    std::mt19937 gen(rd());
     std::uniform_real_distribution<d_type::Bfloat> dis(0,1);
    for(d_type::Bsize i=0;i<count;i++)
    {
    samples[i]=Vector2Bf(dis(gen),dis(gen));
    }
    return samples;
}
