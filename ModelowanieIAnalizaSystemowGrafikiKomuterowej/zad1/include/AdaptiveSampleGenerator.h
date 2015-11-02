#ifndef ADAPTIVESAMPLEGENERATOR_H
#define ADAPTIVESAMPLEGENERATOR_H
#include "ISampleGenerator.h"
#include "Colour.h"
class AdaptiveSampleGenerator : public ISampleGenerator
{
    public:
        AdaptiveSampleGenerator();
        virtual ~AdaptiveSampleGenerator();
        void setColour(const Colour &c)
        {
            this->m_colour=c;
        }
        Colour getColour()const
        {
            return m_colour;
        }
         void setMaxIter(const d_type::Buint &iter)
        {
            this->m_maxIter=iter;
        }
        d_type::Buint getMaxIter()const
        {
            return m_maxIter;
        }
        void generateSamples(d_type::Bsize count)=0;
        void adaptiveSampleGenerate(Vector2Bf points[5]);
    private:
        Colour m_colour;
        d_type::Buint m_maxIter;
};

#endif // ADAPTIVESAMPLEGENERATOR_H
