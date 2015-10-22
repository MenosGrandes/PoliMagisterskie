#ifndef DISKSAMPLEDISTRIBUTOR_H
#define DISKSAMPLEDISTRIBUTOR_H
#include "ISampleDistributor.h"

class DiskSampleDistributor : public ISampleDistributor
{
    public:
        DiskSampleDistributor();
        virtual ~DiskSampleDistributor();
         Vector2Bf MapSample(Vector2Bf sample);

};

#endif // DISKSAMPLEDISTRIBUTOR_H
