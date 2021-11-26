#include "sclMatrix/sclMathUtility.hpp"
#include "sclMatrix/sclMatrix.hpp"

#include <catch2/catch_test_macros.hpp>

SCENARIO("normSquared of complex matrix", "[normSquared]") {
  GIVEN("a ComplexMatrix  with all zeros entries") {
    sclMath::ComplexMatrix m(2, 2);
    WHEN("all entries are zero") {
      THEN("the normSquared must be zero") { REQUIRE(m.normSquared() == 0); }
    }
    WHEN("one entry is set to a value") {
      m.set(0, 0, 1);
      THEN("the normSquared is equal to the squared of that value") {
        REQUIRE(m.normSquared() == 1);
      }
    }
    WHEN("another is set to a value") {
      m.set(1, 0, {0, 1});
      THEN("the normSquared is equal to the squared of that value") {
        REQUIRE(sclMathUtility::areaAlmostEqual(m.normSquared(), 1));
      }
    }
    WHEN("another is set to a value") {
      sclMath::ComplexScalar c1{1, 1};
      sclMath::ComplexScalar c1Squared = std::conj(c1) * c1;
      m.set(1, 1, c1);
      THEN("the normSquared is equal to the squared of that value") {
        REQUIRE(sclMathUtility::areaAlmostEqual(m.normSquared(), c1Squared));
      }
    }
    WHEN("multiple values are set as non-zero") {
      const sclMath::c_Scalar auto c1 = sclMath::ComplexScalar{2, 1};
      const sclMath::c_Scalar auto c2 = sclMath::ComplexScalar{2, 4};
      const sclMath::c_Scalar auto c3 = sclMath::ComplexScalar{4, 3};

      const sclMath::c_Scalar auto CSquaredSum =
          std::conj(c1) * c1 + std::conj(c2) * c2 + std::conj(c3) * c3;

      m.set(0, 0, c1);
      m.set(0, 1, c2);
      m.set(1, 0, c3);
      THEN("The normSquared must equal the sum of the squares of all enties") {
        REQUIRE(sclMathUtility::areaAlmostEqual(m.normSquared(), CSquaredSum));

        WHEN("The order of the elements in the matrix are reorder ") {
          // TODO: swap values
          // TODO: clean methood
          m.set(1, 1, c1);
          m.set(0, 0, 0);
          THEN("the norm must not change") {
            REQUIRE(
                sclMathUtility::areaAlmostEqual(m.normSquared(), CSquaredSum));
          }
        }
      }
    }
  }
}
SCENARIO("normSquared of real matrix", "[normSquared]") {
  GIVEN("a RealMatrix  with all zeros entries") {
    sclMath::RealMatrix m(2, 2);
    WHEN("all entries are zero") {
      THEN("the normSquared must be zero") { REQUIRE(m.normSquared() == 0); }
    }
    WHEN("one entry is set to a value") {
      m.set(0, 0, 1);
      THEN("the normSquared is equal to the squared of that value") {
        REQUIRE(m.normSquared() == 1);
      }
    }
    WHEN("another is set to a value") {
      m.set(1, 0, 2);
      THEN("the normSquared is equal to the squared of that value") {
        REQUIRE(sclMathUtility::areaAlmostEqual(m.normSquared(), 4));
      }
    }
    WHEN("another is set to a value") {
      sclMath::RealScalar c1 = 2.2;
      sclMath::RealScalar c1Squared = c1 * c1;
      m.set(1, 1, c1);
      THEN("the normSquared is equal to the squared of that value") {
        REQUIRE(sclMathUtility::areaAlmostEqual(m.normSquared(), c1Squared));
      }
    }
    WHEN("multiple values are set as non-zero") {
      const sclMath::c_Scalar auto s1 = sclMath::RealScalar{9};
      const sclMath::c_Scalar auto s2 = sclMath::RealScalar{3};
      const sclMath::c_Scalar auto s3 = sclMath::RealScalar{5};

      const sclMath::c_Scalar auto S_SquaredSum = s1 * s1 + s2 * s2 + s3 * s3;

      m.set(0, 0, s1);
      m.set(0, 1, s2);
      m.set(1, 0, s3);
      THEN("The normSquared must equal the sum of the squares of all enties") {
        REQUIRE(sclMathUtility::areaAlmostEqual(m.normSquared(), S_SquaredSum));

        WHEN("The order of the elements in the matrix are reorder ") {
          // TODO: swap values
          // TODO: clean methood
          m.set(1, 1, s1);
          m.set(0, 0, 0);
          THEN("the norm must not change") {
            REQUIRE(
                sclMathUtility::areaAlmostEqual(m.normSquared(), S_SquaredSum));
          }
        }
      }
    }
  }
}
