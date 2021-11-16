#include "sclMatrixOperations.hpp"
#include "sclMathUtility.h"
#include "sclMatrix.hpp"
#include <catch2/catch_test_macros.hpp>

#include <cmath>
#include <iostream>
#include <math.h>
#include <vector>

TEST_CASE("real numbers", "[AlmostEqual]") {
  const sclMath::Scalar a = 1;
  const sclMath::Scalar almost_a = a / std::sqrt(2) * std::sqrt(2);

  const sclMath::Scalar b = 2;
  const sclMath::Scalar almost_b = 2 / std::sqrt(3) * std::sqrt(3);

  const sclMath::Scalar c = 1;
  const sclMath::Scalar almost_c = 1 / std::sqrt(7) * std::sqrt(7);

  const sclMath::Scalar d = 0.2;
  const sclMath::Scalar almost_d = 1 / std::sqrt(5) / std::sqrt(5);

  REQUIRE(sclMathUtility::areaAlmostEqual(a, almost_a));
  REQUIRE(sclMathUtility::areaAlmostEqual(b, almost_b));
  REQUIRE(sclMathUtility::areaAlmostEqual(c, almost_c));
  REQUIRE(sclMathUtility::areaAlmostEqual(d, almost_d));
}
TEST_CASE("complex numbers", "[AlmostEqual]") {
  const sclMath::Scalar a = 1;
  const sclMath::Scalar almost_a = a / std::sqrt(2) * std::sqrt(2);

  const sclMath::Scalar b = 2;
  const sclMath::Scalar almost_b = 2 / std::sqrt(3) * std::sqrt(3);

  const sclMath::Scalar c = 1;
  const sclMath::Scalar almost_c = 1 / std::sqrt(7) * std::sqrt(7);

  const sclMath::Scalar d = 0.2;
  const sclMath::Scalar almost_d = 1 / std::sqrt(5) / std::sqrt(5);

  const sclMath::ComplexScalar ac(a, a);
  const sclMath::ComplexScalar almost_ac(almost_a, almost_a);

  const sclMath::ComplexScalar bc(b, b);
  const sclMath::ComplexScalar almost_bc(almost_b, almost_b);

  const sclMath::ComplexScalar cc(c, c);
  const sclMath::ComplexScalar almost_cc(almost_c, almost_c);

  const sclMath::ComplexScalar dc(d, d);
  const sclMath::ComplexScalar almost_dc(almost_d, almost_d);

  REQUIRE(sclMathUtility::areaAlmostEqual(ac, almost_ac));
  REQUIRE(sclMathUtility::areaAlmostEqual(bc, almost_bc));
  REQUIRE(sclMathUtility::areaAlmostEqual(cc, almost_cc));
  REQUIRE(sclMathUtility::areaAlmostEqual(dc, almost_dc));
}
