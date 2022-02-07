#pragma once

#include "sclMathUtility.hpp"
#include "sclMatrix.hpp"

#include <algorithm>>
// == operator for matrices

// overloading operator == for ComplexMatrix
// overloading operator == for realmatrices
// overloading operator == for sclMath::RealMatrix and sclMath::ComplexMatrix
// overloading operator == for sclMath::ComplexMatrix and sclMath::RealMatrix
bool operator==(const sclMath::c_AnyMatrix auto &m1,
                const sclMath::c_AnyMatrix auto &m2) {

  // TODO: introduce abstraction sclMath::isNotFullMatri and use for branching
  // to different behaviour
  typedef std::remove_cvref_t<decltype(m1)> m1_type;
  typedef std::remove_cvref_t<decltype(m2)> m2_type;
  // check if the matrices are the same type

  // check if any two matices are equal
  typedef typename sclMath::MatrixScalarType<m1_type>::type ScalarType1;
  typedef typename sclMath::MatrixScalarType<m2_type>::type ScalarType2;

  if (m1.getRows() != m2.getRows())
    return false;
  if (m1.getCols() != m2.getCols())
    return false;
  // check if all entries are equal
  return std::equal(m1.getDataVector().begin(), m1.getDataVector().end(),
                    m2.getDataVector().begin(),
                    [](const ScalarType1 s1, const ScalarType2 s2) {
                      return sclMathUtility::areaAlmostEqual(s1, s2);
                    });
}
