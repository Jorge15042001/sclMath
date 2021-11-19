#include "sclComplexMatrix.hpp"
#include <catch2/catch_test_macros.hpp>

SCENARIO("dagger of matrix", "[dagger]") {
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

    WHEN("when the dagger operation is applied to the matrix") {

      m.dagger();

      THEN("swaps m[i,j] with conjugate(m[j,i])") {
        REQUIRE(m.get(0, 0) == sclMath::ComplexScalar(0, -1));
        REQUIRE(m.get(3, 1) == sclMath::ComplexScalar(1, -1));
        REQUIRE(m.get(1, 2) == sclMath::ComplexScalar(2, -1.1));
        REQUIRE(m.get(0, 2) == sclMath::ComplexScalar(0.5, -1.2));

        REQUIRE(m.get(2, 2) == sclMath::ComplexScalar(0, 1.1));
        REQUIRE(m.get(2, 0) == sclMath::ComplexScalar(-9, -1));
        REQUIRE(m.get(2, 1) == sclMath::ComplexScalar(-0.4, -1.3));
        REQUIRE(m.get(1, 1) == sclMath::ComplexScalar(0.2, -1.2));
      }
    }
    WHEN("the dagger operation is perform twice") {
      m.dagger().dagger();

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
}
// TODO:fix test messages
