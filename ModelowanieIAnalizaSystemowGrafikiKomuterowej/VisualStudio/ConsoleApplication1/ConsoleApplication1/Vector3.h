






#ifndef VECTOR3_H
#define VECTOR3_H
#include "structs.hpp"
#include <vector>
using namespace d_type;





template <typename T>
class Vector3
{
public :
    Vector3();
    Vector3(T X, T Y, T Z);
    template <typename U>
    Vector3(const Vector3<U>& vector);
    T min();
    T max();

    static T  dotProduct(const Vector3<T>& p1, const Vector3<T>& p2);
    Vector3<T> vecProduct(const Vector3<T>& p1, const Vector3<T>& p2);
    Vector3<T> computeNormal(const Vector3<T>& p1, const Vector3<T>& p2);
    T length();
    T lengthSquared();
    static Vector3<T> cross(const Vector3<T>& left,const Vector3<T>& right);
    Vector3<T> reflect(const Vector3<T>&v);
    Vector3<T> lerp(const Vector3<T>&v, const T f);
    Vector3<T> normalizeProduct();
    static void normalize(Vector3<T>&v);

    T x, y, z;






};



template <typename T>
inline std::ostream& operator<< (std::ostream& stream, const Vector3<T>& v)
{
    stream<<v.x<<" "<<v.y<<" "<<v.z<<"\n";

    return stream;
}

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
inline Vector3<T> operator +(const Vector3<T>& left)
{
    return Vector3<T>(+left.x, +left.y, +left.z);
}
///////////////////////////////////////////////////////////
template <typename T>
inline Vector3<T> operator +(const Vector3<T>& left, const T & right)
{
    return Vector3<T>(left.x+right, left.y+right, left.z+right);
}
////////////////////////////////////////////////////////////
template <typename T>
inline Vector3<T> operator +(const T& right,const Vector3<T>& left)
{
    return Vector3<T>(left.x+right, left.y+right, left.z+right);
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
inline Vector3<T> operator *(const Vector3<T>& left, const Vector3<T>& right)
{
    return Vector3<T>(left.x * right.x, left.y * right.y, left.z * right.z);
}
////////////////////////////////////////////////////////////
template <typename T>
inline Vector3<T> operator *=(const Vector3<T>& left, const Vector3<T>& right)
{
    return Vector3<T>(    left.x *= right.x,
                          left.y *= right.y,
                          left.z *= right.z

                     );
}
////////////////////////////////////////////////////////////
template <typename T>
inline Vector3<T> operator *(T left, const Vector3<T>& right)
{
    return Vector3<T>(right.x * left, right.y * left, right.z * left);
}


////////////////////////////////////////////////////////////
template <typename T>
inline Vector3<T>& operator *=(Vector3<T>& left, const T right)
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
///////////////////////////////////////////////////////////
template <typename T>
T Vector3<T>::min()
{
    return  std::min({x,y,z});
};
///////////////////////////////////////////////////////////

template <typename T>
T Vector3<T>::max()
{
    return  std::max({x,y,z});
};
///////////////////////////////////////////////////////////

template <typename T>
T Vector3<T>::dotProduct(const Vector3<T>& p1, const Vector3<T>& p2)
{
    return (p1.x*p2.x + p1.y*p2.y + p1.z*p2.z);
}
///////////////////////////////////////////////////////////

template <typename T>
Vector3<T> Vector3<T>::vecProduct(const Vector3<T>& p1, const Vector3<T>& p2)
{
    return Vector3<T>(p1.y*p2.z - p1.z-p2.y ,p1.z*p2.x - p1.x-p2.z,p1.x*p2.y - p1.y*p2.x);
}
///////////////////////////////////////////////////////////
template <typename T>
Vector3<T> Vector3<T>::computeNormal(const Vector3<T>& p1, const Vector3<T>& p2)
{

}
///////////////////////////////////////////////////////////

template <typename T>
T Vector3<T>::length()
{
    return  (T)sqrt(x*x+  y*y+  z*z);
}
///////////////////////////////////////////////////////////

template <typename T>
T Vector3<T>::lengthSquared()
{
    return  (T)(x*x+  y*y+  z*z);
}
///////////////////////////////////////////////////////////

template <typename T>
Vector3<T> Vector3<T>::cross(const Vector3<T>& left,const Vector3<T>& right)
{

    return  Vector3<T>(left.y * right.z - left.z * right.y, left.z * right.x - left.x * right.z, left.x * right.y - left.y * right.x);

}


///////////////////////////////////////////////////////////

template <typename T>
Vector3<T> Vector3<T>::reflect(const Vector3<T>& v)
{
    return this - (2 * this.dotProduct(v) *v);
}
///////////////////////////////////////////////////////////

template <typename T>
Vector3<T> Vector3<T>::lerp(const Vector3<T>& v, const T f)
{

    return Vector3<T>(
               this.x + f * (v.x - this.x),
               this.y + f * (v.y - this.y),
               this.z + f * (v.z - this.z));

}
///////////////////////////////////////////////////////////
template <typename T>
Vector3<T> Vector3<T>::normalizeProduct()
{
    Vector3<T> newV=Vector3<T>(x,y,z);
    d_type::Bfloat n = this->length();
    if(n!=0)
    {
        newV/=n;
        return newV;
    }
    else
        return newV;// throw new Exception("Couldn't normalize");
}
///////////////////////////////////////////////////////////
template <typename T>
void Vector3<T>::normalize(Vector3<T>&v)
{
    d_type::Bfloat n = v.length();
    if(n!=0)
    {
        v/=n;
    }
}



// Define the most common types
typedef Vector3<Bint>   Vector3Bi;
typedef Vector3<Bfloat> Vector3Bf;
typedef Vector3<BBool> Vector3Bb;
typedef Vector3<Bdouble> Vector3Bd;
typedef Vector3<Bubyte> Vector3Bub;
typedef std::vector<Vector3Bf> Vector3BfVector;
typedef Vector3Bf Point3Bf;


#endif // VECTOR3_H
