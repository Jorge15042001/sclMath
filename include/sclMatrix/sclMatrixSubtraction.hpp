#pragma once
#include "sclMathErrors.hpp"
#include "sclMatrix.hpp"

// matrix Subtraction
// ###########################################################################################################
// overloading operator - for sclMath::ComplexMatrix, sclMath::ComplexMatrix
// overloading operator - for sclMath::RealMatrix, sclMath::RealMatrix
// overloading operator - for sclMath::RealMatrix, sclMath::ComplexMatrix
// overloading operator - for sclMath::ComplexMatrix, sclMath::RealMatrix

template <sclMath::c_Scalar T_SCALAR1, sclMath::c_Scalar T_SCALAR2>
sclMath::c_Matrix auto operator-(const sclMath::Matrix<T_SCALAR1> &m1,
                                 const sclMath::Matrix<T_SCALAR2> &m2) {

  typedef
      typename sclMath::resultTypeSclar<T_SCALAR1, T_SCALAR2>::type OUTSCALAR_T;

  sclMathError::ASSERT2(
      m1.getRows() == m2.getRows(),
      "Subtraction requires both matrices to have the same shape");
  sclMathError::ASSERT2(
      m1.getCols() == m2.getCols(),
      "Subtraction requires both matrices to have the same shape");

  const std::size_t cols = m1.getCols();
  const std::size_t rows = m1.getRows();

  std::vector<OUTSCALAR_T> result_data(rows * cols);

  std::transform(m1.getDataVector().begin(), m1.getDataVector().end(),
                 m2.getDataVector().begin(), result_data.begin(),
                 std::minus<>());

  return sclMath::Matrix<OUTSCALAR_T>(rows, cols, std::move(result_data));
}
