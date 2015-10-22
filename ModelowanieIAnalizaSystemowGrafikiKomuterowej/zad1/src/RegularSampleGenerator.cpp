#include "RegularSampleGenerator.h"

RegularSampleGenerator::RegularSampleGenerator()
{
    //ctor
}

RegularSampleGenerator::~RegularSampleGenerator()
{
    //dtor
}

Vector2Bf *RegularSampleGenerator::generateSamples(d_type::Bsize count)
{
    FastSqrt a;
    d_type::Buint rows= static_cast<d_type::Buint>(a.sqrt7(count));
    Vector2Bf * result=new Vector2Bf[rows*rows];


    for(d_type::Buint x=0; x<rows; x++)
    {

        for(d_type::Buint y=0; y<rows; y++)
        {

            result[x*rows+y]=Vector2Bf(
                                 (x+0.5f)/rows,
                                 (y+0.5f)/rows
                             );

        }
    }
    return result;




}


