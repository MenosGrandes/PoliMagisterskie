#ifndef VECTOR3_H
#define VECTOR3_H
#include "structs.hpp"
using namespace d_type;

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
#endif // VECTOR3_H
