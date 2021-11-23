#include "sclMatrix/sclInnerProduct.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("innerProduct of diferent shape matrix ", "[trace]") {
  sclMath::ComplexMatrix m1(1, 2);
  sclMath::ComplexMatrix m2(3, 1);
  sclMath::ComplexMatrix m3(7, 8);
  sclMath::ComplexMatrix m4(9, 4);
  sclMath::ComplexMatrix m5(2, 9);
  sclMath::ComplexMatrix m6(3, 2);

  sclMath::RealMatrix m7(1, 2);
  sclMath::RealMatrix m8(3, 1);
  sclMath::RealMatrix m9(7, 8);
  sclMath::RealMatrix m10(9, 4);
  sclMath::RealMatrix m11(2, 9);
  sclMath::RealMatrix m12(3, 2);

  // ComplexMatrix with ComplexMatrix
  CHECK_THROWS(sclMath::innerProduct(m1, m2));
  CHECK_THROWS(sclMath::innerProduct(m2, m3));
  CHECK_THROWS(sclMath::innerProduct(m1, m3));
  CHECK_THROWS(sclMath::innerProduct(m3, m5));
  CHECK_THROWS(sclMath::innerProduct(m2, m4));
  CHECK_THROWS(sclMath::innerProduct(m2, m6));

  // RealMatrix with RealMatrix
  CHECK_THROWS(sclMath::innerProduct(m7, m8));
  CHECK_THROWS(sclMath::innerProduct(m8, m9));
  CHECK_THROWS(sclMath::innerProduct(m7, m9));
  CHECK_THROWS(sclMath::innerProduct(m9, m11));
  CHECK_THROWS(sclMath::innerProduct(m8, m10));
  CHECK_THROWS(sclMath::innerProduct(m8, m12));

  // RealMatrix with ComplexMatrix
  CHECK_THROWS(sclMath::innerProduct(m7, m2));
  CHECK_THROWS(sclMath::innerProduct(m8, m3));
  CHECK_THROWS(sclMath::innerProduct(m7, m3));
  CHECK_THROWS(sclMath::innerProduct(m9, m5));
  CHECK_THROWS(sclMath::innerProduct(m8, m4));
  CHECK_THROWS(sclMath::innerProduct(m8, m6));

  // ComplexMatrix with RealMatrix
  CHECK_THROWS(sclMath::innerProduct(m1, m8));
  CHECK_THROWS(sclMath::innerProduct(m2, m9));
  CHECK_THROWS(sclMath::innerProduct(m1, m9));
  CHECK_THROWS(sclMath::innerProduct(m3, m11));
  CHECK_THROWS(sclMath::innerProduct(m2, m10));
  CHECK_THROWS(sclMath::innerProduct(m2, m12));
}
TEST_CASE("innerProduct  of same shape matrix", "[trace]") {
  sclMath::ComplexMatrix m1(1, 1);
  sclMath::ComplexMatrix m2(3, 3);
  sclMath::ComplexMatrix m3(7, 7);
  sclMath::ComplexMatrix m4(9, 9);
  sclMath::ComplexMatrix m5(2, 2);

  sclMath::RealMatrix m6(1, 1);
  sclMath::RealMatrix m7(3, 3);
  sclMath::RealMatrix m8(7, 7);
  sclMath::RealMatrix m9(9, 9);
  sclMath::RealMatrix m10(2, 2);

  // ComplexMatrix with ComplexMatrix
  CHECK_NOTHROW(sclMath::innerProduct(m1, m1));
  CHECK_NOTHROW(sclMath::innerProduct(m2, m2));
  CHECK_NOTHROW(sclMath::innerProduct(m3, m3));
  CHECK_NOTHROW(sclMath::innerProduct(m4, m4));
  CHECK_NOTHROW(sclMath::innerProduct(m5, m5));

  // RealMatrix with RealMatrix
  CHECK_NOTHROW(sclMath::innerProduct(m6, m6));
  CHECK_NOTHROW(sclMath::innerProduct(m7, m7));
  CHECK_NOTHROW(sclMath::innerProduct(m8, m8));
  CHECK_NOTHROW(sclMath::innerProduct(m9, m9));
  CHECK_NOTHROW(sclMath::innerProduct(m10, m10));

  // RealMatrix with ComplexMatrix
  CHECK_NOTHROW(sclMath::innerProduct(m6, m1));
  CHECK_NOTHROW(sclMath::innerProduct(m7, m2));
  CHECK_NOTHROW(sclMath::innerProduct(m8, m3));
  CHECK_NOTHROW(sclMath::innerProduct(m9, m4));
  CHECK_NOTHROW(sclMath::innerProduct(m10, m5));

  // ComplexMatrix with RealMatrix
  CHECK_NOTHROW(sclMath::innerProduct(m1, m6));
  CHECK_NOTHROW(sclMath::innerProduct(m2, m7));
  CHECK_NOTHROW(sclMath::innerProduct(m3, m8));
  CHECK_NOTHROW(sclMath::innerProduct(m4, m9));
  CHECK_NOTHROW(sclMath::innerProduct(m5, m10));
}
