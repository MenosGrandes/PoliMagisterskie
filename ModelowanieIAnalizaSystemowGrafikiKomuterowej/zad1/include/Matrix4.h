#ifndef MATRIX4_H
#define MATRIX4_H
#include "Vector4.h"
#include <ostream>
template <typename T>
class Matrix4
{
public:

    Matrix4();
    Matrix4(T a,T a2,T a3,T a4,T a5,T a6,T a7,T a8,T a9,T a10,T a11,T a12,T a13,T a14,T a15,T a16);
    Matrix4(Vector4<T> a1,Vector4<T> a2,Vector4<T> a3,Vector4<T> a4);
    const static Matrix4<T> Identity;//=Matrix4<T>(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

T data[16];


};


template <typename T>
inline Matrix4<T>::Matrix4()
{
    for(d_type::Buint i=0; i<16; i++)
    {
        data[i]=0;
    }
}


template <typename T>
inline Matrix4<T>::Matrix4(T a,T a2,T a3,T a4,T a5,T a6,T a7,T a8,T a9,T a10,T a11,T a12,T a13,T a14,T a15,T a16)
{
    data[0]=(a);
    data[1]=(a2);
    data[2]=(a3);
    data[3]=(a4);
    data[4]=(a5);
    data[5]=(a6);
    data[6]=(a7);
    data[7]=(a8);
    data[8]=(a9);
    data[9]=(a10);
    data[10]=(a11);
    data[11]=(a12);
    data[12]=(a13);
    data[13]=(a14);
    data[14]=(a15);
    data[15]=(a16);
}
    template <typename T>
    inline std::ostream& operator<< (std::ostream& stream, const Matrix4<T>& matrix)
    {
        for(d_type::Buint x=0; x<4; x++)
        {   stream<<"\n";
            for(d_type::Buint y=0; y<4; y++)
            {
            stream<<matrix.data[4*x+y]<<" ";
            }
        }
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

#endif // MATRIX4_H
