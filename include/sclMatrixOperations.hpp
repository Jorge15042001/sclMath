#pragma once

#include "sclMathErrors.hpp"
#include "sclMathUtility.hpp"
#include "sclMatrix.hpp"
#include <cmath>
#include <cstdint>
#include <iostream>

namespace sclMath {
// copy matrix for sclMath::ComplexMatrix, sclMath::ComplexMatrix
// copy matrix for sclMath::RealMatrix, sclMath::RealMatrix
// TODO: copy real matrix as complex matrix, and viseversa
template <sclMath::c_ScalarType T_SCALAR, c_ScalarType target_T_SCALAR>
matrix<target_T_SCALAR> copyMatrix(const matrix<T_SCALAR> &m);

// innerProduct
// ###########################################################################################################
// inner Product for sclMath::ComplexMatrix, sclMath::ComplexMatrix
// inner Product for sclMath::RealMatrix, sclMath::RealMatrix
template <sclMath::c_ScalarType T_SCALAR>
T_SCALAR innerProduct(const matrix<T_SCALAR> &m1, const matrix<T_SCALAR> &m2);
// inner Product for sclMath::ComplexMatrix, sclMath::RealMatrix
ComplexScalar innerProduct(const ComplexMatrix &m1, const RealMatrix &m2);
// inner Product for sclMath::RealMatrix, sclMath::ComplexMatrix
ComplexScalar innerProduct(const RealMatrix &m1, const ComplexMatrix &m2);

// distance
// ###########################################################################################################
// distance for sclmath::complexmatrix, sclmath::complexmatrix
// distance for sclmath::realmatrix, sclmath::realmatrix
template <sclMath::c_ScalarType T_SCALAR>
RealScalar distance(const matrix<T_SCALAR> &m1, const matrix<T_SCALAR> &m2);
// distance for sclMath::ComplexMatrix, sclMath::RealMatrix
ComplexScalar distance(const ComplexMatrix &m1, const RealMatrix &m2);
// distance for sclMath::RealMatrix, sclMath::ComplexMatrix
ComplexScalar distance(const RealMatrix &m1, const ComplexMatrix &m2);

// angle
// ###########################################################################################################
//  angle for sclMath::ComplexMatrix, sclMath::ComplexMatrix
//  angle for sclMath::RealMatrix, sclMath::RealMatrix
template <c_ScalarType T_SCALAR>
RealScalar angle(const matrix<T_SCALAR> &m1, const matrix<T_SCALAR> &m2);

} // namespace sclMath

// matrix addition
// ###########################################################################################################
// overloading operator + for sclMath::ComplexMatrix, sclMath::ComplexMatrix
// overloading operator + for sclMath::RealMatrix, sclMath::RealMatrix
template <sclMath::c_ScalarType T_SCALAR>
sclMath::matrix<T_SCALAR> operator+(const sclMath::matrix<T_SCALAR> &m1,
                                    const sclMath::matrix<T_SCALAR> &m2);
// overloading operator + for sclMath::RealMatrix, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator+(const sclMath::RealMatrix &,
                                 const sclMath::ComplexMatrix &);
// overloading operator + for sclMath::ComplexMatrix, sclMath::RealMatrix
sclMath::ComplexMatrix operator+(const sclMath::ComplexMatrix &m1,
                                 const sclMath::RealMatrix &m2);

// matrix Subtraction
// ###########################################################################################################
// overloading operator - for sclMath::ComplexMatrix, sclMath::ComplexMatrix
// overloading operator - for sclMath::RealMatrix, sclMath::RealMatrix
template <sclMath::c_ScalarType T_SCALAR>
sclMath::matrix<T_SCALAR> operator-(const sclMath::matrix<T_SCALAR> &m1,
                                    const sclMath::matrix<T_SCALAR> &m2);
// overloading operator - for sclMath::RealMatrix, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator-(const sclMath::RealMatrix &m1,
                                 const sclMath::ComplexMatrix &m2);
// overloading operator - for sclMath::ComplexMatrix, sclMath::RealMatrix
sclMath::ComplexMatrix operator-(const sclMath::ComplexMatrix &m1,
                                 const sclMath::RealMatrix &m2);

// matrix multiplication
// ###########################################################################################################
// overloading operator * for sclMath::ComplexMatrix, sclMath::ComplexMatrix
// overloading operator * for sclMath::RealMatrix, sclMath::RealMatrix
template <sclMath::c_ScalarType T_SCALAR>
sclMath::matrix<T_SCALAR> operator*(const sclMath::matrix<T_SCALAR> &m1,
                                    const sclMath::matrix<T_SCALAR> &m2);
// overloading operator * for sclMath::RealMatrix, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator*(const sclMath::RealMatrix &m1,
                                 const sclMath::ComplexMatrix &m2);
// overloading operator * for sclMath::ComplexMatrix, sclMath::RealMatrix
sclMath::ComplexMatrix operator*(const sclMath::ComplexMatrix &m1,
                                 const sclMath::RealMatrix &m2);

// scale matric
// ###########################################################################################################
// overloading operator * for sclMath::ComplexScalar, sclMath::ComplexMatrix
// overloading operator * for sclMath::Scalar, sclMath::RealMatrix
template <sclMath::c_ScalarType T_SCALAR>
sclMath::matrix<T_SCALAR> operator*(const T_SCALAR s,
                                    const sclMath::matrix<T_SCALAR> &m);
// overloading operator * for sclMath::Scalar, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator*(const sclMath::RealScalar s,
                                 const sclMath::ComplexMatrix &m);
// overloading operator * for sclMath::ComplexScalar, sclMath::RealMatrix
sclMath::ComplexMatrix operator*(const sclMath::ComplexScalar s,
                                 const sclMath::RealMatrix &m);

// == operator for matrices
// ###########################################################################################################
// TODO: almost equal neeeds to be tested with complex numbers
// TODO: write a test for this function
// TODO: overloading == between sclMath::ComplexMatrix , sclMath::RealMatrix
template <sclMath::c_ScalarType T_SCALAR>
bool operator==(const sclMath::matrix<T_SCALAR> &m1,
                const sclMath::matrix<T_SCALAR> &m2);

namespace sclMath {
// implementation
// ###########################################################################################################
// copy matrix for sclMath::ComplexMatrix, sclMath::ComplexMatrix
// copy matrix for sclMath::RealMatrix, sclMath::RealMatrix
// TODO: copy real matrix as complex matrix, and viseversa
template <sclMath::c_ScalarType T_SCALAR,
          c_ScalarType target_T_SCALAR = T_SCALAR>
matrix<target_T_SCALAR> copyMatrix(const matrix<T_SCALAR> &m) {
  const std::size_t rows = m.getRows();
  const std::size_t cols = m.getCols();

  // TODO: matrix should do its own copy
  // TODO: if not method to get m_data should exists
  matrix<target_T_SCALAR> mCopy(rows, cols);
  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      mCopy.set(i, j, m.get(i, j));
    }
  }
  return mCopy;
}

// inner Product for sclMath::ComplexMatrix, sclMath::ComplexMatrix
// inner Product for sclMath::RealMatrix, sclMath::RealMatrix
template <c_ScalarType T_SCALAR>
T_SCALAR innerProduct(const matrix<T_SCALAR> &m1, const matrix<T_SCALAR> &m2) {
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
// inner Product for sclMath::ComplexMatrix, sclMath::RealMatrix
ComplexScalar innerProduct(const ComplexMatrix &m1, const RealMatrix &m2) {
  sclMathError::ASSERT2(
      m1.getRows() == m2.getRows(),
      "Inner Product requires both matrices to have the same shape");
  sclMathError::ASSERT2(
      m1.getCols() == m2.getCols(),
      "Inner Product requires both matrices to have the same shape");

  const ComplexMatrix m1Dagger =
      copyMatrix<ComplexScalar, ComplexScalar>(m1).dagger();
  const ComplexMatrix mult = m1Dagger * m2;
  return mult.trace();
}
// inner Product for sclMath::RealMatrix, sclMath::ComplexMatrix
ComplexScalar innerProduct(const RealMatrix &m1, const ComplexMatrix &m2) {
  return innerProduct(m2, m1);
}

// distance for sclmath::complexmatrix, sclmath::complexmatrix
// distance for sclmath::realmatrix, sclmath::realmatrix
template <sclMath::c_ScalarType T_SCALAR>
RealScalar distance(const matrix<T_SCALAR> &m1, const matrix<T_SCALAR> &m2) {
  // TODO: check rigth type, is <T_SCALAR> required in this case
  matrix diff = m1 - m2;
  return diff.norm();
}
// distance for sclMath::ComplexMatrix, sclMath::RealMatrix
ComplexScalar distance(const ComplexMatrix &m1, const RealMatrix &m2) {
  ComplexMatrix diff = m1 - m2;
  return diff.norm();
}
// distance for sclMath::RealMatrix, sclMath::ComplexMatrix
ComplexScalar distance(const RealMatrix &m1, const ComplexMatrix &m2) {
  return distance(m2, m1);
}

//  angle for sclMath::ComplexMatrix, sclMath::ComplexMatrix
//  angle for sclMath::RealMatrix, sclMath::RealMatrix
template <c_ScalarType T_SCALAR>
RealScalar angle(const matrix<T_SCALAR> &m1, const matrix<T_SCALAR> &m2) {
  const RealScalar m1Norm = m1.norm();
  const RealScalar m2Norm = m2.norm();

  const ComplexScalar innerP = innerProduct(m1, m2);

  return std::acos(innerP.real() / (m1Norm * m2Norm));
}
} // namespace sclMath

// overloading operator + for sclMath::ComplexMatrix, sclMath::ComplexMatrix
// overloading operator + for sclMath::RealMatrix, sclMath::RealMatrix
template <sclMath::c_ScalarType T_SCALAR>
sclMath::matrix<T_SCALAR> operator+(const sclMath::matrix<T_SCALAR> &m1,
                                    const sclMath::matrix<T_SCALAR> &m2) {
  sclMathError::ASSERT2(
      m1.getRows() == m2.getRows(),
      "Addition requires both matrices to have the same shape");
  sclMathError::ASSERT2(
      m1.getCols() == m2.getCols(),
      "Addition requires both matrices to have the same shape");

  const std::size_t rows = m1.getRows();
  const std::size_t cols = m1.getCols();
  sclMath::matrix<T_SCALAR> result(rows, cols);

  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      const sclMath::ComplexScalar sum = m1.get(i, j) + m2.get(i, j);
      result.set(i, j, sum);
    }
  }
  return result;
}
// overloading operator + for sclMath::RealMatrix, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator+(const sclMath::RealMatrix &m1,
                                 const sclMath::ComplexMatrix &m2) {
  sclMathError::ASSERT2(
      m1.getRows() == m2.getRows(),
      "Addition requires both matrices to have the same shape");
  sclMathError::ASSERT2(
      m1.getCols() == m2.getCols(),
      "Addition requires both matrices to have the same shape");

  const std::size_t rows = m1.getRows();
  const std::size_t cols = m1.getCols();
  sclMath::matrix<sclMath::ComplexScalar> result(rows, cols);

  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      const sclMath::ComplexScalar sum = m1.get(i, j) + m2.get(i, j);
      result.set(i, j, sum);
    }
  }
  return result;
}
// overloading operator + for sclMath::ComplexMatrix, sclMath::RealMatrix
sclMath::ComplexMatrix operator+(const sclMath::ComplexMatrix &m1,
                                 const sclMath::RealMatrix &m2) {
  return m2 + m1;
}
// overloading operator - for sclMath::ComplexMatrix, sclMath::ComplexMatrix
// overloading operator - for sclMath::RealMatrix, sclMath::RealMatrix
template <sclMath::c_ScalarType T_SCALAR>
sclMath::matrix<T_SCALAR> operator-(const sclMath::matrix<T_SCALAR> &m1,
                                    const sclMath::matrix<T_SCALAR> &m2) {
  sclMathError::ASSERT2(
      m1.getRows() == m2.getRows(),
      "Subtraction requires both matrices to have the same shape");
  sclMathError::ASSERT2(
      m1.getCols() == m2.getCols(),
      "Subtraction requires both matrices to have the same shape");

  const std::size_t rows = m1.getRows();
  const std::size_t cols = m1.getCols();
  sclMath::matrix<T_SCALAR> result(rows, cols);

  // TODO: get data as vector and useit like that
  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      const T_SCALAR subs = m1.get(i, j) - m2.get(i, j);
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
  sclMath::matrix<sclMath::ComplexScalar> result(rows, cols);

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

// overloading operator * for sclMath::ComplexMatrix, sclMath::ComplexMatrix
// overloading operator * for sclMath::RealMatrix, sclMath::RealMatrix
template <sclMath::c_ScalarType T_SCALAR>
sclMath::matrix<T_SCALAR> operator*(const sclMath::matrix<T_SCALAR> &m1,
                                    const sclMath::matrix<T_SCALAR> &m2) {
  sclMathError::ASSERT2(
      m1.getCols() == m2.getRows(),
      "sclMath::matrix multiplication is not defined, incompatible shapes");

  const std::size_t n = m1.getCols();
  const std::size_t rows = m1.getRows();
  const std::size_t cols = m2.getCols();

  sclMath::matrix<T_SCALAR> result(rows, cols);

  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      T_SCALAR sum = 0;
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

  sclMath::matrix<sclMath::ComplexScalar> result(rows, cols);

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

  sclMath::matrix<sclMath::ComplexScalar> result(rows, cols);

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

// overloading operator * for sclMath::ComplexScalar, sclMath::ComplexMatrix
// overloading operator * for sclMath::Scalar, sclMath::RealMatrix
template <sclMath::c_ScalarType T_SCALAR>
sclMath::matrix<T_SCALAR> operator*(const T_SCALAR s,
                                    const sclMath::matrix<T_SCALAR> &m) {
  sclMath::matrix mCopy = sclMath::copyMatrix(m);
  mCopy.scale(s);
  return mCopy;
}
// overloading operator * for sclMath::Scalar, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator*(const sclMath::RealScalar s,
                                 const sclMath::ComplexMatrix &m) {
  sclMath::matrix mCopy =
      sclMath::copyMatrix<sclMath::ComplexScalar, sclMath::ComplexScalar>(m);
  mCopy.scale(s);
  return mCopy;
}
// overloading operator * for sclMath::ComplexScalar, sclMath::RealMatrix
sclMath::ComplexMatrix operator*(const sclMath::ComplexScalar s,
                                 const sclMath::RealMatrix &m) {
  // convert the RealMatrix to a complex matrix, so it can be scaled
  sclMath::matrix mCopy =
      sclMath::copyMatrix<sclMath::RealScalar, sclMath::ComplexScalar>(m);
  mCopy.scale(s);
  return mCopy;
}
// TODO: almost equal neeeds to be tested with complex numbers
// TODO: write a test for this function
// TODO: overloading == between sclMath::ComplexMatrix , sclMath::RealMatrix
template <sclMath::c_ScalarType T_SCALAR>
bool operator==(const sclMath::matrix<T_SCALAR> &m1,
                const sclMath::matrix<T_SCALAR> &m2) {
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
