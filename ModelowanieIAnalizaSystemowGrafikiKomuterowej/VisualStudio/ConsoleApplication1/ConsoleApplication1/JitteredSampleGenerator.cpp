#include "JitteredSampleGenerator.h"

JitteredSampleGenerator::JitteredSampleGenerator()
{
    //ctor
}

JitteredSampleGenerator::~JitteredSampleGenerator()
{
    //dtor
}
Vector2Bf* JitteredSampleGenerator::generateSamples(d_type::Bsize count)
{

    RandomGenFloat *r=new RandomGenFloat(0,1);

    FastSqrt a;
    d_type::Buint rows= static_cast<d_type::Buint>(a.sqrt7(count));
    Vector2Bf * result=new Vector2Bf[rows*rows];


    for(d_type::Buint x=0; x<rows; x++)
    {

        for(d_type::Buint y=0; y<rows; y++)
        {

            result[x*rows+y]=Vector2Bf(
                                 (x+r->generateRandomFloat())/rows,
                                 (y+r->generateRandomFloat())/rows
                             );

        }
    }
    delete r;
    return result;


}
