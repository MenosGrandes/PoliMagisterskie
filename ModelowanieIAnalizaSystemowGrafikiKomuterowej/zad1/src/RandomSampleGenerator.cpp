#include "RandomSampleGenerator.h"


RandomSampleGenerator::~RandomSampleGenerator()
{
    //dtor
}

RandomSampleGenerator::RandomSampleGenerator()
{

}

void RandomSampleGenerator::generateSamples(d_type::Bsize count)
{




    std::mt19937 re(rd());
    std::uniform_real_distribution<d_type::Bfloat> ui(0, 1);

    for(d_type::Bsize i=0; i<count; i++)
    {
        m_samples.push_back(Vector2Bf(ui(re),ui(re)));
    }


}
