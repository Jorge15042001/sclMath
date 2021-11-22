#include "sclMatrix/sclComplexMatrix.hpp"
#include "sclMatrix/sclRealMatrix.hpp"
#include <catch2/catch_test_macros.hpp>

SCENARIO("getting from matrix", "[get]") {
  GIVEN("A comlex matrix of shape (4,4)") {
    sclMath::ComplexMatrix m(4, 4);
    // check the shape
    REQUIRE(m.getRows() == 4);
    REQUIRE(m.getCols() == 4);

    WHEN("it has been created") {
      ; // matrix was initialized in the contstuctor
      THEN("all values must be initialized as 0+0j") {
        REQUIRE(m.get(0, 0) == sclMath::ComplexScalar(0, 0));
        REQUIRE(m.get(0, 1) == sclMath::ComplexScalar(0, 0));
        REQUIRE(m.get(0, 2) == sclMath::ComplexScalar(0, 0));
        REQUIRE(m.get(0, 3) == sclMath::ComplexScalar(0, 0));

        REQUIRE(m.get(1, 0) == sclMath::ComplexScalar(0, 0));
        REQUIRE(m.get(1, 1) == sclMath::ComplexScalar(0, 0));
        REQUIRE(m.get(1, 2) == sclMath::ComplexScalar(0, 0));
        REQUIRE(m.get(1, 3) == sclMath::ComplexScalar(0, 0));

        REQUIRE(m.get(2, 0) == sclMath::ComplexScalar(0, 0));
        REQUIRE(m.get(2, 1) == sclMath::ComplexScalar(0, 0));
        REQUIRE(m.get(2, 2) == sclMath::ComplexScalar(0, 0));
        REQUIRE(m.get(2, 3) == sclMath::ComplexScalar(0, 0));

        REQUIRE(m.get(3, 0) == sclMath::ComplexScalar(0, 0));
        REQUIRE(m.get(3, 1) == sclMath::ComplexScalar(0, 0));
        REQUIRE(m.get(3, 2) == sclMath::ComplexScalar(0, 0));
        REQUIRE(m.get(3, 3) == sclMath::ComplexScalar(0, 0));
      }
    }
    WHEN("index out of range range is requested") {
      ;
      THEN("error should be thrown") {
        CHECK_THROWS(m.get(1, 5));
        CHECK_THROWS(m.get(5, 4));
        CHECK_THROWS(m.get(5, 5));

        CHECK_THROWS(m.get(1, 6));
        CHECK_THROWS(m.get(8, 7));
        CHECK_THROWS(m.get(9, 11));
      }
    }
    WHEN("a negative index is requested") {
      ;
      THEN("error should bw thrown") {
        CHECK_THROWS(m.get(-1, 5));
        CHECK_THROWS(m.get(-1, -5));
        CHECK_THROWS(m.get(3, -5));
        CHECK_THROWS(m.get(-4, 5));
        CHECK_THROWS(m.get(-7, 5));
        CHECK_THROWS(m.get(7, -3));
        CHECK_THROWS(m.get(6, -4));
        CHECK_THROWS(m.get(-6, -4));
        CHECK_THROWS(m.get(-6, -3));
      }
    }
    WHEN("a valid index in requested") {
      ;
      THEN("no errors should be throw ") {
        CHECK_NOTHROW(m.get(0, 0));
        CHECK_NOTHROW(m.get(0, 1));
        CHECK_NOTHROW(m.get(0, 2));
        CHECK_NOTHROW(m.get(0, 3));

        CHECK_NOTHROW(m.get(1, 0));
        CHECK_NOTHROW(m.get(1, 1));
        CHECK_NOTHROW(m.get(1, 2));
        CHECK_NOTHROW(m.get(1, 3));

        CHECK_NOTHROW(m.get(2, 0));
        CHECK_NOTHROW(m.get(2, 1));
        CHECK_NOTHROW(m.get(2, 2));
        CHECK_NOTHROW(m.get(2, 3));

        CHECK_NOTHROW(m.get(3, 0));
        CHECK_NOTHROW(m.get(3, 1));
        CHECK_NOTHROW(m.get(3, 2));
        CHECK_NOTHROW(m.get(3, 3));
      }
    }
  }
  GIVEN("A realMatrix of shape (4,4)") {
    sclMath::RealMatrix m(4, 4);
    // check the shape
    REQUIRE(m.getRows() == 4);
    REQUIRE(m.getCols() == 4);

    WHEN("it has been created") {
      ; // matrix was initialized in the contstuctor
      THEN("all values should be initialized to 0") {
        REQUIRE(m.get(0, 1) == 0);
        REQUIRE(m.get(0, 0) == 0);
        REQUIRE(m.get(0, 2) == 0);
        REQUIRE(m.get(0, 3) == 0);

        REQUIRE(m.get(1, 0) == 0);
        REQUIRE(m.get(1, 1) == 0);
        REQUIRE(m.get(1, 2) == 0);
        REQUIRE(m.get(1, 3) == 0);

        REQUIRE(m.get(2, 0) == 0);
        REQUIRE(m.get(2, 1) == 0);
        REQUIRE(m.get(2, 2) == 0);
        REQUIRE(m.get(2, 3) == 0);

        REQUIRE(m.get(3, 0) == 0);
        REQUIRE(m.get(3, 1) == 0);
        REQUIRE(m.get(3, 2) == 0);
        REQUIRE(m.get(3, 3) == 0);
      }
    }
    WHEN("index out of range range is requested") {
      ;
      THEN("error should be thrown") {
        CHECK_THROWS(m.get(1, 5));
        CHECK_THROWS(m.get(5, 4));
        CHECK_THROWS(m.get(5, 5));

        THEN("all values must be initialized as 0+0j") {
          CHECK_THROWS(m.get(1, 6));
          CHECK_THROWS(m.get(8, 7));
          CHECK_THROWS(m.get(9, 11));
        }
      }
      WHEN("a negative index is requested") {
        ;
        THEN("error should bw thrown") {
          CHECK_THROWS(m.get(-1, 5));
          CHECK_THROWS(m.get(-1, -5));
          CHECK_THROWS(m.get(3, -5));
          CHECK_THROWS(m.get(-4, 5));
          CHECK_THROWS(m.get(-7, 5));
          CHECK_THROWS(m.get(7, -3));
          CHECK_THROWS(m.get(6, -4));
          CHECK_THROWS(m.get(-6, -4));
          CHECK_THROWS(m.get(-6, -3));
        }
      }
      WHEN("a valid index in requested") {
        ;
        THEN("no errors should be throw ") {
          CHECK_NOTHROW(m.get(0, 0));
          CHECK_NOTHROW(m.get(0, 1));
          CHECK_NOTHROW(m.get(0, 2));
          CHECK_NOTHROW(m.get(0, 3));

          CHECK_NOTHROW(m.get(1, 0));
          CHECK_NOTHROW(m.get(1, 1));
          CHECK_NOTHROW(m.get(1, 2));
          CHECK_NOTHROW(m.get(1, 3));

          CHECK_NOTHROW(m.get(2, 0));
          CHECK_NOTHROW(m.get(2, 1));
          CHECK_NOTHROW(m.get(2, 2));
          CHECK_NOTHROW(m.get(2, 3));

          CHECK_NOTHROW(m.get(3, 0));
          CHECK_NOTHROW(m.get(3, 1));
          CHECK_NOTHROW(m.get(3, 2));
          CHECK_NOTHROW(m.get(3, 3));
        }
      }
    }
  }
}
