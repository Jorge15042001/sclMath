#pragma once

#include "sclCopyMatrix.hpp"   //TODO: remove
#include "sclDistance.hpp"     //TODO remove
#include "sclInnerProduct.hpp" //TODO: remove
#include "sclMathErrors.hpp"
#include "sclMathUtility.hpp"
#include "sclMatrix.hpp"
#include <cmath>
#include <cstdint>
#include <iostream>

// matrix addition
// ###########################################################################################################
// overloading operator + for sclMath::ComplexMatrix, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator+(const sclMath::ComplexMatrix &m1,
                                 const sclMath::ComplexMatrix &m2);
// overloading operator + for sclMath::RealMatrix, sclMath::RealMatrix
sclMath::RealMatrix operator+(const sclMath::RealMatrix &m1,
                              const sclMath::RealMatrix &m2);
// overloading operator + for sclMath::RealMatrix, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator+(const sclMath::RealMatrix &,
                                 const sclMath::ComplexMatrix &);
// overloading operator + for sclMath::ComplexMatrix, sclMath::RealMatrix
sclMath::ComplexMatrix operator+(const sclMath::ComplexMatrix &m1,
                                 const sclMath::RealMatrix &m2);

// matrix Subtraction
// ###########################################################################################################
// overloading operator - for sclMath::ComplexMatrix, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator-(const sclMath::ComplexMatrix &m1,
                                 const sclMath::ComplexMatrix &m2);
// overloading operator - for sclMath::RealMatrix, sclMath::RealMatrix
sclMath::RealMatrix operator-(const sclMath::RealMatrix &m1,
                              const sclMath::RealMatrix &m2);
// overloading operator - for sclMath::RealMatrix, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator-(const sclMath::RealMatrix &m1,
                                 const sclMath::ComplexMatrix &m2);
// overloading operator - for sclMath::ComplexMatrix, sclMath::RealMatrix
sclMath::ComplexMatrix operator-(const sclMath::ComplexMatrix &m1,
                                 const sclMath::RealMatrix &m2);

// matrix multiplication
// ###########################################################################################################
// overloading operator * for sclMath::ComplexMatrix, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator*(const sclMath::ComplexMatrix &m1,
                                 const sclMath::ComplexMatrix &m2);
// overloading operator * for sclMath::RealMatrix, sclMath::RealMatrix
sclMath::RealMatrix operator*(const sclMath::RealMatrix &m1,
                              const sclMath::RealMatrix &m2);
// overloading operator * for sclMath::RealMatrix, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator*(const sclMath::RealMatrix &m1,
                                 const sclMath::ComplexMatrix &m2);
// overloading operator * for sclMath::ComplexMatrix, sclMath::RealMatrix
sclMath::ComplexMatrix operator*(const sclMath::ComplexMatrix &m1,
                                 const sclMath::RealMatrix &m2);

// scale matric
// ###########################################################################################################
// overloading operator * for sclMath::ComplexScalar, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator*(const sclMath::ComplexScalar s,
                                 const sclMath::ComplexMatrix &m);
// overloading operator * for sclMath::Scalar, sclMath::RealMatrix
sclMath::RealMatrix operator*(const sclMath::RealScalar s,
                              const sclMath::RealMatrix &m);
// overloading operator * for sclMath::Scalar, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator*(const sclMath::RealScalar s,
                                 const sclMath::ComplexMatrix &m);
// overloading operator * for sclMath::ComplexScalar, sclMath::RealMatrix
sclMath::ComplexMatrix operator*(const sclMath::ComplexScalar s,
                                 const sclMath::RealMatrix &m);

// == operator for matrices
// ###########################################################################################################
// TODO: almost equal neeeds to be tested with complex numbers
// TODO: write a test for this function
// overloading operator == for ComplexMatrix
bool operator==(const sclMath::ComplexMatrix &m1,
                const sclMath::ComplexMatrix &m2);
// overloading operator == for realmatrices
bool operator==(const sclMath::RealMatrix &m1, const sclMath::RealMatrix &m2);
// overloading operator == for sclMath::RealMatrix and sclMath::ComplexMatrix
bool operator==(const sclMath::RealMatrix &m1,
                const sclMath::ComplexMatrix &m2);
// overloading operator == for sclMath::ComplexMatrix and sclMath::RealMatrix
bool operator==(const sclMath::ComplexMatrix &m1,
                const sclMath::RealMatrix &m2);
