#ifndef SQUARESAMPLEDISTRIBUTOR_H
#define SQUARESAMPLEDISTRIBUTOR_H
#include "ISampleDistributor.h"

class SquareSampleDistributor:public ISampleDistributor
{
public:
    SquareSampleDistributor();
    Vector2Bf mapSample(Vector2Bf sample);

};

#endif // SQUARESAMPLEDISTRIBUTOR_H
