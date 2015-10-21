#include <vector>
#include <limits>
#include <algorithm>

#ifndef TORADIANS_H
#define TORADIANS_H
class ToRadians
{
public :
    static d_type::Bfloat toRadians(d_type::Bfloat angle)
    {
        return (angle*M_PI)/180;
    }
};
#endif // TORADIANS_H
#ifndef FASTSQRT_H
#define FASTSQRT_H

struct FastSqrt
{
   float sqrt5(const float m)
{
   float i=0;
   float x1,x2;
   while( (i*i) <= m )
          i+=0.1f;
   x1=i;
   for(int j=0;j<10;j++)
   {
       x2=m;
      x2/=x1;
      x2+=x1;
      x2/=2;
      x1=x2;
   }
   return x2;
}
float sqrt7(float x)
 {
   unsigned int i = *(unsigned int*) &x;
   // adjust bias
   i  += 127 << 23;
   // approximation of square root
   i >>= 1;
   return *(float*) &i;
 }
};
#endif // COLOUR_H

#ifndef SMALLEST_H
#define SMALLEST_H
struct Smallest
{
    template <typename T>
    T min(const std::vector<T>& vec)
    {
        T smallest = std::numeric_limits<T>::max(); // Largest possible integer
        // there are a number of ways to structure this loop, this is just one
        for (int i = 0; i < vec.size(); ++i)
        {
            smallest = std::min(smallest, vec[i]);
        }
        return smallest;
    };



    template <typename T>
    T min(const T x,const T y,const T z)
    {
        T smallest = std::numeric_limits<T>::max(); // Largest possible integer
        // there are a number of ways to structure this loop, this is just one

        smallest = std::min({x,y,z} );



        return smallest;
    };



};
#endif // SMALLEST_H

#ifndef GREATEST_H
#define GREATEST_H
struct Greatest
{
    template <typename T>
    T max(const std::vector<T>& vec)
    {
        T greatest = std::numeric_limits<T>::max(); // Largest possible integer
        // there are a number of ways to structure this loop, this is just one
        for (int i = 0; i < vec.size(); ++i)
        {
            greatest = std::max(greatest, vec[i]);
        }
        return greatest;
    };



    template <typename T>
    T max(const T x,const T y,const T z)
    {
        T greatest = std::numeric_limits<T>::max(); // Largest possible integer
        // there are a number of ways to structure this loop, this is just one

        greatest = std::max({y,z, x});


        return greatest;
    };






};
#endif // GREATEST_H

