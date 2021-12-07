#pragma once

#include "sclMathUtility.hpp"
#include "sclMatrix.hpp"

#include <algorithm>>
// == operator for matrices

// overloading operator == for ComplexMatrix
// overloading operator == for realmatrices
// overloading operator == for sclMath::RealMatrix and sclMath::ComplexMatrix
// overloading operator == for sclMath::ComplexMatrix and sclMath::RealMatrix
template <sclMath::c_Scalar TS1, sclMath::c_Scalar TS2>
bool operator==(const sclMath::Matrix<TS1> &m1,
                const sclMath::Matrix<TS2> &m2) {

  if (m1.getRows() != m2.getRows())
    return false;
  if (m1.getCols() != m2.getCols())
    return false;

  return std::equal(m1.getDataVector().begin(), m1.getDataVector().end(),
                    m2.getDataVector().begin(), [](const TS1 s1, const TS2 s2) {
                      return sclMathUtility::areaAlmostEqual(s1, s2);
                    });
}
