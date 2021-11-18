#pragma once

#include "sclMathErrors.hpp"
#include "sclMathUtility.hpp"
#include "sclMatrix.hpp"
#include <cmath>
#include <cstdint>
#include <iostream>

namespace sclMath {
// copy matrix for sclMath::RealMatrix, sclMath::RealMatrix
RealMatrix copyMatrix(const RealMatrix &m);
// copy matrix for sclMath::ComplexMatrix, sclMath::ComplexMatrix
ComplexMatrix copyMatrix(const ComplexMatrix &m);
// TODO: copy real matrix as complex matrix, and viseversa
RealMatrix copyMatrix_asComplex(const ComplexMatrix &m);

// innerProduct
// ###########################################################################################################
// inner Product for sclMath::RealMatrix, sclMath::RealMatrix
RealScalar innerProduct(const RealMatrix &m1, const RealMatrix &m2);
// inner Product for sclMath::ComplexMatrix, sclMath::ComplexMatrix
ComplexScalar innerProduct(const ComplexMatrix &m1, const ComplexMatrix &m2);
// inner Product for sclMath::ComplexMatrix, sclMath::RealMatrix
ComplexScalar innerProduct(const ComplexMatrix &m1, const RealMatrix &m2);
// inner Product for sclMath::RealMatrix, sclMath::ComplexMatrix
ComplexScalar innerProduct(const RealMatrix &m1, const ComplexMatrix &m2);

// distance
// ###########################################################################################################
// distance for sclmath::complexmatrix, sclmath::complexmatrix
ComplexScalar distance(const ComplexMatrix &m1, const ComplexMatrix &m2);
// distance for sclmath::realmatrix, sclmath::realmatrix
RealScalar distance(const RealMatrix &m1, const RealMatrix &m2);
// distance for sclMath::ComplexMatrix, sclMath::RealMatrix
ComplexScalar distance(const ComplexMatrix &m1, const RealMatrix &m2);
// distance for sclMath::RealMatrix, sclMath::ComplexMatrix
ComplexScalar distance(const RealMatrix &m1, const ComplexMatrix &m2);

// angle
// ###########################################################################################################
//  angle for sclMath::ComplexMatrix, sclMath::ComplexMatrix
ComplexScalar angle(const ComplexMatrix &m1, const ComplexMatrix &m2);
//  angle for sclMath::RealMatrix, sclMath::RealMatrix
RealScalar angle(const RealMatrix &m1, const RealMatrix &m2);

} // namespace sclMath

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
