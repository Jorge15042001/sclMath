#pragma once

#include "sclCopyMatrix.hpp"
#include "sclMathErrors.hpp"
#include "sclMatrix.hpp"
#include "sclMatrixMultiplication.hpp"

#include <type_traits>>

namespace sclMath {

// innerProduct

// inner Product for sclMath::RealMatrix, sclMath::RealMatrix
// inner Product for sclMath::ComplexMatrix, sclMath::ComplexMatrix
// inner Product for sclMath::ComplexMatrix, sclMath::RealMatrix
// inner Product for sclMath::RealMatrix, sclMath::ComplexMatrix
c_Scalar auto innerProduct(const c_FullMatrix auto &m1, const c_FullMatrix auto &m2) {
  sclMathError::ASSERT2(
      m1.getRows() == m2.getRows(),
      "Inner Product requires both matrices to have the same shape");
  sclMathError::ASSERT2(
      m1.getCols() == m2.getCols(),
      "Inner Product requires both matrices to have the same shape");

  return (copyMatrix(m1).dagger() * m2).trace();
}

} // namespace sclMath
