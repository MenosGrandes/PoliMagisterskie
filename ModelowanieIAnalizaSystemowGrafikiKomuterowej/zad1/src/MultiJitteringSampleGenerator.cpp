#include "MultiJitteringSampleGenerator.h"

MultiJitteringSampleGenerator::MultiJitteringSampleGenerator()
{
    //ctor
}

MultiJitteringSampleGenerator::~MultiJitteringSampleGenerator()
{
    //dtor
}
void MultiJitteringSampleGenerator::generateSamples(d_type::Bsize count)
{
    std::mt19937 re(rd());
    std::uniform_real_distribution<d_type::Bfloat> ui(0, 1);

    FastSqrt a;
    d_type::Buint rows= static_cast<d_type::Buint>(a.sqrt7(count));

    d_type::Bfloat cellwidth=1/(rows*rows);
    for(d_type::Buint x=0; x<rows; x++)
    {

        for(d_type::Buint y=0; y<rows; y++)
        {

            m_samples.push_back(Vector2Bf(
                                    (x*rows*cellwidth + y*cellwidth +ui(re)),
                                    (y*rows*cellwidth + x*cellwidth +ui(re))
                                ));

        }
    }

    for(d_type::Buint x=0; x<rows; x++)
    {

        for(d_type::Buint y=0; y<rows; y++)
        {

            d_type::Bfloat t;
            d_type::Bint k;
            std::uniform_int_distribution<d_type::Bint> rand_i(y, rows-1);
            k=rand_i(re);
            t=m_samples[x*rows+y].x;
            m_samples[x*rows+y].x=m_samples[x*rows+k].x;
            m_samples[x*rows+k].x=t;

        }
    }

    for(d_type::Buint x=0; x<rows; x++)
    {

        for(d_type::Buint y=0; y<rows; y++)
        {

            d_type::Bfloat t;
            d_type::Bint k;
            std::uniform_int_distribution<d_type::Bint> rand_i(y, rows-1);
            k=rand_i(re);
            t=m_samples[y*rows+x].y;
            m_samples[y*rows+x].y=m_samples[k*rows+x].y;
            m_samples[k*rows+x].y=t;

        }
    }


}
