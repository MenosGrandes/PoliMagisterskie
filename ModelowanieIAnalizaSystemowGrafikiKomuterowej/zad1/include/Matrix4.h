#ifndef MATRIX4_H
#define MATRIX4_H
#include "Vector4.h"

template <typename T>
class Matrix4
{
public:

    Matrix4();
    Matrix4(T a,T a2,T a3,T a4,T a5,T a6,T a7,T a8,T a9,T a10,T a11,T a12,T a13,T a14,T a15,T a16);
    Matrix4(Vector4<T> a1,Vector4<T> a2,Vector4<T> a3,Vector4<T> a4);
    const T * getElements() const;
    void setElements(const T data[16]);
    const static Matrix4<T> Identity=Matrix4<T>(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);



    inline Matrix4<T>& operator *=(Vector4<T>& vector, Matrix4<T> matrix)
    {
        Matrix4<T> temp=Matrix4<T>::Identity;
        for(Buint = 0 ; m_x<4; m_x++)
        {
            for(Buint = 0 ; m_y<4; m_y++)
            {
                for(Buint = 0 ; v<4; v++)
                {
                    temp[4*m_x+m_y]=matrix[4*m_x+m_y]*vector[v];
                }
            }
        }



        return temp;
    }

private :
    T data[16];

};


#endif // MATRIX4_H
