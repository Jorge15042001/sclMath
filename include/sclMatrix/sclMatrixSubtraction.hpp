#pragma once
#include "sclMathErrors.hpp"
#include "sclMatrix.hpp"

// matrix Subtraction
// ###########################################################################################################
// overloading operator - for sclMath::ComplexMatrix, sclMath::ComplexMatrix
// overloading operator - for sclMath::RealMatrix, sclMath::RealMatrix
// overloading operator - for sclMath::RealMatrix, sclMath::ComplexMatrix
// overloading operator - for sclMath::ComplexMatrix, sclMath::RealMatrix

template <sclMath::c_Matrix T_MATRIX1, sclMath::c_Matrix T_MATRIX2>
sclMath::c_Matrix auto operator-(const T_MATRIX1 &m1, const T_MATRIX2 &m2) {

  typedef typename sclMath::resultType<T_MATRIX1, T_MATRIX2>::type ResultType;

  sclMathError::ASSERT2(
      m1.getRows() == m2.getRows(),
      "Subtraction requires both matrices to have the same shape");
  sclMathError::ASSERT2(
      m1.getCols() == m2.getCols(),
      "Subtraction requires both matrices to have the same shape");

  const std::size_t cols = m1.getCols();
  const std::size_t rows = m1.getRows();

  ResultType result(rows, cols);

  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      const sclMath::c_Scalar auto sum = m1.get(i, j) - m2.get(i, j);
      result.set(i, j, sum);
    }
  }
  return result;
}
