#include "DiskSampleDistributor.h"

DiskSampleDistributor::DiskSampleDistributor()
{
    //ctor
}

DiskSampleDistributor::~DiskSampleDistributor()
{
    //dtor
}
Vector2Bf DiskSampleDistributor::MapSample(Vector2Bf sample)
{
    return Vector2Bf(sample.x*cosf(sample.y * M_PI),sample.x*sinf(sample.y * M_PI));
}
