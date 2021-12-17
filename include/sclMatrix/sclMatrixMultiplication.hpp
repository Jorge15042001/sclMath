#pragma once

#include "sclMathErrors.hpp"
#include "sclMatrix.hpp"
// matrix multiplication
// ###########################################################################################################
// overloading operator * for sclMath::ComplexMatrix, sclMath::ComplexMatrix
// overloading operator * for sclMath::RealMatrix, sclMath::RealMatrix
// overloading operator * for sclMath::RealMatrix, sclMath::ComplexMatrix
// overloading operator * for sclMath::ComplexMatrix, sclMath::RealMatrix

sclMath::c_AnyMatrix auto operator*(const sclMath::c_AnyMatrix auto &m1,
                                    const sclMath::c_AnyMatrix auto &m2) {
  // type deduction code
  typedef std::remove_cvref_t<decltype(m1)> m1_type;
  typedef std::remove_cvref_t<decltype(m2)> m2_type;

  typedef typename sclMath::MatrixResultType<m1_type, m2_type>::type MatrixType;
  typedef typename sclMath::MatrixScalarType<MatrixType>::type ScalarType;

  sclMathError::ASSERT2(
      m1.getCols() == m2.getRows(),
      "sclMath::matrix multiplication is not defined, incompatible shapes");
  // if any of the matrices is a ZeroMatrix
  if constexpr (sclMath::anyIsZeroMatrix<m1_type, m2_type>) {
    return sclMath::ZeroMatrix(m1.getRows(), m2.getCols());
  } else {
    /* run standard algorith for matrix multiplication */
    const std::size_t n = m1.getCols();
    const std::size_t rows = m1.getRows();
    const std::size_t cols = m2.getCols();

    MatrixType result(rows, cols);

    for (std::size_t i = 0; i < rows; i++) {
      for (std::size_t j = 0; j < cols; j++) {
        ScalarType sum = 0.0;
        for (std::size_t h = 0; h < n; h++) {
          sum += m1.get(i, h) * m2.get(h, j);
        }
        result.set(i, j, sum);
      }
    }

    return result;
  }
}
