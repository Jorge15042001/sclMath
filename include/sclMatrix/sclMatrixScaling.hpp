#pragma once
#include "sclCopyMatrix.hpp"
#include "sclMatrix.hpp"
// scale matric

// overloading operator * for sclMath::ComplexScalar, sclMath::ComplexMatrix
// overloading operator * for sclMath::Scalar, sclMath::RealMatrix
// overloading operator * for sclMath::Scalar, sclMath::ComplexMatrix
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
template <sclMath::c_Scalar T_SCALAR1, sclMath::c_Scalar T_SCALAR2>

sclMath::c_Matrix auto operator*(const sclMath::Matrix<T_SCALAR2> &m,
                                 const T_SCALAR1 s) {
  return s * m;
}
