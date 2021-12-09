#pragma once
#include "sclCopyMatrix.hpp"
#include "sclMatrix.hpp"
// scale matric

// overloading operator * for sclMath::ComplexScalar, sclMath::ComplexMatrix
// overloading operator * for sclMath::RealScalar, sclMath::RealMatrix
// overloading operator * for sclMath::RealScalar, sclMath::ComplexMatrix
// overloading operator * for sclMath::ComplexScalar, sclMath::RealMatrix

template <sclMath::c_Scalar T_SCALAR, sclMath::c_Matrix T_MATRIX>
sclMath::c_Matrix auto operator*(const T_SCALAR s, const T_MATRIX &m) {

  typedef typename sclMath::MatrixScalarType<T_MATRIX>::type MATRIX_ST;
  typedef
      typename sclMath::ScalarResultType<T_SCALAR, MATRIX_ST>::type T_OUTPUT;

  return sclMath::copyMatrix<T_MATRIX, sclMath::Matrix<T_OUTPUT>>(m).scale(s);
}
// overloading operator * for sclMath::ComplexMatrix, sclMath::ComplexScalar
// overloading operator * for sclMath::RealMatrix, sclMath::RealScalar
// overloading operator * for sclMath::RealMatrix, sclMath::ComplexScalar
// overloading operator * for sclMath::ComplexMatrix, sclMath::RealScalar
template <sclMath::c_Matrix T_SCALAR, sclMath::c_Matrix T_MATRIX>

sclMath::c_Matrix auto operator*(const T_MATRIX &m, const T_SCALAR s) {
  return s * m;
}
