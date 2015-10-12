#ifndef VECTOR4_H
#define VECTOR4_H
#include "structs.hpp"

using namespace d_type;

template <typename T>
class Vector4
{
public:

    Vector4();
    Vector4(T X, T Y,T Z,T W);
    template <typename U>
    explicit Vector4(const Vector4<U>& vector);
    T min();
    T max();
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
inline std::ostream& operator<< (std::ostream& stream, const Vector4<T>& v)
{

    stream<<v.x<<" "<<v.y<<" "<<v.z<<" "<<v.w<<"\n";
    return stream;
}

template <typename T>
inline bool operator !=(const Vector4<T>& left, const Vector4<T>& right)
{
    return (left.x != right.x) || (left.y != right.y) || (left.z != right.z) || (left.w != right.w);
}

template <typename T>
T Vector4<T>::max()
{
    T greatest = std::numeric_limits<T>::max(); // Largest possible integer
    // there are a number of ways to structure this loop, this is just one

    greatest = std::max(greatest, x);
    greatest = std::max(greatest, y);
    greatest = std::max(greatest, z);
    greatest = std::max(greatest, w);

    return greatest;
};
template <typename T>
T Vector4<T>::min()
{
    T smallest = std::numeric_limits<T>::max(); // Largest possible integer
    // there are a number of ways to structure this loop, this is just one

    smallest = std::min(smallest, x);
    smallest = std::min(smallest, y);
    smallest = std::min(smallest, z);
    smallest = std::min(smallest, w);

    return smallest;
};


typedef Vector4<Bint>   Vector4Bi;
typedef Vector4<Bfloat> Vector4Bf;
typedef Vector4<BBool> Vector4Bb;
typedef Vector4<Bdouble> Vector4Bd;

#endif // VECTOR4_H
