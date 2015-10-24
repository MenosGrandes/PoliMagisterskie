#ifndef ISAMPLEDISTRIBUTOR_H
#define ISAMPLEDISTRIBUTOR_H
#include "Vector2.h"

class ISampleDistributor
{
public:
    ISampleDistributor();
    virtual Vector2Bf mapSample(Vector2Bf sample)=0;
};

#endif // ISAMPLEDISTRIBUTOR_H
