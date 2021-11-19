

#include "sclMatrix.hpp"
#include "sclMatrixOperations.hpp"
#include <catch2/catch_test_macros.hpp>
#include <cstdlib>
#include <iostream>
#include <vector>
SCENARIO("transpose of ComplexMatrix", "[transpose]") {
  GIVEN("A comlex matrix of shape (3,4)") {
    sclMath::ComplexMatrix m(3, 4);
    // check the shape
    REQUIRE(m.getRows() == 3);
    REQUIRE(m.getCols() == 4);

    // setting up the state of the matrix
    m.set(0, 0, sclMath::ComplexScalar(0, 1));
    m.set(1, 3, sclMath::ComplexScalar(1, 1));
    m.set(2, 1, sclMath::ComplexScalar(2, 1.1));
    m.set(2, 0, sclMath::ComplexScalar(0.5, 1.2));

    m.set(2, 2, sclMath::ComplexScalar(0, -1.1));
    m.set(0, 2, sclMath::ComplexScalar(-9, 1));
    m.set(1, 2, sclMath::ComplexScalar(-0.4, 1.3));
    m.set(1, 1, sclMath::ComplexScalar(0.2, 1.2));

    WHEN("when the matrix is transposed") {

      m.transpose();

      THEN("swaps m[i,j] with m[j,i]") {
        REQUIRE(m.get(0, 0) == sclMath::ComplexScalar(0, 1));
        REQUIRE(m.get(3, 1) == sclMath::ComplexScalar(1, 1));
        REQUIRE(m.get(1, 2) == sclMath::ComplexScalar(2, 1.1));
        REQUIRE(m.get(0, 2) == sclMath::ComplexScalar(0.5, 1.2));

        REQUIRE(m.get(2, 2) == sclMath::ComplexScalar(0, -1.1));
        REQUIRE(m.get(2, 0) == sclMath::ComplexScalar(-9, 1));
        REQUIRE(m.get(2, 1) == sclMath::ComplexScalar(-0.4, 1.3));
        REQUIRE(m.get(1, 1) == sclMath::ComplexScalar(0.2, 1.2));
      }
    }
    WHEN("the matrix is conjugated twice ") {
      m.transpose().transpose();

      THEN("the value at each position should e the same ") {
        REQUIRE(m.get(0, 0) == sclMath::ComplexScalar(0, 1));
        REQUIRE(m.get(1, 3) == sclMath::ComplexScalar(1, 1));
        REQUIRE(m.get(2, 1) == sclMath::ComplexScalar(2, 1.1));
        REQUIRE(m.get(2, 0) == sclMath::ComplexScalar(0.5, 1.2));

        REQUIRE(m.get(2, 2) == sclMath::ComplexScalar(0, -1.1));
        REQUIRE(m.get(0, 2) == sclMath::ComplexScalar(-9, 1));
        REQUIRE(m.get(1, 2) == sclMath::ComplexScalar(-0.4, 1.3));
        REQUIRE(m.get(1, 1) == sclMath::ComplexScalar(0.2, 1.2));
      }
    }
  }
  GIVEN("A real matrix of shape (3,4)") {
    sclMath::RealMatrix m(3, 4);
    // check the shape
    REQUIRE(m.getRows() == 3);
    REQUIRE(m.getCols() == 4);

    // setting up the state of the matrix
    m.set(0, 0, 1);
    m.set(1, 3, 2);
    m.set(2, 1, 1);
    m.set(2, 0, 1.2);

    m.set(2, 2, .1);
    m.set(0, 2, 3);
    m.set(1, 2, 1.3);
    m.set(1, 1, 1.2);

    WHEN("when the matrix is transposed") {

      m.transpose();

      THEN("swaps m[i,j] with m[j,i]") {
        REQUIRE(m.get(0, 0) == 1);
        REQUIRE(m.get(3, 1) == 2);
        REQUIRE(m.get(1, 2) == 1);
        REQUIRE(m.get(0, 2) == 1.2);

        REQUIRE(m.get(2, 2) == .1);
        REQUIRE(m.get(2, 0) == 3);
        REQUIRE(m.get(2, 1) == 1.3);
        REQUIRE(m.get(1, 1) == 1.2);
      }
    }
    WHEN("the matrix is conjugated twice ") {
      m.transpose().transpose();

      THEN("the value at each position should e the same ") {
        REQUIRE(m.get(0, 0) == 1);
        REQUIRE(m.get(1, 3) == 2);
        REQUIRE(m.get(2, 1) == 1);
        REQUIRE(m.get(2, 0) == 1.2);

        REQUIRE(m.get(2, 2) == .1);
        REQUIRE(m.get(0, 2) == 3);
        REQUIRE(m.get(1, 2) == 1.3);
        REQUIRE(m.get(1, 1) == 1.2);
      }
    }
  }
}
