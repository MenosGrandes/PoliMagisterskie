#include "RandomSampleGenerator.h"


RandomSampleGenerator::~RandomSampleGenerator()
{
    //dtor
}


Vector2Bf* RandomSampleGenerator::generateSamples(d_type::Bsize count)
{
    Vector2Bf* samples = new Vector2Bf[count];
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1, 2);
    for (int n = 0; n < 10; ++n) {
        std::cout << dis(gen) << ' ';
    }
    std::cout << '\n';
}
