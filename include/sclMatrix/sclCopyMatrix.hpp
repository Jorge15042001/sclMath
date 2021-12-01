#pragma once

#include "sclMatrix.hpp"

namespace sclMath {

// copy matrix for sclMath::ComplexMatrix, sclMath::ComplexMatrix
// copy matrix for sclMath::RealMatrix, sclMath::RealMatrix

template <c_Matrix T_MATRIX, c_Matrix T_OUTPUT = T_MATRIX>
T_OUTPUT copyMatrix(const T_MATRIX &m) {

  typedef typename ScalarTypeOfMatrix<T_MATRIX>::type ScalarType_input;
  typedef typename ScalarTypeOfMatrix<T_OUTPUT>::type ScalarType_output;

  const std::vector<ScalarType_input> &data = m.getDataVector();
  std::vector<ScalarType_output> dataCopy;
  // get enough space to store the data
  dataCopy.reserve(data.size());
  // fill the copy with data from the origicil vector
  dataCopy.insert(dataCopy.end(), data.begin(), data.end());

  T_OUTPUT mCopy(m.getRows(), m.getCols(), std::move(dataCopy));

  return mCopy;
}
} // namespace sclMath
