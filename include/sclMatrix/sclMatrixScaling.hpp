#pragma once
#include "sclCopyMatrix.hpp"
#include "sclMatrix.hpp"
// scale matric

// overloading operator * for sclMath::ComplexScalar, sclMath::ComplexMatrix
// overloading operator * for sclMath::RealScalar, sclMath::RealMatrix
// overloading operator * for sclMath::RealScalar, sclMath::ComplexMatrix
// overloading operator * for sclMath::ComplexScalar, sclMath::RealMatrix

template <sclMath::c_Scalar T_SCALAR1, sclMath::c_Scalar T_SCALAR2>
sclMath::c_Matrix auto operator*(const T_SCALAR1 s,
                                 const sclMath::Matrix<T_SCALAR2> &m) {
  constexpr bool copyDoesNotChangeType =
      std::is_same_v<T_SCALAR1, T_SCALAR2> ||
      std::is_same_v<T_SCALAR2, sclMath::ComplexScalar>;

  if constexpr (copyDoesNotChangeType)
    return sclMath::copyMatrix(m).scale(s);
  else
    return sclMath::copyMatrix<sclMath::RealMatrix, sclMath::ComplexMatrix>(m)
        .scale(s);
}
// overloading operator * for sclMath::ComplexMatrix, sclMath::ComplexScalar
// overloading operator * for sclMath::RealMatrix, sclMath::RealScalar
// overloading operator * for sclMath::RealMatrix, sclMath::ComplexScalar
// overloading operator * for sclMath::ComplexMatrix, sclMath::RealScalar
template <sclMath::c_Scalar T_SCALAR1, sclMath::c_Scalar T_SCALAR2>

sclMath::c_Matrix auto operator*(const sclMath::Matrix<T_SCALAR2> &m,
                                 const T_SCALAR1 s) {
  return s * m;
}
