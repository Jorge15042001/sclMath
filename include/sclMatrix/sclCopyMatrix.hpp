#pragma once

#include "sclMatrix.hpp"

namespace sclMath {

// copy matrix for sclMath::ComplexMatrix, sclMath::ComplexMatrix
// copy matrix for sclMath::RealMatrix, sclMath::RealMatrix

template <c_Matrix T_MATRIX, c_Matrix T_OUTPUT = T_MATRIX>
T_OUTPUT copyMatrix(const T_MATRIX &m) {
  const std::size_t rows = m.getRows();
  const std::size_t cols = m.getCols();

  T_OUTPUT mCopy(rows, cols);
  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      mCopy.set(i, j, m.get(i, j));
    }
  }
  return mCopy;
}
} // namespace sclMath
