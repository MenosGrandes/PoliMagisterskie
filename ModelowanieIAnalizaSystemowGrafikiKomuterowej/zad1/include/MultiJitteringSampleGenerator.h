#ifndef MULTIJITTERINGSAMPLEGENERATOR_H
#define MULTIJITTERINGSAMPLEGENERATOR_H
#include "ISampleGenerator.h"

class MultiJitteringSampleGenerator : public ISampleGenerator
{
public:
    MultiJitteringSampleGenerator();
    virtual ~MultiJitteringSampleGenerator();
    void generateSamples(d_type::Bsize count);

private:
    std::random_device rd;

};

#endif // MULTIJITTERINGSAMPLEGENERATOR_H
