#include <limits>
#include <algorithm>
#include <cmath>
#include <iostream>

#define M_PI 3.14159265
#define F_EPSILON 0.000001
namespace d_type
{
typedef bool	        BBool;   /*1-byte boolean*/
typedef signed char	    Bbyte;		/* 1-byte signed */
typedef short		    Bshort;	/* 2-byte signed */
typedef int		        Bint;		/* 4-byte signed */
typedef unsigned char   Bubyte;	/* 1-byte unsigned */
typedef unsigned short	Bushort;	/* 2-byte unsigned */
typedef unsigned int	Buint;		/* 4-byte unsigned */
typedef float		    Bfloat;	/* single precision float */
typedef double		    Bdouble;	/* double precision float */
typedef size_t          Bsize;
}






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
