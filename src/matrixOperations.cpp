#include "sclMatrixOperations.hpp"
#include "sclMathErrors.h"
#include "sclMathUtility.h"
#include "sclMatrix.hpp"
#include <cmath>
#include <cstdint>
#include <iostream>

namespace sclMath {
matrix copyMatrix(const matrix &m) {
  const std::size_t rows = m.getRows();
  const std::size_t cols = m.getCols();

  matrix mCopy(rows, cols);
  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      mCopy.set(i, j, m.get(i, j));
    }
  }
  return mCopy;
}
ComplexScalar innerProduct(const matrix &m1, const matrix &m2) {
  sclMathError::ASSERT2(
      m1.getRows() == m2.getRows(),
      "Inner Product requires both matrices to have the same shape");
  sclMathError::ASSERT2(
      m1.getCols() == m2.getCols(),
      "Inner Product requires both matrices to have the same shape");

  const matrix m1Dagger = copyMatrix(m1).dagger();
  const matrix mult = m1Dagger * m2;
  return mult.trace();
}
Scalar distance(const matrix &m1, const matrix &m2) {
  matrix diff = m1 - m2;
  return diff.norm();
}

Scalar angle(const matrix &m1, const matrix &m2) {
  const Scalar m1Norm = m1.norm();
  const Scalar m2Norm = m2.norm();

  const ComplexScalar innerP = innerProduct(m1, m2);

  return std::acos(innerP.real() / (m1Norm * m2Norm));
}
} // namespace sclMath
sclMath::matrix operator+(const sclMath::matrix &m1,
                          const sclMath::matrix &m2) {
  sclMathError::ASSERT2(
      m1.getRows() == m2.getRows(),
      "Addition requires both matrices to have the same shape");
  sclMathError::ASSERT2(
      m1.getCols() == m2.getCols(),
      "Addition requires both matrices to have the same shape");

  const std::size_t rows = m1.getRows();
  const std::size_t cols = m1.getCols();
  sclMath::matrix result = sclMath::matrix(rows, cols);

  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      const sclMath::ComplexScalar sum = m1.get(i, j) + m2.get(i, j);
      result.set(i, j, sum);
    }
  }
  return result;
}
sclMath::matrix operator-(const sclMath::matrix &m1,
                          const sclMath::matrix &m2) {
  sclMathError::ASSERT2(
      m1.getRows() == m2.getRows(),
      "Subtraction requires both matrices to have the same shape");
  sclMathError::ASSERT2(
      m1.getCols() == m2.getCols(),
      "Subtraction requires both matrices to have the same shape");

  const std::size_t rows = m1.getRows();
  const std::size_t cols = m1.getCols();
  sclMath::matrix result = sclMath::matrix(rows, cols);

  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      const sclMath::ComplexScalar subs = m1.get(i, j) - m2.get(i, j);
      result.set(i, j, subs);
    }
  }
  return result;
}
sclMath::matrix operator*(const sclMath::matrix &m1,
                          const sclMath::matrix &m2) {
  sclMathError::ASSERT2(
      m1.getCols() == m2.getRows(),
      "sclMath::matrix multiplication is not defined, incompatible shapes");

  const std::size_t n = m1.getCols();
  const std::size_t rows = m1.getRows();
  const std::size_t cols = m2.getCols();

  sclMath::matrix result(rows, cols);

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
sclMath::matrix operator*(const sclMath::ComplexScalar s,
                          const sclMath::matrix &m) {
  sclMath::matrix mCopy = sclMath::copyMatrix(m);
  mCopy.scale(s);
  return mCopy;
}
// TODO: write a test for this function
bool operator==(const sclMath::matrix &m1, const sclMath::matrix &m2) {
  if (m1.getRows() != m2.getRows())
    return false;
  if (m1.getCols() != m2.getCols())
    return false;

  const std::size_t rows = m1.getRows();
  const std::size_t cols = m1.getCols();

  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      if (!sclMathUtility::areaAlmostEqual(m1.get(i, j), m2.get(i, j)))
        return false;
    }
  }
  return true;
}
