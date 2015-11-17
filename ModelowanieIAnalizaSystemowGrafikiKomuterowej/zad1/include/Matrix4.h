#ifndef MATRIX4_H
#define MATRIX4_H
#include "Vector4.h"
#include <ostream>
#include <iostream>
class Matrix4{
public:

d_type::Bfloat  m[4][4];                                                                // elements


Matrix4(void);                                                                   // default constructor

Matrix4(const Matrix4& mat);                                              // copy constructor

~Matrix4 (void);                                                                 // destructor

Matrix4&                                                                                 // assignment operator
operator= (const Matrix4& rhs);

Matrix4                                                                                  // multiplication of two matrices
operator* (const Matrix4& mat) const;

Matrix4
scalar_mult(const d_type::Bfloat m);

Matrix4                                                                                  // divsion by a double
operator/ (const d_type::Bfloat d);

void                                                                                    // set to the identity matrix
set_identity(void);
};
#endif // MATRIX4_H
