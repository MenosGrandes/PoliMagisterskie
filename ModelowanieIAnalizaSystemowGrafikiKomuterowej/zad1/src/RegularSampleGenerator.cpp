#include "RegularSampleGenerator.h"

RegularSampleGenerator::RegularSampleGenerator()
{
    //ctor
}

RegularSampleGenerator::~RegularSampleGenerator()
{
    //dtor
}

void RegularSampleGenerator::generateSamples(d_type::Bsize count)
{
    d_type::Buint rows= static_cast<d_type::Buint>(sqrt(count));

    assert(count%2==0 && "Sample count must be 2^x!");
    for(d_type::Buint x=0; x<rows; x++)
    {

        for(d_type::Buint y=0; y<rows; y++)
        {

            m_samples.push_back(Vector2Bf(
                                    (x+0.5f)/rows,
                                    (y+0.5f)/rows
                                ));

        }
    }




}


