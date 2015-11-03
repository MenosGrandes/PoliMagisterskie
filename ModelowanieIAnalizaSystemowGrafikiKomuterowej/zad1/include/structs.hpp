#include <limits>
#include <algorithm>
#include <cmath>
#include <iostream>
/** \def M_PI
\brief Mathematic PI
*/
#define M_PI 3.14159265

#define F_EPSILON 0.000001


#define ENABLE_AA
#define ENABLE_LIGHT
/**
 *  Namespace to group wrapped standard types
 *
 *
 *
 */
namespace d_type
{
/** 1-byte boolean*/
typedef bool	        BBool;
/** 1-byte signed */
typedef signed char	    Bbyte;
/** 2-byte signed */
typedef short		    Bshort;
/** 4-byte signed */
typedef int		        Bint;
/** 1-byte unsigned */
typedef unsigned char   Bubyte;
/** 2-byte unsigned */
typedef unsigned short	Bushort;
/** 4-byte unsigned */
typedef unsigned int	Buint;
/**  single precision float */
typedef float		    Bfloat;
/** double precision float */
typedef double		    Bdouble;
/** size_t wrapper*/
typedef size_t          Bsize;
typedef char          Bchar;

};







