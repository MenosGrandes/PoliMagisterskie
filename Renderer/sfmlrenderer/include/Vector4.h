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
    T dotProduct( const Vector4<T>& p2);
    T length();
    Vector4<T> cross(const Vector4<T>& p1);
    Vector4<T> normalized();
    Vector4<T> rotate(Vector4<T> axis, d_type::Bfloat angle);
    Vector4<T> lerp(Vector4<T> dest, d_type::Bfloat lerpFactor);


    T x; ///< X coordinate of the vector
    T y; ///< Y coordinate of the vector
    T z; ///< Z coordinate of the vector
    T w; ///< W coordinate of the vector / depth
};
template <typename T>
T Vector4<T>::dotProduct( const Vector4<T>& p2)
{
    return (x*p2.x +y*p2.y + z*p2.z + w*p2.w );
}

template <typename T>
inline Vector4<T>::Vector4() :x(),y(),z(),w() {}



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
inline std::ostream& operator<< (std::ostream& stream, const Vector4<T>& v)
{
    stream<<v.x<<" "<<v.y<<" "<<v.z<<" "<<v.w<<"\n";

    return stream;
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

template <typename T>
inline T Vector4<T>::max()
{
    // there are a number of ways to structure this loop, this is just one
    return std::max({x,y,z,w});;
};
template <typename T>
inline T Vector4<T>::min()
{
    return std::min({x,y,z,w});;
};


template <typename T>
inline T Vector4<T>::length()
{
    return (T)sqrt(x * x + y * y + z * z + w * w);
};


template <typename T>
inline Vector4<T> Vector4<T>::cross (const Vector4<T>& p1)
{
    T x_ = y * p1.z - z * p1.y;
    T y_ = z * p1.x - x * p1.z;
    T z_ = x * p1.y- y * p1.x;

    return  Vector4<T>(x_, y_, z_, 0);
};
template <typename T>
inline Vector4<T> Vector4<T>::normalized()
{
    T _length = length();

    return  Vector4<T>(x / _length, y / _length, z / _length, w / _length);
}

template <typename T>
inline Vector4<T> Vector4<T>::rotate(Vector4<T> axis, d_type::Bfloat angle)
{
    d_type::Bfloat sinAngle = (d_type::Bfloat)sinf(-angle);
    d_type::Bfloat cosAngle = (d_type::Bfloat)cosf(-angle);

        return (this.cross(axis*sinAngle) + (this*cosAngle + (axis*this.dotProduct(axis*(1-cosAngle)))));

//    return cross(axis.Mul(sinAngle)).Add(           //Rotation on local X
//               (this.Mul(cosAngle)).Add(                     //Rotation on local Z
//                   axis.Mul(this.Dot(axis.Mul(1 - cosAngle))))); //Rotation on local Y
}
template <typename T>
inline Vector4<T> Vector4<T>::lerp(Vector4<T> dest, d_type::Bfloat lerpFactor)
{
    return dest-(this)*(lerpFactor)+(this);

}

typedef Vector4<Bint>   Vector4Bi;
typedef Vector4<Bfloat> Vector4Bf;
typedef Vector4<BBool> Vector4Bb;
typedef Vector4<Bdouble> Vector4Bd;

#endif // VECTOR4_H
