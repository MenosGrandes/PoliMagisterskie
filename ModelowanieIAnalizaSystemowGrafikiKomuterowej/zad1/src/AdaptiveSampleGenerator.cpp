#include "AdaptiveSampleGenerator.h"

AdaptiveSampleGenerator::AdaptiveSampleGenerator()
{
    //ctor
}

AdaptiveSampleGenerator::~AdaptiveSampleGenerator()
{
    //dtor
}
void AdaptiveSampleGenerator::generateSamples(d_type::Bsize count)
{
    Vector2Bf points[5] ;
    points[0] = Vector2Bf(0,0);
    points[1]= Vector2Bf(0.5,0.5);
    points[2]= Vector2Bf(0,1);
    points[3]= Vector2Bf(1,0);
    points[4]= Vector2Bf(1,1);
    adaptiveSampleGenerate(points);

}

void AdaptiveSampleGenerator::adaptiveSampleGenerate(Vector2Bf points[5])
{


}
