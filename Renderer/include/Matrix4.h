#ifndef MATRIX4_H
#define MATRIX4_H
#include "Vector4.h"
#include <ostream>
#include <iostream>
template <typename T>
class Matrix4
{
public:
    Matrix4();

    Matrix4(T a,T a2,T a3,T a4,T a5,T a6,T a7,T a8,T a9,T a10,T a11,T a12,T a13,T a14,T a15,T a16);
    Matrix4(Vector4<T> a1,Vector4<T> a2,Vector4<T> a3,Vector4<T> a4);
    void transpose();
    const static Matrix4<T> Identity;//=Matrix4<T>(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
    Vector4<Vector4<T> > data;


};

template <typename T>
void Matrix4<T>::transpose()
{
    Matrix4<T> tmp=Matrix4(data.x,data.y,data.z,data.w);

    data.x.x=tmp.data.x.x;
    data.x.y=tmp.data.y.x;
    data.x.z=tmp.data.z.x;
    data.x.w=tmp.data.w.x;

    data.y.x=tmp.data.x.y;
    data.y.y=tmp.data.y.y;
    data.y.z=tmp.data.z.y;
    data.y.w=tmp.data.w.y;

    data.z.x=tmp.data.x.z;
    data.z.y=tmp.data.y.z;
    data.z.z=tmp.data.z.z;
    data.z.w=tmp.data.w.z;

    data.w.x=tmp.data.x.w;
    data.w.y=tmp.data.y.w;
    data.w.z=tmp.data.z.w;
    data.w.w=tmp.data.w.w;


}

template <typename T>
inline Matrix4<T>::Matrix4()
{
    data.x.x=(0);
    data.x.y=(0);
    data.x.z=(0);
    data.x.w=(0);
    data.y.x=(0);
    data.y.y=(0);
    data.y.z=(0);
    data.y.w=(0);
    data.z.x=(0);
    data.z.y=(0);
    data.z.z=(0);
    data.z.w=(0);
    data.w.x=(0);
    data.w.y=(0);
    data.w.z=(0);
    data.w.w=(0);
}

template <typename T>
inline Matrix4<T>::Matrix4(Vector4<T> a1,Vector4<T> a2,Vector4<T> a3,Vector4<T> a4)
{
    data.x=a1;
    data.y=a2;
    data.z=a3;
    data.w=a4;

}

template <typename T>
inline Matrix4<T>::Matrix4(T a,T a2,T a3,T a4,T a5,T a6,T a7,T a8,T a9,T a10,T a11,T a12,T a13,T a14,T a15,T a16)
{
    data.x.x=(a);
    data.x.y=(a2);
    data.x.z=(a3);
    data.x.w=(a4);
    data.y.x=(a5);
    data.y.y=(a6);
    data.y.z=(a7);
    data.y.w=(a8);
    data.z.x=(a9);
    data.z.y=(a10);
    data.z.z=(a11);
    data.z.w=(a12);
    data.w.x=(a13);
    data.w.y=(a14);
    data.w.z=(a15);
    data.w.w=(a16);
}
template <typename T>
inline std::ostream& operator<< (std::ostream& stream, const Matrix4<T>& matrix)
{
    stream<<matrix.data.x.x<<" ";;
    stream<<matrix.data.x.y<<" ";;
    stream<<matrix.data.x.z<<" ";;
    stream<<matrix.data.x.w<<"\n";
    stream<<matrix.data.y.x<<" ";;
    stream<<matrix.data.y.y<<" ";;
    stream<<matrix.data.y.z<<" ";;
    stream<<matrix.data.y.w<<"\n";
    stream<< matrix.data.z.x<<" ";;
    stream<< matrix.data.z.y<<" ";;
    stream<< matrix.data.z.z<<" ";;
    stream<< matrix.data.z.w<<"\n";
    stream<< matrix.data.w.x<<" ";;
    stream<< matrix.data.w.y<<" ";;
    stream<< matrix.data.w.z<<" ";;
    stream<< matrix.data.w.w<<"\n";
    return stream;
}
template <typename T>
inline Vector4<T> operator *( const Matrix4<T> matrix, const Vector4<T>& vector)
{
    return Vector4<T>(
               Vector4<T>::dotProduct(matrix.data.x,vector),
               Vector4<T>::dotProduct(matrix.data.y,vector),
               Vector4<T>::dotProduct(matrix.data.z,vector),
               Vector4<T>::dotProduct(matrix.data.w,vector)


           );
}



template <typename T>
inline Matrix4<T> operator +(const Matrix4<T> &left)
{

    return Matrix4<T>(
               +left.data.x.x ,
               +left.data.x.y ,
               +left.data.x.z ,
               +left.data.x.w ,
               +left.data.y.x ,
               +left.data.y.y ,
               +left.data.y.z ,
               +left.data.y.w ,
               +left.data.z.x ,
               +left.data.z.y ,
               +left.data.z.z ,
               +left.data.z.w ,
               +left.data.w.x ,
               +left.data.w.y ,
               +left.data.w.z ,
               +left.data.w.w
           );
}

template <typename T>
inline Matrix4<T> operator -(const Matrix4<T> &left)
{

    return Matrix4<T>(
               -left.data.x.x ,
               -left.data.x.y ,
               -left.data.x.z ,
               -left.data.x.w ,
               -left.data.y.x ,
               -left.data.y.y ,
               -left.data.y.z ,
               -left.data.y.w ,
               -left.data.z.x ,
               -left.data.z.y ,
               -left.data.z.z ,
               -left.data.z.w ,
               -left.data.w.x ,
               -left.data.w.y ,
               -left.data.w.z ,
               -left.data.w.w
           );
}
template <typename T>
inline Matrix4<T> operator +(const Matrix4<T> &left,const Matrix4<T> &right)
{
    Matrix4<T> tmp=Matrix4<T>();


    tmp.data.x.x=left.data.x.x + right.data.x.x;
    tmp.data.x.y=left.data.x.y + right.data.x.y;
    tmp.data.x.z=left.data.x.z + right.data.x.z;
    tmp.data.x.w=left.data.x.w + right.data.x.w;
    tmp.data.y.x=left.data.y.x + right.data.y.x;
    tmp.data.y.y=left.data.y.y + right.data.y.y;
    tmp.data.y.z=left.data.y.z + right.data.y.z;
    tmp.data.y.w=left.data.y.w + right.data.y.w;
    tmp.data.z.x=left.data.z.x + right.data.z.x;
    tmp.data.z.y=left.data.z.y + right.data.z.y;
    tmp.data.z.z=left.data.z.z + right.data.z.z;
    tmp.data.z.w=left.data.z.w + right.data.z.w;
    tmp.data.w.x=left.data.w.x + right.data.w.x;
    tmp.data.w.y=left.data.w.y + right.data.w.y;
    tmp.data.w.z=left.data.w.z + right.data.w.z;
    tmp.data.w.w=left.data.w.w + right.data.w.w;

    return tmp;
}
template <typename T>
inline Matrix4<T>& operator +=(Matrix4<T>& left, const Matrix4<T>& right)
{

    left.data.x.x += right.data.x.x;
    left.data.x.y += right.data.x.y;
    left.data.x.z += right.data.x.z;
    left.data.x.w += right.data.x.w;
    left.data.y.x += right.data.y.x;
    left.data.y.y += right.data.y.y;
    left.data.y.z += right.data.y.z;
    left.data.y.w += right.data.y.w;
    left.data.z.x += right.data.z.x;
    left.data.z.y += right.data.z.y;
    left.data.z.z += right.data.z.z;
    left.data.z.w += right.data.z.w;
    left.data.w.x += right.data.w.x;
    left.data.w.y += right.data.w.y;
    left.data.w.z += right.data.w.z;
    left.data.w.w += right.data.w.w;

    return left;
}


template <typename T>
inline Matrix4<T> operator -(const Matrix4<T> &left,const Matrix4<T> &  right)
{
    Matrix4<T> tmp=Matrix4<T>();


    tmp.data.x.x=left.data.x.x - right.data.x.x;
    tmp.data.x.y=left.data.x.y - right.data.x.y;
    tmp.data.x.z=left.data.x.z - right.data.x.z;
    tmp.data.x.w=left.data.x.w - right.data.x.w;
    tmp.data.y.x=left.data.y.x - right.data.y.x;
    tmp.data.y.y=left.data.y.y - right.data.y.y;
    tmp.data.y.z=left.data.y.z - right.data.y.z;
    tmp.data.y.w=left.data.y.w - right.data.y.w;
    tmp.data.z.x=left.data.z.x - right.data.z.x;
    tmp.data.z.y=left.data.z.y - right.data.z.y;
    tmp.data.z.z=left.data.z.z - right.data.z.z;
    tmp.data.z.w=left.data.z.w - right.data.z.w;
    tmp.data.w.x=left.data.w.x - right.data.w.x;
    tmp.data.w.y=left.data.w.y - right.data.w.y;
    tmp.data.w.z=left.data.w.z - right.data.w.z;
    tmp.data.w.w=left.data.w.w - right.data.w.w;

    return tmp;
}
template <typename T>
inline Matrix4<T>& operator -=(Matrix4<T>& left, const Matrix4<T>& right)
{

    left.data.x.x -= right.data.x.x;
    left.data.x.y -=right.data.x.y;
    left.data.x.z -= right.data.x.z;
    left.data.x.w -= right.data.x.w;
    left.data.y.x -= right.data.y.x;
    left.data.y.y -= right.data.y.y;
    left.data.y.z -= right.data.y.z;
    left.data.y.w -= right.data.y.w;
    left.data.z.x -= right.data.z.x;
    left.data.z.y -= right.data.z.y;
    left.data.z.z -= right.data.z.z;
    left.data.z.w -= right.data.z.w;
    left.data.w.x -= right.data.w.x;
    left.data.w.y -= right.data.w.y;
    left.data.w.z -= right.data.w.z;
    left.data.w.w -= right.data.w.w;

    return left;
}

template <typename T>
inline Matrix4<T> operator *(const Matrix4<T> &left,const T &right)
{
    Matrix4<T> tmp=Matrix4<T>();
    tmp.data.x.x=left.data.x.x *right;
    tmp.data.x.y=left.data.x.y *right;
    tmp.data.x.z=left.data.x.z *right;
    tmp.data.x.w=left.data.x.w *right;
    tmp.data.y.x=left.data.y.x *right;
    tmp.data.y.y=left.data.y.y *right;
    tmp.data.y.z=left.data.y.z *right;
    tmp.data.y.w=left.data.y.w *right;
    tmp.data.z.x=left.data.z.x *right;
    tmp.data.z.y=left.data.z.y *right;
    tmp.data.z.z=left.data.z.z *right;
    tmp.data.z.w=left.data.z.w *right;
    tmp.data.w.x=left.data.w.x *right;
    tmp.data.w.y=left.data.w.y *right;
    tmp.data.w.z=left.data.w.z *right;
    tmp.data.w.w=left.data.w.w *right;

    return tmp;
}

template <typename T>
inline Matrix4<T> operator *(const Matrix4<T> &left,const Matrix4<T> &right)
{
    return Matrix4<T>(
               Vector4<T>::dotProduct(Vector4<T>(right.data.x.x,right.data.y.x ,right.data.z.x ,right.data.w.x ),left.data.x),
               Vector4<T>::dotProduct(Vector4<T>(right.data.x.y,right.data.y.y ,right.data.z.y ,right.data.w.y ),left.data.x),
               Vector4<T>::dotProduct(Vector4<T>(right.data.x.z,right.data.y.z ,right.data.z.z ,right.data.w.z ),left.data.x),
               Vector4<T>::dotProduct(Vector4<T>(right.data.x.w,right.data.y.w ,right.data.z.w ,right.data.w.w ),left.data.x),

               //////////////////////////////////////////////////////////////////////////////////
               Vector4<T>::dotProduct(Vector4<T>(right.data.x.x,right.data.y.x ,right.data.z.x ,right.data.w.x ),left.data.y),
               Vector4<T>::dotProduct(Vector4<T>(right.data.x.y,right.data.y.y ,right.data.z.y ,right.data.w.y ),left.data.y),
               Vector4<T>::dotProduct(Vector4<T>(right.data.x.z,right.data.y.z ,right.data.z.z ,right.data.w.z ),left.data.y),
               Vector4<T>::dotProduct(Vector4<T>(right.data.x.w,right.data.y.w ,right.data.z.w ,right.data.w.w ),left.data.y),
////////////////////////////////////////////////////////////////////////////////
               Vector4<T>::dotProduct(Vector4<T>(right.data.x.x,right.data.y.x ,right.data.z.x ,right.data.w.x ),left.data.z),
               Vector4<T>::dotProduct(Vector4<T>(right.data.x.y,right.data.y.y ,right.data.z.y ,right.data.w.y ),left.data.z),
               Vector4<T>::dotProduct(Vector4<T>(right.data.x.z,right.data.y.z ,right.data.z.z ,right.data.w.z ),left.data.z),
               Vector4<T>::dotProduct(Vector4<T>(right.data.x.w,right.data.y.w ,right.data.z.w ,right.data.w.w ),left.data.z),
////////////////////////////////////////////////////////////////////////////////////////////////
               Vector4<T>::dotProduct(Vector4<T>(right.data.x.x,right.data.y.x ,right.data.z.x ,right.data.w.x ),left.data.w),
               Vector4<T>::dotProduct(Vector4<T>(right.data.x.y,right.data.y.y ,right.data.z.y ,right.data.w.y ),left.data.w),
               Vector4<T>::dotProduct(Vector4<T>(right.data.x.z,right.data.y.z ,right.data.z.z ,right.data.w.z ),left.data.w),
               Vector4<T>::dotProduct(Vector4<T>(right.data.x.w,right.data.y.w ,right.data.z.w ,right.data.w.w ),left.data.w)
           );

}
template <typename T>
inline Matrix4<T> &operator *=( Matrix4<T> &left,const Matrix4<T> &right)
{
    left= Matrix4<T>(
              Vector4<T>::dotProduct(Vector4<T>(right.data.x.x,right.data.y.x ,right.data.z.x ,right.data.w.x ),left.data.x),
              Vector4<T>::dotProduct(Vector4<T>(right.data.x.y,right.data.y.y ,right.data.z.y ,right.data.w.y ),left.data.x),
              Vector4<T>::dotProduct(Vector4<T>(right.data.x.z,right.data.y.z ,right.data.z.z ,right.data.w.z ),left.data.x),
              Vector4<T>::dotProduct(Vector4<T>(right.data.x.w,right.data.y.w ,right.data.z.w ,right.data.w.w ),left.data.x),

              //////////////////////////////////////////////////////////////////////////////////
              Vector4<T>::dotProduct(Vector4<T>(right.data.x.x,right.data.y.x ,right.data.z.x ,right.data.w.x ),left.data.y),
              Vector4<T>::dotProduct(Vector4<T>(right.data.x.y,right.data.y.y ,right.data.z.y ,right.data.w.y ),left.data.y),
              Vector4<T>::dotProduct(Vector4<T>(right.data.x.z,right.data.y.z ,right.data.z.z ,right.data.w.z ),left.data.y),
              Vector4<T>::dotProduct(Vector4<T>(right.data.x.w,right.data.y.w ,right.data.z.w ,right.data.w.w ),left.data.y),
////////////////////////////////////////////////////////////////////////////////
              Vector4<T>::dotProduct(Vector4<T>(right.data.x.x,right.data.y.x ,right.data.z.x ,right.data.w.x ),left.data.z),
              Vector4<T>::dotProduct(Vector4<T>(right.data.x.y,right.data.y.y ,right.data.z.y ,right.data.w.y ),left.data.z),
              Vector4<T>::dotProduct(Vector4<T>(right.data.x.z,right.data.y.z ,right.data.z.z ,right.data.w.z ),left.data.z),
              Vector4<T>::dotProduct(Vector4<T>(right.data.x.w,right.data.y.w ,right.data.z.w ,right.data.w.w ),left.data.z),
////////////////////////////////////////////////////////////////////////////////////////////////
              Vector4<T>::dotProduct(Vector4<T>(right.data.x.x,right.data.y.x ,right.data.z.x ,right.data.w.x ),left.data.w),
              Vector4<T>::dotProduct(Vector4<T>(right.data.x.y,right.data.y.y ,right.data.z.y ,right.data.w.y ),left.data.w),
              Vector4<T>::dotProduct(Vector4<T>(right.data.x.z,right.data.y.z ,right.data.z.z ,right.data.w.z ),left.data.w),
              Vector4<T>::dotProduct(Vector4<T>(right.data.x.w,right.data.y.w ,right.data.z.w ,right.data.w.w ),left.data.w)
          );
    return left;

}
typedef Matrix4<d_type::Bfloat> Matrix4Bfloat;
typedef Matrix4<d_type::Bint> Matrix4Bint;

#endif // MATRIX4_H
