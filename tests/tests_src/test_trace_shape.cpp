#include "sclComplexMatrix.hpp"
#include "sclRealMatrix.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("trace shape of non-square complexmatrix", "[trace]") {
  sclMath::ComplexMatrix m1(1, 2);
  sclMath::ComplexMatrix m2(3, 1);
  sclMath::ComplexMatrix m3(7, 8);
  sclMath::ComplexMatrix m4(9, 4);
  sclMath::ComplexMatrix m5(2, 9);

  CHECK_THROWS(m1.trace());
  CHECK_THROWS(m2.trace());
  CHECK_THROWS(m3.trace());
  CHECK_THROWS(m4.trace());
  CHECK_THROWS(m5.trace());
}
TEST_CASE("trace shape of suare complexmatrix", "[trace]") {
  sclMath::ComplexMatrix m1(1, 1);
  sclMath::ComplexMatrix m2(3, 3);
  sclMath::ComplexMatrix m3(7, 7);
  sclMath::ComplexMatrix m4(9, 9);
  sclMath::ComplexMatrix m5(2, 2);

  CHECK_NOTHROW(m1.trace());
  CHECK_NOTHROW(m2.trace());
  CHECK_NOTHROW(m3.trace());
  CHECK_NOTHROW(m4.trace());
  CHECK_NOTHROW(m5.trace());
}
TEST_CASE("trace shape of non-square RealMatrix", "[trace]") {
  sclMath::RealMatrix m1(1, 2);
  sclMath::RealMatrix m2(3, 1);
  sclMath::RealMatrix m3(7, 8);
  sclMath::RealMatrix m4(9, 4);
  sclMath::RealMatrix m5(2, 9);

  CHECK_THROWS(m1.trace());
  CHECK_THROWS(m2.trace());
  CHECK_THROWS(m3.trace());
  CHECK_THROWS(m4.trace());
  CHECK_THROWS(m5.trace());
}
TEST_CASE("trace shape of suare RealMatrix", "[trace]") {
  sclMath::RealMatrix m1(1, 1);
  sclMath::RealMatrix m2(3, 3);
  sclMath::RealMatrix m3(7, 7);
  sclMath::RealMatrix m4(9, 9);
  sclMath::RealMatrix m5(2, 2);

  CHECK_NOTHROW(m1.trace());
  CHECK_NOTHROW(m2.trace());
  CHECK_NOTHROW(m3.trace());
  CHECK_NOTHROW(m4.trace());
  CHECK_NOTHROW(m5.trace());
}
