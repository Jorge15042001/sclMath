#include "sclMatrix.hpp"
#include "sclMatrixOperations.hpp"
#include <catch2/catch_test_macros.hpp>
#include <cstdlib>
#include <iostream>
#include <vector>
TEST_CASE("mul of incompatible shapes complex matrices ", "[mul]") {
  sclMath::ComplexMatrix m1(1, 2);
  sclMath::ComplexMatrix m2(3, 1);
  sclMath::ComplexMatrix m3(7, 8);
  sclMath::ComplexMatrix m4(9, 4);
  sclMath::ComplexMatrix m5(2, 9);

  CHECK_THROWS(m1 * m2);
  CHECK_THROWS(m2 * m3);
  CHECK_THROWS(m1 * m3);
  CHECK_THROWS(m3 * m5);
  CHECK_THROWS(m2 * m4);
}
TEST_CASE("mul of compatible shape complex matrices", "[mul]") {
  sclMath::ComplexMatrix m1(1, 3);
  sclMath::ComplexMatrix m2(3, 2);
  sclMath::ComplexMatrix m3(7, 7);
  sclMath::ComplexMatrix m4(9, 7);
  sclMath::ComplexMatrix m5(2, 9);

  // different shaped matrices
  CHECK_NOTHROW(m1 * m2);
  CHECK_NOTHROW(m2 * m5);
  CHECK_NOTHROW(m4 * m3);
  CHECK_NOTHROW(m5 * m4);
}
TEST_CASE("output shape of complex matrix mul", "[mul]") {
  sclMath::ComplexMatrix m1(1, 3);
  sclMath::ComplexMatrix m2(3, 2);
  sclMath::ComplexMatrix m3(7, 7);
  sclMath::ComplexMatrix m4(9, 7);
  sclMath::ComplexMatrix m5(2, 9);

  sclMath::ComplexMatrix Result1 = m1 * m2;
  sclMath::ComplexMatrix Result2 = m2 * m5;
  sclMath::ComplexMatrix Result3 = m4 * m3;
  sclMath::ComplexMatrix Result4 = m5 * m4;

  CHECK(m1.getRows() == Result1.getRows());
  CHECK(m2.getCols() == Result1.getCols());

  CHECK(m2.getRows() == Result2.getRows());
  CHECK(m5.getCols() == Result2.getCols());

  CHECK(m4.getRows() == Result3.getRows());
  CHECK(m3.getCols() == Result3.getCols());

  CHECK(m5.getRows() == Result4.getRows());
  CHECK(m4.getCols() == Result4.getCols());
}
TEST_CASE("mul of incompatible shapes real matrices ", "[mul]") {
  sclMath::RealMatrix m1(1, 2);
  sclMath::RealMatrix m2(3, 1);
  sclMath::RealMatrix m3(7, 8);
  sclMath::RealMatrix m4(9, 4);
  sclMath::RealMatrix m5(2, 9);

  CHECK_THROWS(m1 * m2);
  CHECK_THROWS(m2 * m3);
  CHECK_THROWS(m1 * m3);
  CHECK_THROWS(m3 * m5);
  CHECK_THROWS(m2 * m4);
}
TEST_CASE("mul of compatible shape real matrices", "[mul]") {
  sclMath::RealMatrix m1(1, 3);
  sclMath::RealMatrix m2(3, 2);
  sclMath::RealMatrix m3(7, 7);
  sclMath::RealMatrix m4(9, 7);
  sclMath::RealMatrix m5(2, 9);

  // different shaped matrices
  CHECK_NOTHROW(m1 * m2);
  CHECK_NOTHROW(m2 * m5);
  CHECK_NOTHROW(m4 * m3);
  CHECK_NOTHROW(m5 * m4);
}
TEST_CASE("output shape of real matrix mul", "[mul]") {
  sclMath::RealMatrix m1(1, 3);
  sclMath::RealMatrix m2(3, 2);
  sclMath::RealMatrix m3(7, 7);
  sclMath::RealMatrix m4(9, 7);
  sclMath::RealMatrix m5(2, 9);

  sclMath::RealMatrix Result1 = m1 * m2;
  sclMath::RealMatrix Result2 = m2 * m5;
  sclMath::RealMatrix Result3 = m4 * m3;
  sclMath::RealMatrix Result4 = m5 * m4;

  CHECK(m1.getRows() == Result1.getRows());
  CHECK(m2.getCols() == Result1.getCols());

  CHECK(m2.getRows() == Result2.getRows());
  CHECK(m5.getCols() == Result2.getCols());

  CHECK(m4.getRows() == Result3.getRows());
  CHECK(m3.getCols() == Result3.getCols());

  CHECK(m5.getRows() == Result4.getRows());
  CHECK(m4.getCols() == Result4.getCols());
}
