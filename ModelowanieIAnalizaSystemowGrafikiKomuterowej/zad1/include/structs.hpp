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

//#############################################################



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
inline Vector2<T> operator *(const Vector2<T>& left, const Vector2<T>& right)
{
    return Vector2<T>(right.x * left.x, right.y * left.y);
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

template <typename T>
class Vector4
{
public:

    Vector4();
    Vector4(T X, T Y,T Z,T W);
    template <typename U>
    explicit Vector4(const Vector4<U>& vector);

    T x; ///< X coordinate of the vector
    T y; ///< Y coordinate of the vector
    T z; ///< Z coordinate of the vector
    T w; ///< W coordinate of the vector / depth
};


template <typename T>
inline Vector4<T>::Vector4() :x(0),y(0),z(0),w(0) {}



template <typename T>
inline Vector4<T>::Vector4(T X, T Y,T Z, T W) : x(X), y(Y),z(Z), w(W) {}



template <typename T>
template <typename U>
inline Vector4<T>::Vector4(const Vector4<U>& vector) :
    x(static_cast<T>(vector.x)),
    y(static_cast<T>(vector.y)),
    z(static_cast<T>(vector.z)),
    w(static_cast<T>(vector.w))
{
}



template <typename T>
inline Vector4<T> operator -(const Vector4<T>& right)
{
    return Vector4<T>(-right.x, -right.y,-right.z, -right.w);
}



template <typename T>
inline Vector4<T>& operator +=(Vector4<T>& left, const Vector4<T>& right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    left.w += right.w;
    return left;
}



template <typename T>
inline Vector4<T>& operator -=(Vector4<T>& left, const Vector4<T>& right)
{
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;
    left.w -= right.w;
    return left;
}



template <typename T>
inline Vector4<T> operator +(const Vector4<T>& left, const Vector4<T>& right)
{
    return Vector4<T>(left.x + right.x, left.y + right.y,left.z + right.z, left.w + right.w);
}



template <typename T>
inline Vector4<T> operator -(const Vector4<T>& left, const Vector4<T>& right)
{
    return Vector4<T>(left.x - right.x, left.y - right.y,left.z - right.z, left.w - right.w);
}



template <typename T>
inline Vector4<T> operator *(const Vector4<T>& left, T right)
{
    return Vector4<T>(left.x * right, left.y * right,left.z * right, left.w * right);
}



template <typename T>
inline Vector4<T> operator *(T left, const Vector4<T>& right)
{
    return Vector4<T>(right.x * left, right.y * left,right.z * left, right.w * left);
}



template <typename T>
inline Vector4<T>& operator *=(Vector4<T>& left, T right)
{
    left.x *= right;
    left.y *= right;
    left.z *= right;
    left.w *= right;
    return left;
}



template <typename T>
inline Vector4<T> operator /(const Vector4<T>& left, T right)
{
    return Vector4<T>(left.x / right, left.y / right,left.z / right, left.w / right);
}



template <typename T>
inline Vector4<T>& operator /=(Vector4<T>& left, T right)
{
    left.x /= right;
    left.y /= right;
    left.z /= right;
    left.w /= right;
    return left;
}



template <typename T>
inline bool operator ==(const Vector4<T>& left, const Vector4<T>& right)
{
    return (left.x == right.x) && (left.y == right.y) && (left.z == right.z) && (left.w == right.w);
}



template <typename T>
inline bool operator !=(const Vector4<T>& left, const Vector4<T>& right)
{
    return (left.x != right.x) || (left.y != right.y) || (left.z != right.z) || (left.w != right.w);
}


//####################################################//

namespace c
{
class Colour
{
public :
    Bubyte r,g,b,a;
    Colour(Bubyte _r,Bubyte _g,Bubyte _b,Bubyte _a=255):r(_r),g(_g),b(_b),a(_a)
    {
    }
    Colour():r(255),g(255),b(255),a(255) {};
    Colour(const Colour& next):r(next.r),g(next.g),b(next.b),a(next.a) {};
    void Red()
    {
        this->r=255;
        this->g=0;
        this->b=0;
        this->a=255;
    }
    void Green()
    {
        this->r=0;
        this->g=255;
        this->b=0;
        this->a=255;
    }
    void Blue()
    {
        this->r=0;
        this->g=0;
        this->b=255;
        this->a=255;
    }


};
}
//#################################################################
namespace eq
{

template <typename T>
class Triangle
{
public :
    Triangle(Vector2<T> first,Vector2<T> second,Vector2<T> third):first(first),second(second),third(third) {}

    Triangle() :first(0),second(0),third(0) {};

    BBool calculate(Vector2<T> current)
    {
        if(!first || !second || !third)
        {
            return false;
        }
        return ((first.x-second.x)*(current.y-first.y) -(first.y-second.y)*(current.x - first.x )>0)
               &&((second.x-third.x)*(current.y-second.y)-(second.y-third.y)*(current.x - second.x)>0)
               &&((third.x-first.x) *(current.y-third.y) -(third.y-first.y) *(current.x - third.x )>0);
    }
    BBool calculate(T x,T y)
    {
        return ((first.x-second.x)*(y-first.y) -(first.y-second.y)*(x - first.x )>0)
               &&((second.x-third.x)*(y-second.y)-(second.y-third.y)*(x - second.x)>0)
               &&((third.x-first.x) *(y-third.y) -(third.y-first.y) *(x - third.x )>0);


    }
    //MEMBERS
    Vector2<T> first;
    Vector2<T> second;
    Vector2<T> third;

};


typedef Triangle<Bfloat> TriangleFloat;
typedef Triangle<Bdouble> TriangleDouble;
typedef Triangle<Buint> TriangleUint;



}
//#################################################################
} // namespace d_type




