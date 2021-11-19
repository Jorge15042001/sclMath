#include "sclMatrixMultiplication.hpp"
// matrix multiplication
// ###########################################################################################################
// overloading operator * for sclMath::ComplexMatrix, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator*(const sclMath::ComplexMatrix &m1,
                                 const sclMath::ComplexMatrix &m2) {
  sclMathError::ASSERT2(
      m1.getCols() == m2.getRows(),
      "sclMath::matrix multiplication is not defined, incompatible shapes");

  const std::size_t n = m1.getCols();
  const std::size_t rows = m1.getRows();
  const std::size_t cols = m2.getCols();

  sclMath::ComplexMatrix result(rows, cols);

  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      sclMath::ComplexScalar sum = 0;
      for (std::size_t h = 0; h < n; h++) {
        sum += m1.get(i, h) * m2.get(h, j);
      }
      result.set(i, j, sum);
    }
  }

  return result;
}
// overloading operator * for sclMath::RealMatrix, sclMath::RealMatrix
sclMath::RealMatrix operator*(const sclMath::RealMatrix &m1,
                              const sclMath::RealMatrix &m2) {
  sclMathError::ASSERT2(
      m1.getCols() == m2.getRows(),
      "sclMath::matrix multiplication is not defined, incompatible shapes");

  const std::size_t n = m1.getCols();
  const std::size_t rows = m1.getRows();
  const std::size_t cols = m2.getCols();

  sclMath::RealMatrix result(rows, cols);

  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      sclMath::RealScalar sum = 0;
      for (std::size_t h = 0; h < n; h++) {
        sum += m1.get(i, h) * m2.get(h, j);
      }
      result.set(i, j, sum);
    }
  }

  return result;
}
// overloading operator * for sclMath::RealMatrix, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator*(const sclMath::RealMatrix &m1,
                                 const sclMath::ComplexMatrix &m2) {
  sclMathError::ASSERT2(
      m1.getCols() == m2.getRows(),
      "sclMath::matrix multiplication is not defined, incompatible shapes");

  const std::size_t n = m1.getCols();
  const std::size_t rows = m1.getRows();
  const std::size_t cols = m2.getCols();

  sclMath::ComplexMatrix result(rows, cols);

  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      sclMath::ComplexScalar sum = 0;
      for (std::size_t h = 0; h < n; h++) {
        sum += m1.get(i, h) * m2.get(h, j);
      }
      result.set(i, j, sum);
    }
  }

  return result;
}
// overloading operator * for sclMath::ComplexMatrix, sclMath::RealMatrix
sclMath::ComplexMatrix operator*(const sclMath::ComplexMatrix &m1,
                                 const sclMath::RealMatrix &m2) {
  sclMathError::ASSERT2(
      m1.getCols() == m2.getRows(),
      "sclMath::matrix multiplication is not defined, incompatible shapes");

  const std::size_t n = m1.getCols();
  const std::size_t rows = m1.getRows();
  const std::size_t cols = m2.getCols();

  sclMath::ComplexMatrix result(rows, cols);

  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      sclMath::ComplexScalar sum = 0;
      for (std::size_t h = 0; h < n; h++) {
        sum += m1.get(i, h) * m2.get(h, j);
      }
      result.set(i, j, sum);
    }
  }

  return result;
}
