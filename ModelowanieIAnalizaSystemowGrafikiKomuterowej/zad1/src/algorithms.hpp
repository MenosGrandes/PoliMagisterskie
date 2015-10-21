#include <vector>
#include <limits>
#include <algorithm>


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


