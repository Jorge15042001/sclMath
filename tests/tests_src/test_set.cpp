#include "sclMatrix.hpp"
#include "sclMatrixOperations.hpp"
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <vector>

SCENARIO("setting in matrix", "[set]") {
  GIVEN("A comlex matrix of shape (4,4)") {
    sclMath::ComplexMatrix m(4, 4);
    // check the shape
    REQUIRE(m.getRows() == 4);
    REQUIRE(m.getCols() == 4);

    WHEN("index out of range range is requested") {
      ;
      THEN("error should be thrown") {
        CHECK_THROWS(m.set(1, 5, sclMath::ComplexScalar(0, 0)));
        CHECK_THROWS(m.set(5, 4, sclMath::ComplexScalar(0, 0)));
        CHECK_THROWS(m.set(5, 5, sclMath::ComplexScalar(0, 0)));

        CHECK_THROWS(m.set(1, 6, sclMath::ComplexScalar(0, 0)));
        CHECK_THROWS(m.set(8, 7, sclMath::ComplexScalar(0, 0)));
        CHECK_THROWS(m.set(9, 11, sclMath::ComplexScalar(0, 0)));
      }
    }
    WHEN("a negative index is requested") {
      ;
      THEN("error should bw thrown") {
        CHECK_THROWS(m.set(-1, 5, sclMath::ComplexScalar(0, 0)));
        CHECK_THROWS(m.set(-1, -5, sclMath::ComplexScalar(0, 0)));
        CHECK_THROWS(m.set(3, -5, sclMath::ComplexScalar(0, 0)));
        CHECK_THROWS(m.set(-4, 5, sclMath::ComplexScalar(0, 0)));
        CHECK_THROWS(m.set(-7, 5, sclMath::ComplexScalar(0, 0)));
        CHECK_THROWS(m.set(7, -3, sclMath::ComplexScalar(0, 0)));
        CHECK_THROWS(m.set(6, -4, sclMath::ComplexScalar(0, 0)));
        CHECK_THROWS(m.set(-6, -4, sclMath::ComplexScalar(0, 0)));
        CHECK_THROWS(m.set(-6, -3, sclMath::ComplexScalar(0, 0)));
      }
    }
    WHEN("a valid index in requested") {
      ;
      THEN("no errors should be throw ") {
        CHECK_NOTHROW(m.set(0, 0, sclMath::ComplexScalar(0, 0)));
        CHECK_NOTHROW(m.set(0, 1, sclMath::ComplexScalar(0, 0)));
        CHECK_NOTHROW(m.set(0, 2, sclMath::ComplexScalar(0, 0)));
        CHECK_NOTHROW(m.set(0, 3, sclMath::ComplexScalar(0, 0)));

        CHECK_NOTHROW(m.set(1, 0, sclMath::ComplexScalar(0, 0)));
        CHECK_NOTHROW(m.set(1, 1, sclMath::ComplexScalar(0, 0)));
        CHECK_NOTHROW(m.set(1, 2, sclMath::ComplexScalar(0, 0)));
        CHECK_NOTHROW(m.set(1, 3, sclMath::ComplexScalar(0, 0)));

        CHECK_NOTHROW(m.set(2, 0, sclMath::ComplexScalar(0, 0)));
        CHECK_NOTHROW(m.set(2, 1, sclMath::ComplexScalar(0, 0)));
        CHECK_NOTHROW(m.set(2, 2, sclMath::ComplexScalar(0, 0)));
        CHECK_NOTHROW(m.set(2, 3, sclMath::ComplexScalar(0, 0)));

        CHECK_NOTHROW(m.set(3, 0, sclMath::ComplexScalar(0, 0)));
        CHECK_NOTHROW(m.set(3, 1, sclMath::ComplexScalar(0, 0)));
        CHECK_NOTHROW(m.set(3, 2, sclMath::ComplexScalar(0, 0)));
        CHECK_NOTHROW(m.set(3, 3, sclMath::ComplexScalar(0, 0)));
      }
    }
  }

  GIVEN("A real matrix of shape (4,4)") {
    sclMath::RealMatrix m(4, 4);
    // check the shape
    REQUIRE(m.getRows() == 4);
    REQUIRE(m.getCols() == 4);

    WHEN("index out of range range is requested") {
      ;
      THEN("error should be thrown") {
        CHECK_THROWS(m.set(1, 5, 0));
        CHECK_THROWS(m.set(5, 4, 0));
        CHECK_THROWS(m.set(5, 5, 0));

        CHECK_THROWS(m.set(1, 6, 0));
        CHECK_THROWS(m.set(8, 7, 0));
        CHECK_THROWS(m.set(9, 11, 0));
      }
    }
    WHEN("a negative index is requested") {
      ;
      THEN("error should bw thrown") {
        CHECK_THROWS(m.set(-1, 5, 0));
        CHECK_THROWS(m.set(-1, -5, 0));
        CHECK_THROWS(m.set(3, -5, 0));
        CHECK_THROWS(m.set(-4, 5, 0));
        CHECK_THROWS(m.set(-7, 5, 0));
        CHECK_THROWS(m.set(7, -3, 0));
        CHECK_THROWS(m.set(6, -4, 0));
        CHECK_THROWS(m.set(-6, -4, 0));
        CHECK_THROWS(m.set(-6, -3, 0));
      }
    }
    WHEN("a valid index in requested") {
      ;
      THEN("no errors should be throw ") {
        CHECK_NOTHROW(m.set(0, 0, 0));
        CHECK_NOTHROW(m.set(0, 1, 0));
        CHECK_NOTHROW(m.set(0, 2, 0));
        CHECK_NOTHROW(m.set(0, 3, 0));

        CHECK_NOTHROW(m.set(1, 0, 0));
        CHECK_NOTHROW(m.set(1, 1, 0));
        CHECK_NOTHROW(m.set(1, 2, 0));
        CHECK_NOTHROW(m.set(1, 3, 0));

        CHECK_NOTHROW(m.set(2, 0, 0));
        CHECK_NOTHROW(m.set(2, 1, 0));
        CHECK_NOTHROW(m.set(2, 2, 0));
        CHECK_NOTHROW(m.set(2, 3, 0));

        CHECK_NOTHROW(m.set(3, 0, 0));
        CHECK_NOTHROW(m.set(3, 1, 0));
        CHECK_NOTHROW(m.set(3, 2, 0));
        CHECK_NOTHROW(m.set(3, 3, 0));
      }
    }
  }
}
