#include "JitteredSampleGenerator.h"

JitteredSampleGenerator::JitteredSampleGenerator()
{
    //ctor
}

JitteredSampleGenerator::~JitteredSampleGenerator()
{
    //dtor
}
void JitteredSampleGenerator::generateSamples(d_type::Bsize count)
{

    std::mt19937 re(rd());
    std::uniform_real_distribution<d_type::Bfloat> ui(0, 1);
    FastSqrt a;
    d_type::Buint rows= static_cast<d_type::Buint>(a.sqrt7(count));


    for(d_type::Buint x=0; x<rows; x++)
    {

        for(d_type::Buint y=0; y<rows; y++)
        {

            m_samples.push_back( Vector2Bf(
                                     (x+ui(re))/rows,
                                     (y+ui(re))/rows
                                 ));

        }
    }



}
