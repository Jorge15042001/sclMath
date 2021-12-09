#pragma once

#include "sclMatrix.hpp"
#include "sclMatrixSubtraction.hpp"
namespace sclMath {
// distance
// ###########################################################################################################
// distance for sclmath::complexmatrix, sclmath::complexmatrix
// distance for sclmath::realmatrix, sclmath::realmatrix
// distance for sclMath::ComplexMatrix, sclMath::RealMatrixu
// distance for sclMath::RealMatrix, sclMath::ComplexMatrix
RealScalar distance(const c_FullMatrix auto &m1, const c_FullMatrix auto &m2) {
  return (m1 - m2).norm();
}
} // namespace sclMath
