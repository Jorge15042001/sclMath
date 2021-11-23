#include "sclMatrix/sclMathUtility.hpp"
#include <catch2/catch_test_macros.hpp>

#include <cmath>

TEST_CASE("real numbers", "[AlmostEqual]") {
  const sclMath::RealScalar a = 1;
  const sclMath::RealScalar almost_a = a / std::sqrt(2) * std::sqrt(2);

  const sclMath::RealScalar b = 2;
  const sclMath::RealScalar almost_b = 2 / std::sqrt(3) * std::sqrt(3);

  const sclMath::RealScalar c = 1;
  const sclMath::RealScalar almost_c = 1 / std::sqrt(7) * std::sqrt(7);

  const sclMath::RealScalar d = 0.2;
  const sclMath::RealScalar almost_d = 1 / std::sqrt(5) / std::sqrt(5);

  REQUIRE(sclMathUtility::areaAlmostEqual(a, almost_a));
  REQUIRE(sclMathUtility::areaAlmostEqual(b, almost_b));
  REQUIRE(sclMathUtility::areaAlmostEqual(c, almost_c));
  REQUIRE(sclMathUtility::areaAlmostEqual(d, almost_d));

  REQUIRE_FALSE(sclMathUtility::areaAlmostEqual(a, b));
  REQUIRE_FALSE(sclMathUtility::areaAlmostEqual(b, c));
  REQUIRE_FALSE(sclMathUtility::areaAlmostEqual(a, d));
  REQUIRE_FALSE(sclMathUtility::areaAlmostEqual(c, d));
  REQUIRE_FALSE(sclMathUtility::areaAlmostEqual(b, d));
}
TEST_CASE("complex numbers", "[AlmostEqual]") {
  const sclMath::RealScalar a = 1;
  const sclMath::RealScalar almost_a = a / std::sqrt(2) * std::sqrt(2);

  const sclMath::RealScalar b = 2;
  const sclMath::RealScalar almost_b = 2 / std::sqrt(3) * std::sqrt(3);

  const sclMath::RealScalar c = 1;
  const sclMath::RealScalar almost_c = 1 / std::sqrt(7) * std::sqrt(7);

  const sclMath::RealScalar d = 0.2;
  const sclMath::RealScalar almost_d = 1 / std::sqrt(5) / std::sqrt(5);

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
  REQUIRE(sclMathUtility::areaAlmostEqual(dc, almost_dc));

  REQUIRE(sclMathUtility::areaAlmostEqual(almost_ac, almost_cc));

  REQUIRE_FALSE(sclMathUtility::areaAlmostEqual(ac, bc));
  REQUIRE_FALSE(sclMathUtility::areaAlmostEqual(bc, cc));
  REQUIRE_FALSE(sclMathUtility::areaAlmostEqual(ac, dc));
  REQUIRE_FALSE(sclMathUtility::areaAlmostEqual(cc, dc));
  REQUIRE_FALSE(sclMathUtility::areaAlmostEqual(bc, dc));
}

TEST_CASE("ComplexNumbers with real Numbers", "[AlmostEqual]") {
  const sclMath::RealScalar a = 1;
  const sclMath::RealScalar almost_a = a / std::sqrt(2) * std::sqrt(2);

  const sclMath::RealScalar b = 2;
  const sclMath::RealScalar almost_b = 2 / std::sqrt(3) * std::sqrt(3);

  const sclMath::RealScalar c = 1;
  const sclMath::RealScalar almost_c = 1 / std::sqrt(7) * std::sqrt(7);

  const sclMath::RealScalar d = 0.2;
  const sclMath::RealScalar almost_d = 1 / std::sqrt(5) / std::sqrt(5);

  const sclMath::ComplexScalar almost_ac(almost_a);
  const sclMath::ComplexScalar almost_bc(almost_b);
  const sclMath::ComplexScalar almost_cc(almost_c);
  const sclMath::ComplexScalar almost_dc(almost_d);

  REQUIRE(sclMathUtility::areaAlmostEqual(a, almost_ac));
  REQUIRE(sclMathUtility::areaAlmostEqual(b, almost_bc));
  REQUIRE(sclMathUtility::areaAlmostEqual(c, almost_cc));
  REQUIRE(sclMathUtility::areaAlmostEqual(d, almost_dc));

  REQUIRE_FALSE(sclMathUtility::areaAlmostEqual(a, almost_bc));
  REQUIRE_FALSE(sclMathUtility::areaAlmostEqual(b, almost_cc));
  REQUIRE_FALSE(sclMathUtility::areaAlmostEqual(a, almost_dc));
  REQUIRE_FALSE(sclMathUtility::areaAlmostEqual(c, almost_dc));
  REQUIRE_FALSE(sclMathUtility::areaAlmostEqual(b, almost_dc));
}
