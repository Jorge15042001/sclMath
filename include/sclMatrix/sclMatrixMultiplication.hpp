#pragma once

#include "sclMathErrors.hpp"
#include "sclMatrix.hpp"
// matrix multiplication
// ###########################################################################################################
// overloading operator * for sclMath::ComplexMatrix, sclMath::ComplexMatrix
// overloading operator * for sclMath::RealMatrix, sclMath::RealMatrix
// overloading operator * for sclMath::RealMatrix, sclMath::ComplexMatrix
// overloading operator * for sclMath::ComplexMatrix, sclMath::RealMatrix

/* template <sclMath::c_Scalar T_SCALAR1, sclMath::c_Scalar T_SCALAR2> */
sclMath::c_FullMatrix auto operator*(const sclMath::c_FullMatrix auto &m1,
                                 const sclMath::c_FullMatrix auto &m2) {

  /* typedef typename sclMath::ScalarResultType<>::type ResultType; */
  typedef typename sclMath::MatrixResultType<
      std::remove_cvref_t<decltype(m1)>,
      std::remove_cvref_t<decltype(m2)>>::type MatrixType;
  typedef typename sclMath::MatrixScalarType<MatrixType>::type ScalarType;

  sclMathError::ASSERT2(
      m1.getCols() == m2.getRows(),
      "sclMath::matrix multiplication is not defined, incompatible shapes");

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
