#include <limits>
#include <algorithm>
#include <cmath>
#include <iostream>
/** \def M_PI
\brief Mathematic PI
*/

#define M_PI 3.1415926535897932384
#define TWO_PI 6.2831853071795864769
#define INV_PI 0.3183098861837906715
#define INV_TWO_PI 0.1591549430918953358
#define    PI_ON_180       0.0174532925199432957;

#define F_EPSILON 0.001



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
typedef double		    Bfloat;
/** size_t wrapper*/
typedef size_t          Bsize;
typedef char          Bchar;

};







