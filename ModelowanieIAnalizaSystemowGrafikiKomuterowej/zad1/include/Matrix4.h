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
    const static Matrix4<T> Identity;//=Matrix4<T>(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
    Vector4<Vector4<T> > data;


};


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
inline Matrix4<T>::Matrix4(T a,T a2,T a3,T a4,T a5,T a6,T a7,T a8,T a9,T a10,T a11,T a12,T a13,T a14,T a15,T a16)
{
//
//    for(d_type::Buint i=0; i<4; i++)
//    {
//        data[i]=Vector4<T>();
//    }

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
    stream<<matrix.data.x.x;
    stream<<matrix.data.x.y;
    stream<<matrix.data.x.z;
    stream<<matrix.data.x.w<<"\n";
    stream<<matrix.data.y.x;
    stream<<matrix.data.y.y;
    stream<<matrix.data.y.z;
    stream<<matrix.data.y.w<<"\n";
    stream<< matrix.data.z.x;
    stream<< matrix.data.z.y;
    stream<< matrix.data.z.z;
    stream<< matrix.data.z.w<<"\n";
    stream<< matrix.data.w.x;
    stream<< matrix.data.w.y;
    stream<< matrix.data.w.z;
    stream<< matrix.data.w.w<<"\n";
    return stream;
}
template <typename T>
inline Matrix4<T>& operator *=( Matrix4<T> matrix, const Vector4<T>& vector)
{
    Matrix4<T> temp=Matrix4<T>::Identity;
//        for(Buint = 0 ; m_x<4; m_x++)
//        {
//            for(Buint = 0 ; m_y<4; m_y++)
//            {
//                for(Buint = 0 ; v<4; v++)
//                {
//                    temp[4*m_x+m_y]=matrix[4*m_x+m_y]*vector[v];
//                }
//            }
//        }



    return temp;
}
template <typename T>
inline Matrix4<T> operator +(const Matrix4<T> left)
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
inline Matrix4<T> operator -(const Matrix4<T> left)
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
inline Matrix4<T> operator +(const Matrix4<T> left,const Matrix4<T> right)
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
    left.data.x.y +=right.data.x.y;
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
inline Matrix4<T> operator -(const Matrix4<T> left,const Matrix4<T> right)
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
inline Matrix4<T> operator *(const Matrix4<T> left,const T right)
{
    Matrix4<T> tmp=Matrix4<T>();
    tmp.data.x.x=left.data.x.x *right;
    tmp.data.x.y=left.data.x.y *right;
    tmp.data.x.z=left.data.x.z *right;
    tmp.data.x.w=left.data.x.w *right;
    tmp.data.y.x=left.data.y.x *right;
    tmp.data.y.y=left.data.y.y*right;
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
inline Matrix4<T> operator *(const Matrix4<T> left,const Matrix4<T> right)
{

    int i, j;
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            std::cout<<"C["<<i<<"]["<<j<<"]=A["<<i<<"]["<<j<<"]+B["<<i<<"]["<<j<<"]\n";

        }
    }




    Matrix4<T> tmp=Matrix4<T>();

    tmp.data.x.x=left.data.x+right.data.x;
    tmp.data.

    tmp.data.x.y=(left.data.x.x *right.data.x.x +
                  left.data.x.y *right.data.y.x +
                  left.data.x.z *right.data.z.x +
                  left.data.x.w *right.data.w.x);


//    tmp.data.x.y=left.data.x.y *right;
//
//
//    tmp.data.x.z=left.data.x.z *right;
//    tmp.data.x.w=left.data.x.w *right;
//    tmp.data.y.x=left.data.y.x *right;
//    tmp.data.y.y=left.data.y.y*right;
//    tmp.data.y.z=left.data.y.z *right;
//    tmp.data.y.w=left.data.y.w *right;
//    tmp.data.z.x=left.data.z.x *right;
//    tmp.data.z.y=left.data.z.y *right;
//    tmp.data.z.z=left.data.z.z *right;
//    tmp.data.z.w=left.data.z.w *right;
//    tmp.data.w.x=left.data.w.x *right;
//    tmp.data.w.y=left.data.w.y *right;
//    tmp.data.w.z=left.data.w.z *right;
//    tmp.data.w.w=left.data.w.w *right;

    //return tmp;
}

typedef Matrix4<d_type::Bfloat> Matrix4Bfloat;
typedef Matrix4<d_type::Bint> Matrix4Bint;

#endif // MATRIX4_H
