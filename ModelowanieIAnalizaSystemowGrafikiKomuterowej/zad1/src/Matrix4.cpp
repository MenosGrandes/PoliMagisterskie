#include "Matrix4.h"

// ----------------------------------------------------------------------- default constructor
// a default matrix is an identity matrix

Matrix4::Matrix4(void) {
        for (int x = 0; x < 4; x++)
                for (int y = 0; y < 4; y++) {
                        if (x == y)
                                m[x][y] = 1.0;
                        else
                                m[x][y] = 0.0;
                }
}


// ----------------------------------------------------------------------- copy constructor

Matrix4::Matrix4 (const Matrix4& mat) {
        for (int x = 0; x < 4; x++)
                for (int y = 0; y < 4; y++)
                        m[x][y] = mat.m[x][y];
}


// ----------------------------------------------------------------------- destructor

Matrix4::~Matrix4 (void) {}




// ----------------------------------------------------------------------- assignment operator

Matrix4&
Matrix4::operator= (const Matrix4& rhs) {
        if (this == &rhs)
                return (*this);

        for (int x = 0; x < 4; x++)
                for (int y = 0; y < 4; y++)
                        m[x][y] = rhs.m[x][y];

        return (*this);
}


// ----------------------------------------------------------------------- operator*
// multiplication of two matrices

Matrix4
Matrix4::operator* (const Matrix4& mat) const {
        Matrix4  product;

        for (int y = 0; y < 4; y++)
                for (int x = 0; x < 4; x++) {
                        d_type::Bfloat sum = 0.0;

                        for (int j = 0; j < 4; j++)
                                sum += m[x][j] * mat.m[j][y];

                        product.m[x][y] = sum;
                }

        return (product);
}


// ----------------------------------------------------------------------- operator/
// division by a scalar

Matrix4
Matrix4::operator/ (const d_type::Bfloat d) {
        for (int x = 0; x < 4; x++)
                for (int y = 0; y < 4; y++)
                        m[x][y] = m[x][y] / d;

        return (*this);
}

Matrix4
Matrix4::scalar_mult(const d_type::Bfloat d) {
        for (int x = 0; x < 4; x++)
                for (int y = 0; y < 4; y++)
                        m[x][y] = m[x][y] * d;

        return (*this);
}



// ----------------------------------------------------------------------- set_identity
// set matrix to the identity matrix

void
Matrix4::set_identity(void) {
    for (int x = 0; x < 4; x++)
                for (int y = 0; y < 4; y++) {
                        if (x == y)
                                m[x][y] = 1.0;
                        else
                                m[x][y] = 0.0;
                }
}
