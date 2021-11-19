#pragma once
#include "sclComplexMatrix.hpp"
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <type_traits>

namespace sclMathUtility {
bool areaAlmostEqual(sclMath::ComplexScalar a, sclMath::ComplexScalar b);
bool areaAlmostEqual(sclMath::RealScalar a, sclMath::RealScalar b);
void setUPL(const std::uint64_t);
} // namespace sclMathUtility
