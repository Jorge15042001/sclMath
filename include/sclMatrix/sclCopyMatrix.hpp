#pragma once

#include "sclMatrix.hpp"

namespace sclMath {

inline RealMatrix copyMatrix(const RealMatrix &m) {
  const std::size_t rows = m.getRows();
  const std::size_t cols = m.getCols();

  // TODO: matrix should do its own copy
  // TODO: if not method to get m_data should exists
  RealMatrix mCopy(rows, cols);
  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      mCopy.set(i, j, m.get(i, j));
    }
  }
  return mCopy;
}
// copy matrix for sclMath::ComplexMatrix, sclMath::ComplexMatrix
inline ComplexMatrix copyMatrix(const ComplexMatrix &m) {
  const std::size_t rows = m.getRows();
  const std::size_t cols = m.getCols();

  // TODO: matrix should do its own copy
  // TODO: if not method to get m_data should exists
  ComplexMatrix mCopy(rows, cols);
  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      mCopy.set(i, j, m.get(i, j));
    }
  }
  return mCopy;
}
// TODO: copy real matrix as complex matrix, and viseversa
inline ComplexMatrix copyMatrix_asComplex(const RealMatrix &m) {
  const std::size_t rows = m.getRows();
  const std::size_t cols = m.getCols();

  // TODO: matrix should do its own copy
  // TODO: if not method to get m_data should exists
  ComplexMatrix mCopy(rows, cols);
  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      mCopy.set(i, j, m.get(i, j));
    }
  }
  return mCopy;
}
} // namespace sclMath
