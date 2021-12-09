#pragma once

#include "sclInnerProduct.hpp"
#include "sclMatrix.hpp"
#include "sclZeroMatrix.hpp"

namespace sclMath {
// implementation
//  angle for sclMath::ComplexMatrix, sclMath::ComplexMatrix
//  angle for sclMath::RealMatrix, sclMath::RealMatrix
//  angle for sclMath::ComplexMatrix, sclMath::RealMatrix
//  angle for sclMath::RealMatrix, sclMath::ComplexMatrix
RealScalar angle(const c_FullMatrix auto &m1, const c_FullMatrix auto &m2) {
  const RealScalar m1Norm = m1.norm();
  const RealScalar m2Norm = m2.norm();

  const RealScalar innerP = std::real(innerProduct(m1, m2));
  return std::acos(innerP / (m1Norm * m2Norm));
}
} // namespace sclMath
