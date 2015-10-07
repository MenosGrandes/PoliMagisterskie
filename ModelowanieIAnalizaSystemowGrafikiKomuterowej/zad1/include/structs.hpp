namespace d_type
{
typedef bool	        BBool;   /*1-byte boolean*/
typedef signed char	    Bbyte;		/* 1-byte signed */
typedef short		    Bshort;	/* 2-byte signed */
typedef int		        Bint;		/* 4-byte signed */
typedef unsigned char   Bubyte;	/* 1-byte unsigned */
typedef unsigned short	Bushort;	/* 2-byte unsigned */
typedef unsigned int	Buint;		/* 4-byte unsigned */
typedef size_t		    Bsize;	/* size_t */
typedef float		    Bfloat;	/* single precision float */
typedef double		    Bdouble;	/* double precision float */

//####################################################//
template <typename T>
class Vector3
{
public :
    Vector3();
    Vector3(T X, T Y, T Z);
    template <typename U>
    explicit Vector3(const Vector3<U>& vector);
    // Member data
    T x;
    T y;
    T z;
};

template <typename T>
Vector3<T> operator -(const Vector3<T>& left);

template <typename T>
Vector3<T>& operator +=(Vector3<T>& left, const Vector3<T>& right);

template <typename T>
Vector3<T>& operator -=(Vector3<T>& left, const Vector3<T>& right);

template <typename T>
Vector3<T> operator +(const Vector3<T>& left, const Vector3<T>& right);

template <typename T>
Vector3<T> operator -(const Vector3<T>& left, const Vector3<T>& right);

template <typename T>
Vector3<T> operator *(const Vector3<T>& left, T right);

template <typename T>
Vector3<T> operator *(T left, const Vector3<T>& right);

template <typename T>
Vector3<T>& operator *=(Vector3<T>& left, T right);

template <typename T>
Vector3<T> operator /(const Vector3<T>& left, T right);

template <typename T>
Vector3<T>& operator /=(Vector3<T>& left, T right);

template <typename T>
bool operator ==(const Vector3<T>& left, const Vector3<T>& right);

template <typename T>
bool operator !=(const Vector3<T>& left, const Vector3<T>& right);

template <typename T>
inline Vector3<T>::Vector3() : x(0), y(0), z(0) {}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector3<T>::Vector3(T X, T Y, T Z) :x(X),y(Y),z(Z) {}


////////////////////////////////////////////////////////////
template <typename T>
template <typename U>
inline Vector3<T>::Vector3(const Vector3<U>& vector) :x(static_cast<T>(vector.x)),y(static_cast<T>(vector.y)),z(static_cast<T>(vector.z)) {}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector3<T> operator -(const Vector3<T>& left)
{
    return Vector3<T>(-left.x, -left.y, -left.z);
}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector3<T>& operator +=(Vector3<T>& left, const Vector3<T>& right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;

    return left;
}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector3<T>& operator -=(Vector3<T>& left, const Vector3<T>& right)
{
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;

    return left;
}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector3<T> operator +(const Vector3<T>& left, const Vector3<T>& right)
{
    return Vector3<T>(left.x + right.x, left.y + right.y, left.z + right.z);
}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector3<T> operator -(const Vector3<T>& left, const Vector3<T>& right)
{
    return Vector3<T>(left.x - right.x, left.y - right.y, left.z - right.z);
}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector3<T> operator *(const Vector3<T>& left, T right)
{
    return Vector3<T>(left.x * right, left.y * right, left.z * right);
}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector3<T> operator *(T left, const Vector3<T>& right)
{
    return Vector3<T>(right.x * left, right.y * left, right.z * left);
}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector3<T>& operator *=(Vector3<T>& left, T right)
{
    left.x *= right;
    left.y *= right;
    left.z *= right;

    return left;
}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector3<T> operator /(const Vector3<T>& left, T right)
{
    return Vector3<T>(left.x / right, left.y / right, left.z / right);
}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector3<T>& operator /=(Vector3<T>& left, T right)
{
    left.x /= right;
    left.y /= right;
    left.z /= right;

    return left;
}


////////////////////////////////////////////////////////////
template <typename T>
inline bool operator ==(const Vector3<T>& left, const Vector3<T>& right)
{
    return (left.x == right.x) && (left.y == right.y) && (left.z == right.z);
}


////////////////////////////////////////////////////////////
template <typename T>
inline bool operator !=(const Vector3<T>& left, const Vector3<T>& right)
{
    return (left.x != right.x) || (left.y != right.y) || (left.z != right.z);
}
// Define the most common types
typedef Vector3<Bint>   Vector3Bi;
typedef Vector3<Bfloat> Vector3Bf;
typedef Vector3<BBool> Vector3Bb;
typedef Vector3<Bdouble> Vector3Bd;
//####################################################//

template <typename T>
class Vector3Pair
{
public :
    Vector3Pair();
    Vector3Pair(Vector3<T> x,Vector3<T> y);

    // Member data
    Vector3<T> x;
    Vector3<T> y;
};

template <typename T>
inline Vector3Pair<T>::Vector3Pair() : x(Vector3<T>()), y(Vector3<T>()) {}

template <typename T>
inline Vector3Pair<T>::Vector3Pair(Vector3<T> X, Vector3<T> Y) : x(X), y(Y) {}

typedef Vector3Pair<Bdouble> Vector3PairBd;
typedef Vector3Pair<Bfloat> Vector3PairBf;
typedef Vector3Pair<Buint> Vector3PairBui;
typedef Vector3Pair<Bint> Vector3PairBi;

/*USAGE
    Vector3PairBd d_pair=Vector3PairBd(Vector3Bd(10,10,10),Vector3Bd(10,10,10));//= Vector3Pair<double>(Vector3Bd(100,100,100),Vector3Bd(100,100,100));

*/
//####################################################//




template <typename T>
class Vector2
{
public:

    Vector2();
    Vector2(T X, T Y);
    template <typename U>
    explicit Vector2(const Vector2<U>& vector);

    T x; ///< X coordinate of the vector
    T y; ///< Y coordinate of the vector
};


template <typename T>
Vector2<T> operator -(const Vector2<T>& right);


template <typename T>
Vector2<T>& operator +=(Vector2<T>& left, const Vector2<T>& right);


template <typename T>
Vector2<T>& operator -=(Vector2<T>& left, const Vector2<T>& right);


template <typename T>
Vector2<T> operator +(const Vector2<T>& left, const Vector2<T>& right);

template <typename T>
Vector2<T> operator -(const Vector2<T>& left, const Vector2<T>& right);


template <typename T>
Vector2<T> operator *(const Vector2<T>& left, T right);

template <typename T>
Vector2<T> operator *(T left, const Vector2<T>& right);


template <typename T>
Vector2<T>& operator *=(Vector2<T>& left, T right);


template <typename T>
Vector2<T> operator /(const Vector2<T>& left, T right);


template <typename T>
Vector2<T>& operator /=(Vector2<T>& left, T right);


template <typename T>
bool operator ==(const Vector2<T>& left, const Vector2<T>& right);


template <typename T>
bool operator !=(const Vector2<T>& left, const Vector2<T>& right);


template <typename T>
inline Vector2<T>::Vector2() :x(0),y(0) {}



template <typename T>
inline Vector2<T>::Vector2(T X, T Y) : x(X), y(Y) {}



template <typename T>
template <typename U>
inline Vector2<T>::Vector2(const Vector2<U>& vector) :
    x(static_cast<T>(vector.x)),
    y(static_cast<T>(vector.y))
{
}



template <typename T>
inline Vector2<T> operator -(const Vector2<T>& right)
{
    return Vector2<T>(-right.x, -right.y);
}



template <typename T>
inline Vector2<T>& operator +=(Vector2<T>& left, const Vector2<T>& right)
{
    left.x += right.x;
    left.y += right.y;

    return left;
}



template <typename T>
inline Vector2<T>& operator -=(Vector2<T>& left, const Vector2<T>& right)
{
    left.x -= right.x;
    left.y -= right.y;

    return left;
}



template <typename T>
inline Vector2<T> operator +(const Vector2<T>& left, const Vector2<T>& right)
{
    return Vector2<T>(left.x + right.x, left.y + right.y);
}



template <typename T>
inline Vector2<T> operator -(const Vector2<T>& left, const Vector2<T>& right)
{
    return Vector2<T>(left.x - right.x, left.y - right.y);
}



template <typename T>
inline Vector2<T> operator *(const Vector2<T>& left, T right)
{
    return Vector2<T>(left.x * right, left.y * right);
}



template <typename T>
inline Vector2<T> operator *(T left, const Vector2<T>& right)
{
    return Vector2<T>(right.x * left, right.y * left);
}



template <typename T>
inline Vector2<T>& operator *=(Vector2<T>& left, T right)
{
    left.x *= right;
    left.y *= right;

    return left;
}



template <typename T>
inline Vector2<T> operator /(const Vector2<T>& left, T right)
{
    return Vector2<T>(left.x / right, left.y / right);
}



template <typename T>
inline Vector2<T>& operator /=(Vector2<T>& left, T right)
{
    left.x /= right;
    left.y /= right;

    return left;
}



template <typename T>
inline bool operator ==(const Vector2<T>& left, const Vector2<T>& right)
{
    return (left.x == right.x) && (left.y == right.y);
}



template <typename T>
inline bool operator !=(const Vector2<T>& left, const Vector2<T>& right)
{
    return (left.x != right.x) || (left.y != right.y);
}

// Define the most common types
typedef Vector2<Bint>          Vector2Bi;
typedef Vector2<Buint>         Vector2Bui;
typedef Vector2<Bfloat>        Vector2Bf;
typedef Vector2<Bdouble>        Vector2Bd;
typedef Vector2<BBool> Vector2Bb;
typedef Vector2<Bshort> Vector2Bs;
//####################################################//




namespace c
{
class Colour
{
public :
    Bubyte r,g,b,a;
    Colour(Bubyte _r,Bubyte _g,Bubyte _b,Bubyte _a):r(_r),g(_g),b(_b),a(_a)
    {
    }
    Colour():r(255),g(255),b(255),a(255) {};

};

static const Colour White=Colour(Bubyte(255),Bubyte(255),Bubyte(255),Bubyte(255));
static const Colour Black=Colour(Bubyte(0),Bubyte(0),Bubyte(0),Bubyte(255));
static const Colour Red=Colour(Bubyte(255),Bubyte(0),Bubyte(0),Bubyte(255));
static const Colour Blue=Colour(Bubyte(0),Bubyte(0),Bubyte(255),Bubyte(255));
static const Colour Green=Colour(Bubyte(0),Bubyte(255),Bubyte(0),Bubyte(255));
static const Colour Yellow=Colour(Bubyte(255),Bubyte(255),Bubyte(0),Bubyte(255));

}
//namespace eq
//{
//    class HalfSpace
//    {
//     HalfSpace(Vector2Bf first)
//    }
//}
} // namespace d_type




