#include "sclMatrixSubtraction.hpp"
// matrix Subtraction
// ###########################################################################################################
// overloading operator - for sclMath::ComplexMatrix, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator-(const sclMath::ComplexMatrix &m1,
                                 const sclMath::ComplexMatrix &m2) {
  sclMathError::ASSERT2(
      m1.getRows() == m2.getRows(),
      "Subtraction requires both matrices to have the same shape");
  sclMathError::ASSERT2(
      m1.getCols() == m2.getCols(),
      "Subtraction requires both matrices to have the same shape");

  const std::size_t rows = m1.getRows();
  const std::size_t cols = m1.getCols();
  sclMath::ComplexMatrix result(rows, cols);

  // TODO: get data as vector and useit like that
  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      const sclMath::ComplexScalar subs = m1.get(i, j) - m2.get(i, j);
      result.set(i, j, subs);
    }
  }
  return result;
}
// overloading operator - for sclMath::RealMatrix, sclMath::RealMatrix
sclMath::RealMatrix operator-(const sclMath::RealMatrix &m1,
                              const sclMath::RealMatrix &m2) {
  sclMathError::ASSERT2(
      m1.getRows() == m2.getRows(),
      "Subtraction requires both matrices to have the same shape");
  sclMathError::ASSERT2(
      m1.getCols() == m2.getCols(),
      "Subtraction requires both matrices to have the same shape");

  const std::size_t rows = m1.getRows();
  const std::size_t cols = m1.getCols();
  sclMath::RealMatrix result(rows, cols);

  // TODO: get data as vector and useit like that
  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      const sclMath::RealScalar subs = m1.get(i, j) - m2.get(i, j);
      result.set(i, j, subs);
    }
  }
  return result;
}
// overloading operator - for sclMath::RealMatrix, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator-(const sclMath::RealMatrix &m1,
                                 const sclMath::ComplexMatrix &m2) {
  sclMathError::ASSERT2(
      m1.getRows() == m2.getRows(),
      "Subtraction requires both matrices to have the same shape");
  sclMathError::ASSERT2(
      m1.getCols() == m2.getCols(),
      "Subtraction requires both matrices to have the same shape");

  const std::size_t rows = m1.getRows();
  const std::size_t cols = m1.getCols();
  sclMath::ComplexMatrix result(rows, cols);

  // TODO: get data as vector and useit like that
  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      const sclMath::ComplexScalar subs = m1.get(i, j) - m2.get(i, j);
      result.set(i, j, subs);
    }
  }
  return result;
}
// overloading operator - for sclMath::ComplexMatrix, sclMath::RealMatrix
sclMath::ComplexMatrix operator-(const sclMath::ComplexMatrix &m1,
                                 const sclMath::RealMatrix &m2) {
  return m2 - m1;
}