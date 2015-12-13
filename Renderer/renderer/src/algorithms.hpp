#include <vector>
#include <limits>
#include <algorithm>
#include <random>



#ifndef MINMAX_HPP
#define MINMAX_HPP
template<typename T>
inline T Max(T left , T right)
{
return left > right ? left : right;
}

template<typename T>
inline T Min(T left, T right)
{
return left < right ? left : right;
}


#endif // MINMAX_HPP
