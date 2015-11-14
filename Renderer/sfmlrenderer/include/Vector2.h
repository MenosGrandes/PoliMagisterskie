#ifndef VECTOR2_H
#define VECTOR2_H
#include "structs.hpp"
template <typename T>
class Vector2
{
public:

    Vector2();
    Vector2(T X, T Y);
    template <typename U>
    explicit Vector2(const Vector2<U>& vector);
    T min();
    T max();

    T  dotProduct(const Vector2<T>& p1, const Vector2<T>& p2);

    Vector2<T> computeNormal(const Vector2<T>& p1, const Vector2<T>& p2);



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
Vector2<T> operator +(const Vector2<T>& left, const T right);

template <typename T>
Vector2<T> operator +(const T right, const Vector2<T>& left);



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
inline std::ostream& operator<< (std::ostream& stream, const Vector2<T>& v)
{
    stream<<v.x<<" "<<v.y<<"\n";

    return stream;
}

////////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T>::Vector2() :
    x(0),
    y(0)
{

}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T>::Vector2(T X, T Y) :
    x(X),
    y(Y)
{

}


////////////////////////////////////////////////////////////
template <typename T>
template <typename U>
inline Vector2<T>::Vector2(const Vector2<U>& vector) :
    x(static_cast<T>(vector.x)),
    y(static_cast<T>(vector.y))
{
}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T> operator -(const Vector2<T>& right)
{
    return Vector2<T>(-right.x, -right.y);
}
///////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T> operator +(const Vector2<T>& right)
{
    return Vector2<T>(+right.x, +right.y);
}
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T>& operator +=(Vector2<T>& left, const Vector2<T>& right)
{
    left.x += right.x;
    left.y += right.y;

    return left;
}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T>& operator -=(Vector2<T>& left, const Vector2<T>& right)
{
    left.x -= right.x;
    left.y -= right.y;

    return left;
}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T> operator +(const Vector2<T>& left, const Vector2<T>& right)
{
    return Vector2<T>(left.x + right.x, left.y + right.y);
}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T> operator -(const Vector2<T>& left, const Vector2<T>& right)
{
    return Vector2<T>(left.x - right.x, left.y - right.y);
}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T> operator *(const Vector2<T>& left, const T right)
{
    return Vector2<T>(left.x * right, left.y * right);
}
///////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T> operator *(const Vector2<T>& left, const Vector2<T>& right)
{
    return Vector2<T>(left.x * right.x, left.y * right.y);
}

////////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T> operator *(const T left, const Vector2<T>& right)
{
    return Vector2<T>(right.x * left, right.y * left);
}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T>& operator *=(Vector2<T>& left, const T right)
{
    left.x *= right;
    left.y *= right;

    return left;
}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T> operator /(const Vector2<T>& left, const T right)
{
    return Vector2<T>(left.x / right, left.y / right);
}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T>& operator /=(Vector2<T>& left, const T right)
{
    left.x /= right;
    left.y /= right;

    return left;
}


////////////////////////////////////////////////////////////
template <typename T>
inline bool operator ==(const Vector2<T>& left, const Vector2<T>& right)
{
    return (left.x == right.x) && (left.y == right.y);
}


////////////////////////////////////////////////////////////
template <typename T>
inline bool operator !=(const Vector2<T>& left, const Vector2<T>& right)
{
    return (left.x != right.x) || (left.y != right.y);
}
template <typename T>
T Vector2<T>::max()
{
    // there are a number of ways to structure this loop, this is just one

    T greatest = std::max(x, y);

    return greatest;
};
template <typename T>
T Vector2<T>::min()
{
    // there are a number of ways to structure this loop, this is just one

    T smallest = std::min(y, x);

    return smallest;
};
template <typename T>
Vector2<T> Vector2<T>::computeNormal(const Vector2<T>& p1, const Vector2<T>& p2)
{
    Vector2<T> normal(p1.y - p2.y, p2.x - p1.x);
    float length = std::sqrt(normal.x * normal.x + normal.y * normal.y);
    if (length != 0.f)
        normal /= length;
    return normal;
};

// Compute the dot product of two vectors
template <typename T>
T  Vector2<T>::dotProduct(const Vector2<T>& p1, const Vector2<T>& p2)
{
    return p1.x * p2.x + p1.y * p2.y;
};



typedef Vector2<d_type::Bfloat> Vector2Bf;
typedef Vector2<d_type::Bdouble> Vector2Bd;
typedef Vector2<d_type::Bint> Vector2Bi;
typedef Vector2<d_type::Buint> Vector2Bui;
typedef Vector2<d_type::Bshort> Vector2Bs;

#endif // VECTOR2_H
