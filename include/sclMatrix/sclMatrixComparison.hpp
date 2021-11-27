#pragma once

#include "sclMathUtility.hpp"
#include "sclMatrix.hpp"
// == operator for matrices

// TODO: almost equal neeeds to be tested with complex numbers

// overloading operator == for ComplexMatrix
// overloading operator == for realmatrices
// overloading operator == for sclMath::RealMatrix and sclMath::ComplexMatrix
// overloading operator == for sclMath::ComplexMatrix and sclMath::RealMatrix
bool operator==(const sclMath::c_Matrix auto &m1,
                const sclMath::c_Matrix auto &m2) {
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
