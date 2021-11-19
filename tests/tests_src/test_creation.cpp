#include "sclMatrix.hpp"
#include "sclMatrixOperations.hpp"
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <vector>

TEST_CASE("square matrix creation", "[creation]") {
  // prove square matrix
  sclMath::ComplexMatrix m1(2, 2);
  REQUIRE(m1.getRows() == 2);
  REQUIRE(m1.getCols() == 2);

  sclMath::RealMatrix m2(4, 4);
  REQUIRE(m2.getRows() == 4);
  REQUIRE(m2.getCols() == 4);

  sclMath::RealMatrix m3(10, 10);
  REQUIRE(m3.getRows() == 10);
  REQUIRE(m3.getCols() == 10);

  sclMath::ComplexMatrix m4(10, 10);
  REQUIRE(m4.getRows() == 10);
  REQUIRE(m4.getCols() == 10);
}

TEST_CASE("non-squre matrix creation", "[creation]") {
  // non square matrices
  sclMath::RealMatrix m4(1, 3);
  REQUIRE(m4.getRows() == 1);
  REQUIRE(m4.getCols() == 3);

  sclMath::RealMatrix m5(4, 1);
  REQUIRE(m5.getRows() == 4);
  REQUIRE(m5.getCols() == 1);

  sclMath::ComplexMatrix m6(2, 5);
  REQUIRE(m6.getRows() == 2);
  REQUIRE(m6.getCols() == 5);

  sclMath::ComplexMatrix m7(4, 7);
  REQUIRE(m7.getRows() == 4);
  REQUIRE(m7.getCols() == 7);
}

TEST_CASE("empty matrix creation", "[creation]") {

  // empty matrix
  CHECK_THROWS(sclMath::RealMatrix(0, 1));
  CHECK_THROWS(sclMath::RealMatrix(0, 4));
  CHECK_THROWS(sclMath::RealMatrix(0, 10));
  CHECK_THROWS(sclMath::RealMatrix(0, 5));
  CHECK_THROWS(sclMath::RealMatrix(0, 21));

  CHECK_THROWS(sclMath::RealMatrix(1, 0));
  CHECK_THROWS(sclMath::RealMatrix(3, 0));
  CHECK_THROWS(sclMath::RealMatrix(7, 0));
  CHECK_THROWS(sclMath::RealMatrix(8, 0));
  CHECK_THROWS(sclMath::RealMatrix(22, 0));

  CHECK_THROWS(sclMath::ComplexMatrix(0, 1));
  CHECK_THROWS(sclMath::ComplexMatrix(0, 4));
  CHECK_THROWS(sclMath::ComplexMatrix(0, 10));
  CHECK_THROWS(sclMath::ComplexMatrix(0, 5));
  CHECK_THROWS(sclMath::ComplexMatrix(0, 21));

  CHECK_THROWS(sclMath::ComplexMatrix(1, 0));
  CHECK_THROWS(sclMath::ComplexMatrix(3, 0));
  CHECK_THROWS(sclMath::ComplexMatrix(7, 0));
  CHECK_THROWS(sclMath::ComplexMatrix(8, 0));
  CHECK_THROWS(sclMath::ComplexMatrix(22, 0));
}

TEST_CASE("negative size matrix", "[creation]") {
  CHECK_THROWS(sclMath::RealMatrix(-1, 2));
  CHECK_THROWS(sclMath::RealMatrix(-3, 10));
  CHECK_THROWS(sclMath::RealMatrix(-8, 0));
  CHECK_THROWS(sclMath::RealMatrix(-2, 2));
  CHECK_THROWS(sclMath::RealMatrix(-9, 10));
  CHECK_THROWS(sclMath::RealMatrix(-18, 0));

  CHECK_THROWS(sclMath::RealMatrix(2, -1));
  CHECK_THROWS(sclMath::RealMatrix(1, -10));
  CHECK_THROWS(sclMath::RealMatrix(0, -1));
  CHECK_THROWS(sclMath::RealMatrix(2, -4));
  CHECK_THROWS(sclMath::RealMatrix(1, -10));
  CHECK_THROWS(sclMath::RealMatrix(0, -1));

  CHECK_THROWS(sclMath::RealMatrix(-0, -1));
  CHECK_THROWS(sclMath::RealMatrix(-1, -9));
  CHECK_THROWS(sclMath::RealMatrix(-9, -4));
  CHECK_THROWS(sclMath::RealMatrix(-10, -12));
  CHECK_THROWS(sclMath::RealMatrix(-21, -13));
  CHECK_THROWS(sclMath::RealMatrix(-10, -10));

  CHECK_THROWS(sclMath::ComplexMatrix(-1, 2));
  CHECK_THROWS(sclMath::ComplexMatrix(-3, 10));
  CHECK_THROWS(sclMath::ComplexMatrix(-8, 0));
  CHECK_THROWS(sclMath::ComplexMatrix(-2, 2));
  CHECK_THROWS(sclMath::ComplexMatrix(-9, 10));
  CHECK_THROWS(sclMath::ComplexMatrix(-18, 0));

  CHECK_THROWS(sclMath::ComplexMatrix(2, -1));
  CHECK_THROWS(sclMath::ComplexMatrix(1, -10));
  CHECK_THROWS(sclMath::ComplexMatrix(0, -1));
  CHECK_THROWS(sclMath::ComplexMatrix(2, -4));
  CHECK_THROWS(sclMath::ComplexMatrix(1, -10));
  CHECK_THROWS(sclMath::ComplexMatrix(0, -1));

  CHECK_THROWS(sclMath::ComplexMatrix(-0, -1));
  CHECK_THROWS(sclMath::ComplexMatrix(-1, -9));
  CHECK_THROWS(sclMath::ComplexMatrix(-9, -4));
  CHECK_THROWS(sclMath::ComplexMatrix(-10, -12));
  CHECK_THROWS(sclMath::ComplexMatrix(-21, -13));
  CHECK_THROWS(sclMath::ComplexMatrix(-10, -10));
}
