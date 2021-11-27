#include "sclMatrix/sclMathUtility.hpp"
#include "sclMatrix/sclMatrixComparison.hpp"
#include "sclMatrix/sclMatrixScaling.hpp"
#include <catch2/catch_test_macros.hpp>

SCENARIO("Scalar multiplication ComplexMatrix with ComplexScalar",
         "[scaling]") {
  GIVEN("a complex matrix with all entries set to zero") {
    sclMath::ComplexMatrix m(3, 4);
    WHEN("multiply by any scalar ") {
      sclMath::ComplexMatrix result = sclMath::ComplexScalar{1, 1} * m;
      THEN("the resulting matrix is always a zero matrix") {
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 3), {0, 0}));
      }
    }
    WHEN("multiply by any scalar ") {
      sclMath::ComplexMatrix result = sclMath::ComplexScalar{2, 1} * m;
      THEN("the resulting matrix is always a zero matrix") {
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 3), {0, 0}));
      }
    }
    WHEN("multiply by any scalar ") {
      sclMath::ComplexMatrix result = sclMath::ComplexScalar{1, 3} * m;
      THEN("the resulting matrix is always a zero matrix") {
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 3), {0, 0}));
      }
    }
    WHEN("multiply by any scalar ") {
      sclMath::ComplexMatrix result = sclMath::ComplexScalar{-1, 1} * m;
      THEN("the resulting matrix is always a zero matrix") {
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 3), {0, 0}));
      }
    }
    GIVEN("a complex non-zero matrix ") {
      sclMath::ComplexMatrix m(3, 4);
      const sclMath::ComplexScalar i(0, 1);

      m.set(0, 0, {1});
      m.set(0, 1, {2});
      m.set(0, 3, {4});

      m.set(1, 1, {1, 1});
      m.set(1, 3, {0, 1});

      WHEN("multiply by i ") {
        const sclMath::ComplexScalar i(0, 1);
        sclMath::Matrix result = i * m;
        THEN("the value in each position most be multiply by i") {

          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0),
                                                  m.get(0, 0) * i));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1),
                                                  m.get(0, 1) * i));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2),
                                                  m.get(0, 2) * i));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3),
                                                  m.get(0, 3) * i));

          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0),
                                                  m.get(1, 0) * i));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1),
                                                  m.get(1, 1) * i));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2),
                                                  m.get(1, 2) * i));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3),
                                                  m.get(1, 3) * i));
          // the result must equal the scaling result
          REQUIRE(result == m.scale(i));
        }
      }
      WHEN("multiply by 1 ") {
        const sclMath::ComplexScalar s(1, 0);
        sclMath::Matrix result = s * m;
        THEN("the value in each position most be multiply by i") {
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0),
                                                  m.get(0, 0) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1),
                                                  m.get(0, 1) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2),
                                                  m.get(0, 2) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3),
                                                  m.get(0, 3) * s));

          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0),
                                                  m.get(1, 0) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1),
                                                  m.get(1, 1) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2),
                                                  m.get(1, 2) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3),
                                                  m.get(1, 3) * s));
          // the result must equal the scaling result
          REQUIRE(result == m.scale(s));
        }
      }
      WHEN("multiply by -i ") {
        const sclMath::ComplexScalar s(0, -1);
        sclMath::Matrix result = s * m;
        THEN("the value in each position most be multiply by i") {
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0),
                                                  m.get(0, 0) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1),
                                                  m.get(0, 1) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2),
                                                  m.get(0, 2) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3),
                                                  m.get(0, 3) * s));

          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0),
                                                  m.get(1, 0) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1),
                                                  m.get(1, 1) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2),
                                                  m.get(1, 2) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3),
                                                  m.get(1, 3) * s));
          // the result must equal the scaling result
          REQUIRE(result == m.scale(s));
        }
      }
      WHEN("multiply by 1+i ") {
        const sclMath::ComplexScalar s(1, 1);
        sclMath::Matrix result = s * m;
        THEN("the value in each position most be multiply by i") {
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0),
                                                  m.get(0, 0) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1),
                                                  m.get(0, 1) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2),
                                                  m.get(0, 2) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3),
                                                  m.get(0, 3) * s));

          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0),
                                                  m.get(1, 0) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1),
                                                  m.get(1, 1) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2),
                                                  m.get(1, 2) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3),
                                                  m.get(1, 3) * s));
          // the result must equal the scaling result
          REQUIRE(result == m.scale(s));
        }
      }
    }
  }
}

SCENARIO("Scalar multiplication ComplexMatrix with RealScalar", "[scaling]") {
  GIVEN("a complex matrix with all entries set to zero") {
    sclMath::ComplexMatrix m(3, 4);
    WHEN("multiply by any scalar ") {
      sclMath::ComplexMatrix result = sclMath::RealScalar{1} * m;
      THEN("the resulting matrix is always a zero matrix") {
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 3), {0, 0}));
      }
    }
    WHEN("multiply by any scalar ") {
      sclMath::ComplexMatrix result = sclMath::RealScalar{2} * m;
      THEN("the resulting matrix is always a zero matrix") {
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 3), {0, 0}));
      }
    }
    WHEN("multiply by any scalar ") {
      sclMath::ComplexMatrix result = sclMath::RealScalar{3} * m;
      THEN("the resulting matrix is always a zero matrix") {
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 3), {0, 0}));
      }
    }
    WHEN("multiply by any scalar ") {
      sclMath::ComplexMatrix result = sclMath::RealScalar{-1} * m;
      THEN("the resulting matrix is always a zero matrix") {
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 3), {0, 0}));
      }
    }
    GIVEN("a complex non-zero matrix ") {
      sclMath::ComplexMatrix m(3, 4);
      const sclMath::ComplexScalar i(0, 1);

      m.set(0, 0, {1});
      m.set(0, 1, {2});
      m.set(0, 3, {4});

      m.set(1, 1, {1, 1});
      m.set(1, 3, {0, 1});

      WHEN("multiply by 1 ") {
        const sclMath::RealScalar one(1);
        sclMath::Matrix result = one * m;
        THEN("the value in each position most be multiply by i") {

          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0),
                                                  m.get(0, 0) * one));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1),
                                                  m.get(0, 1) * one));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2),
                                                  m.get(0, 2) * one));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3),
                                                  m.get(0, 3) * one));

          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0),
                                                  m.get(1, 0) * one));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1),
                                                  m.get(1, 1) * one));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2),
                                                  m.get(1, 2) * one));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3),
                                                  m.get(1, 3) * one));
          // the result must equal the scaling result
          REQUIRE(result == m.scale(one));
        }
      }
      WHEN("multiply by 3 ") {
        const sclMath::RealScalar s(3);
        sclMath::Matrix result = s * m;
        THEN("the value in each position most be multiply by i") {
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0),
                                                  m.get(0, 0) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1),
                                                  m.get(0, 1) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2),
                                                  m.get(0, 2) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3),
                                                  m.get(0, 3) * s));

          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0),
                                                  m.get(1, 0) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1),
                                                  m.get(1, 1) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2),
                                                  m.get(1, 2) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3),
                                                  m.get(1, 3) * s));
          // the result must equal the scaling result
          REQUIRE(result == m.scale(s));
        }
      }
      WHEN("multiply by -1 ") {
        const sclMath::RealScalar s(-1);
        sclMath::Matrix result = s * m;
        THEN("the value in each position most be multiply by i") {
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0),
                                                  m.get(0, 0) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1),
                                                  m.get(0, 1) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2),
                                                  m.get(0, 2) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3),
                                                  m.get(0, 3) * s));

          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0),
                                                  m.get(1, 0) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1),
                                                  m.get(1, 1) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2),
                                                  m.get(1, 2) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3),
                                                  m.get(1, 3) * s));
          // the result must equal the scaling result
          REQUIRE(result == m.scale(s));
        }
      }
    }
  }
}

SCENARIO("Scalar multiplication RealMatrix with RealScalar", "[scaling]") {
  GIVEN("a complex matrix with all entries set to zero") {
    sclMath::RealMatrix m(3, 4);
    WHEN("multiply by any scalar ") {
      sclMath::Matrix result = sclMath::RealScalar{1} * m;
      THEN("the resulting matrix is always a zero matrix") {
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 3), {0, 0}));
      }
    }
    WHEN("multiply by any scalar ") {
      sclMath::Matrix result = sclMath::RealScalar{2} * m;
      THEN("the resulting matrix is always a zero matrix") {
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 3), {0, 0}));
      }
    }
    WHEN("multiply by any scalar ") {
      sclMath::Matrix result = sclMath::RealScalar{3} * m;
      THEN("the resulting matrix is always a zero matrix") {
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 3), {0, 0}));
      }
    }
    WHEN("multiply by any scalar ") {
      sclMath::Matrix result = sclMath::RealScalar{-1} * m;
      THEN("the resulting matrix is always a zero matrix") {
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 3), {0, 0}));
      }
    }
    GIVEN("a real non-zero matrix ") {
      sclMath::RealMatrix m(4, 4);
      const sclMath::ComplexScalar i(0, 1);

      m.set(0, 0, {1});
      m.set(0, 1, {2});
      m.set(0, 3, {4});

      m.set(1, 1, {8.8});
      m.set(1, 3, {5});

      WHEN("multiply by 1 ") {
        const sclMath::RealScalar one(1);
        sclMath::Matrix result = one * m;
        THEN("the value in each position most be multiply by i") {

          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0),
                                                  m.get(0, 0) * one));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1),
                                                  m.get(0, 1) * one));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2),
                                                  m.get(0, 2) * one));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3),
                                                  m.get(0, 3) * one));

          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0),
                                                  m.get(1, 0) * one));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1),
                                                  m.get(1, 1) * one));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2),
                                                  m.get(1, 2) * one));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3),
                                                  m.get(1, 3) * one));
          // the result must equal the scaling result
          REQUIRE(result == m.scale(one));
        }
      }
      WHEN("multiply by 3 ") {
        const sclMath::RealScalar s(3);
        sclMath::Matrix result = s * m;
        THEN("the value in each position most be multiply by i") {
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0),
                                                  m.get(0, 0) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1),
                                                  m.get(0, 1) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2),
                                                  m.get(0, 2) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3),
                                                  m.get(0, 3) * s));

          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0),
                                                  m.get(1, 0) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1),
                                                  m.get(1, 1) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2),
                                                  m.get(1, 2) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3),
                                                  m.get(1, 3) * s));
          // the result must equal the scaling result
          REQUIRE(result == m.scale(s));
        }
      }
      WHEN("multiply by -1 ") {
        const sclMath::RealScalar s(-1);
        sclMath::Matrix result = s * m;
        THEN("the value in each position most be multiply by i") {
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0),
                                                  m.get(0, 0) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1),
                                                  m.get(0, 1) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2),
                                                  m.get(0, 2) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3),
                                                  m.get(0, 3) * s));

          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0),
                                                  m.get(1, 0) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1),
                                                  m.get(1, 1) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2),
                                                  m.get(1, 2) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3),
                                                  m.get(1, 3) * s));
          // the result must equal the scaling result
          REQUIRE(result == m.scale(s));
        }
      }
    }
  }
}

SCENARIO("Scalar multiplication RealMatrix with ComplexScalar", "[scaling]") {
  GIVEN("a complex matrix with all entries set to zero") {
    sclMath::RealMatrix m(3, 4);
    WHEN("multiply by any scalar ") {
      sclMath::ComplexMatrix result = sclMath::ComplexScalar{1, 1} * m;
      THEN("the resulting matrix is always a zero matrix") {
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 3), {0, 0}));
      }
    }
    WHEN("multiply by any scalar ") {
      sclMath::ComplexMatrix result = sclMath::ComplexScalar{2, 1} * m;
      THEN("the resulting matrix is always a zero matrix") {
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 3), {0, 0}));
      }
    }
    WHEN("multiply by any scalar ") {
      sclMath::ComplexMatrix result = sclMath::ComplexScalar{1, 3} * m;
      THEN("the resulting matrix is always a zero matrix") {
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 3), {0, 0}));
      }
    }
    WHEN("multiply by any scalar ") {
      sclMath::ComplexMatrix result = sclMath::ComplexScalar{-1, 1} * m;
      THEN("the resulting matrix is always a zero matrix") {
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3), {0, 0}));

        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 0), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 1), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 2), {0, 0}));
        REQUIRE(sclMathUtility::areaAlmostEqual(result.get(2, 3), {0, 0}));
      }
    }
    GIVEN("a real non-zero matrix ") {
      sclMath::RealMatrix m(3, 4);
      const sclMath::ComplexScalar i(0, 1);

      m.set(0, 0, {1});
      m.set(0, 1, {2});
      m.set(0, 3, {4});

      m.set(1, 1, {9.7});
      m.set(1, 3, {2});

      WHEN("multiply by i ") {
        const sclMath::ComplexScalar i(0, 1);
        sclMath::Matrix result = i * m;
        THEN("the value in each position most be multiply by i") {

          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0),
                                                  m.get(0, 0) * i));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1),
                                                  m.get(0, 1) * i));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2),
                                                  m.get(0, 2) * i));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3),
                                                  m.get(0, 3) * i));

          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0),
                                                  m.get(1, 0) * i));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1),
                                                  m.get(1, 1) * i));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2),
                                                  m.get(1, 2) * i));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3),
                                                  m.get(1, 3) * i));
        }
      }
      WHEN("multiply by 1 ") {
        const sclMath::ComplexScalar s(1, 0);
        sclMath::Matrix result = s * m;
        THEN("the value in each position most be multiply by i") {
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0),
                                                  m.get(0, 0) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1),
                                                  m.get(0, 1) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2),
                                                  m.get(0, 2) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3),
                                                  m.get(0, 3) * s));

          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0),
                                                  m.get(1, 0) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1),
                                                  m.get(1, 1) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2),
                                                  m.get(1, 2) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3),
                                                  m.get(1, 3) * s));
        }
      }
      WHEN("multiply by -i ") {
        const sclMath::ComplexScalar s(0, -1);
        sclMath::Matrix result = s * m;
        THEN("the value in each position most be multiply by i") {
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0),
                                                  m.get(0, 0) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1),
                                                  m.get(0, 1) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2),
                                                  m.get(0, 2) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3),
                                                  m.get(0, 3) * s));

          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0),
                                                  m.get(1, 0) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1),
                                                  m.get(1, 1) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2),
                                                  m.get(1, 2) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3),
                                                  m.get(1, 3) * s));
        }
      }
      WHEN("multiply by 1+i ") {
        const sclMath::ComplexScalar s(1, 1);
        sclMath::Matrix result = s * m;
        THEN("the value in each position most be multiply by i") {
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 0),
                                                  m.get(0, 0) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 1),
                                                  m.get(0, 1) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 2),
                                                  m.get(0, 2) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(0, 3),
                                                  m.get(0, 3) * s));

          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 0),
                                                  m.get(1, 0) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 1),
                                                  m.get(1, 1) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 2),
                                                  m.get(1, 2) * s));
          REQUIRE(sclMathUtility::areaAlmostEqual(result.get(1, 3),
                                                  m.get(1, 3) * s));
        }
      }
    }
  }
}
