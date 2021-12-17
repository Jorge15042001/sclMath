#pragma once

#include "sclMathErrors.hpp"
#include "sclMatrix.hpp"

#include <algorithm>

// matrix addition
// overloading operator + for sclMath::ComplexMatrix, sclMath::ComplexMatrix
// overloading operator + for sclMath::RealMatrix, sclMath::RealMatrix
// overloading operator + for sclMath::RealMatrix, sclMath::ComplexMatrix
// overloading operator + for sclMath::ComplexMatrix, sclMath::RealMatrix

template <sclMath::c_Scalar T_SCALAR1, sclMath::c_Scalar T_SCALAR2>
sclMath::c_FullMatrix auto operator+(const sclMath::Matrix<T_SCALAR1> &m1,
                                 const sclMath::Matrix<T_SCALAR2> &m2) {

  typedef typename sclMath::ScalarResultType<T_SCALAR1, T_SCALAR2>::type T_OUT;

  sclMathError::ASSERT2(
      m1.getRows() == m2.getRows(),
      "Addition requires both matrices to have the same shape");
  sclMathError::ASSERT2(
      m1.getCols() == m2.getCols(),
      "Addition requires both matrices to have the same shape");

  const std::size_t rows = m1.getRows();
  const std::size_t cols = m1.getCols();

  std::vector<ScalarType> result_data(rows * cols);

  std::transform(m1.getDataVector().begin(), m1.getDataVector().end(),
                 m2.getDataVector().begin(), result_data.begin(),
                 std::plus<>());

  return MatrixType(rows, cols, std::move(result_data));
}
inline sclMath::ZeroMatrix operator+(const sclMath::ZeroMatrix &m1,
                                     const sclMath::ZeroMatrix &m2) {
  sclMathError::ASSERT2(
      m1.getRows() == m2.getRows(),
      "Addition requires both matrices to have the same shape");
  sclMathError::ASSERT2(
      m1.getCols() == m2.getCols(),
      "Addition requires both matrices to have the same shape");
  return sclMath::ZeroMatrix(m1.getRows(), m2.getCols());
}
sclMath::c_FullMatrix auto operator+(const sclMath::ZeroMatrix &m1,
                                     const sclMath::c_FullMatrix auto &m2) {
  sclMathError::ASSERT2(
      m1.getRows() == m2.getRows(),
      "Addition requires both matrices to have the same shape");
  sclMathError::ASSERT2(
      m1.getCols() == m2.getCols(),
      "Addition requires both matrices to have the same shape");
  return sclMath::copyMatrix(m2);
}
sclMath::c_FullMatrix auto operator+(const sclMath::c_FullMatrix auto &m1,
                                     const sclMath::ZeroMatrix &m2) {
  sclMathError::ASSERT2(
      m1.getRows() == m2.getRows(),
      "Addition requires both matrices to have the same shape");
  sclMathError::ASSERT2(
      m1.getCols() == m2.getCols(),
      "Addition requires both matrices to have the same shape");
  return sclMath::copyMatrix(m1);
}
