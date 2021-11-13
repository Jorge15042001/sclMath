#pragma once
#include <cmath>
#include <limits>
#include <iomanip>
#include <iostream>
#include <type_traits>
#include <algorithm>
#include "matrix.h"

namespace sclMathUtility {
  bool areaAlmostEqual(sclMath::ComplexScalar a, sclMath::ComplexScalar b);
  bool areaAlmostEqual(sclMath::Scalar a, sclMath::Scalar b);
  void setUPL(const std::uint64_t);
}
