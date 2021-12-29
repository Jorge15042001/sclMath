#pragma once

#include "sclMatrix.hpp"

namespace sclMath {

// copy matrix from sclMath::ComplexMatrix, sclMath::ComplexMatrix
// copy matrix from sclMath::RealMatrix, sclMath::RealMatrix
// copy matrix from sclMath::RealMatrix, sclMath::ComplexMatrix

// INVALID copy matrix from sclMath::ComplexMatrix, sclMath::RealMatrix

template <c_AnyMatrix T_MATRIX, c_AnyMatrix T_OUTPUT = T_MATRIX>
T_OUTPUT copyMatrix(const T_MATRIX &m) {
  if constexpr (isZeroMatrix<T_MATRIX>) {
    return T_OUTPUT(m);
  } else {
    typedef typename MatrixScalarType<T_MATRIX>::type ScalarType_input;
    typedef typename MatrixScalarType<T_OUTPUT>::type ScalarType_output;

    const std::vector<ScalarType_input> &data = m.getDataVector();
    std::vector<ScalarType_output> dataCopy;
    // get enough space to store the data
    dataCopy.reserve(data.size());
    // fill the copy with data from the origicil vector
    dataCopy.insert(dataCopy.end(), data.begin(), data.end());

    T_OUTPUT mCopy(m.getRows(), m.getCols(), std::move(dataCopy));

    return mCopy;
  }
}

} // namespace sclMath
