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
    FastSqrt a;
    d_type::Buint rows= static_cast<d_type::Buint>(a.sqrt7(count));


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


