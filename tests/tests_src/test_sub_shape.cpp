#include "sclMatrix/sclMatrixSubtraction.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("sub of diferent shape complexmatrix ", "[sub]") {
  sclMath::ComplexMatrix m1(1, 2);
  sclMath::ComplexMatrix m2(3, 1);
  sclMath::ComplexMatrix m3(7, 8);
  sclMath::ComplexMatrix m4(9, 4);
  sclMath::ComplexMatrix m5(2, 9);

  CHECK_THROWS(m1 - m2);
  CHECK_THROWS(m2 - m3);
  CHECK_THROWS(m1 - m3);
  CHECK_THROWS(m3 - m5);
  CHECK_THROWS(m2 - m4);
}
TEST_CASE("sub of compatible non-square shape ComplexMatrix ", "[sub]") {

  sclMath::ComplexMatrix m1(3, 2);
  sclMath::ComplexMatrix m2(3, 2);
  sclMath::ComplexMatrix m3(4, 8);
  sclMath::ComplexMatrix m4(4, 8);
  sclMath::ComplexMatrix m5(2, 9);
  sclMath::ComplexMatrix m6(2, 9);

  CHECK_NOTHROW(m1 - m2);
  CHECK_NOTHROW(m2 - m1);
  CHECK_NOTHROW(m3 - m4);
  CHECK_NOTHROW(m4 - m4);
  CHECK_NOTHROW(m5 - m6);
  CHECK_NOTHROW(m6 - m5);
}
TEST_CASE("sub  of same shape ComplexMatrix", "[sub]") {
  sclMath::ComplexMatrix m1(1, 1);
  sclMath::ComplexMatrix m2(3, 3);
  sclMath::ComplexMatrix m3(7, 7);
  sclMath::ComplexMatrix m4(9, 9);
  sclMath::ComplexMatrix m5(2, 2);

  CHECK_NOTHROW(m1 - m1);
  CHECK_NOTHROW(m2 - m2);
  CHECK_NOTHROW(m3 - m3);
  CHECK_NOTHROW(m4 - m4);
  CHECK_NOTHROW(m5 - m5);
}
TEST_CASE("sub right output shape for ComplexMatrix substraction", "[sub]") {
  sclMath::ComplexMatrix m1(1, 1);
  sclMath::ComplexMatrix m2(3, 3);
  sclMath::ComplexMatrix m3(7, 7);
  sclMath::ComplexMatrix m4(9, 9);
  sclMath::ComplexMatrix m5(2, 2);

  sclMath::ComplexMatrix m1Result = m1 - m1;
  sclMath::ComplexMatrix m2Result = m2 - m2;
  sclMath::ComplexMatrix m3Result = m3 - m3;
  sclMath::ComplexMatrix m4Result = m4 - m4;
  sclMath::ComplexMatrix m5Result = m5 - m5;

  CHECK(m1.getRows() == m1Result.getRows());
  CHECK(m1.getCols() == m1Result.getCols());

  CHECK(m2.getRows() == m2Result.getRows());
  CHECK(m2.getCols() == m2Result.getCols());

  CHECK(m3.getRows() == m3Result.getRows());
  CHECK(m3.getCols() == m3Result.getCols());

  CHECK(m4.getRows() == m4Result.getRows());
  CHECK(m4.getCols() == m4Result.getCols());

  CHECK(m5.getRows() == m5Result.getRows());
  CHECK(m5.getCols() == m5Result.getCols());
}
// tests for rean matrices
TEST_CASE("sub of diferent shape RealMatrix ", "[sub]") {
  sclMath::RealMatrix m1(1, 2);
  sclMath::RealMatrix m2(3, 1);
  sclMath::RealMatrix m3(7, 8);
  sclMath::RealMatrix m4(9, 4);
  sclMath::RealMatrix m5(2, 9);

  CHECK_THROWS(m1 - m2);
  CHECK_THROWS(m2 - m3);
  CHECK_THROWS(m1 - m3);
  CHECK_THROWS(m3 - m5);
  CHECK_THROWS(m2 - m4);
}
TEST_CASE("sub of compatible non-square shape RealMatrix ", "[sub]") {

  sclMath::RealMatrix m1(3, 2);
  sclMath::RealMatrix m2(3, 2);
  sclMath::RealMatrix m3(4, 8);
  sclMath::RealMatrix m4(4, 8);
  sclMath::RealMatrix m5(2, 9);
  sclMath::RealMatrix m6(2, 9);

  CHECK_NOTHROW(m1 - m2);
  CHECK_NOTHROW(m2 - m1);
  CHECK_NOTHROW(m3 - m4);
  CHECK_NOTHROW(m4 - m4);
  CHECK_NOTHROW(m5 - m6);
  CHECK_NOTHROW(m6 - m5);
}
TEST_CASE("sub  of same shape RealMatrix", "[sub]") {
  sclMath::RealMatrix m1(1, 1);
  sclMath::RealMatrix m2(3, 3);
  sclMath::RealMatrix m3(7, 7);
  sclMath::RealMatrix m4(9, 9);
  sclMath::RealMatrix m5(2, 2);

  CHECK_NOTHROW(m1 - m1);
  CHECK_NOTHROW(m2 - m2);
  CHECK_NOTHROW(m3 - m3);
  CHECK_NOTHROW(m4 - m4);
  CHECK_NOTHROW(m5 - m5);
}
TEST_CASE("sub right output shape RealMatrix", "[sub]") {
  sclMath::RealMatrix m1(1, 1);
  sclMath::RealMatrix m2(3, 3);
  sclMath::RealMatrix m3(7, 7);
  sclMath::RealMatrix m4(9, 9);
  sclMath::RealMatrix m5(2, 2);

  sclMath::RealMatrix m1Result = m1 - m1;
  sclMath::RealMatrix m2Result = m2 - m2;
  sclMath::RealMatrix m3Result = m3 - m3;
  sclMath::RealMatrix m4Result = m4 - m4;
  sclMath::RealMatrix m5Result = m5 - m5;

  CHECK(m1.getRows() == m1Result.getRows());
  CHECK(m1.getCols() == m1Result.getCols());

  CHECK(m2.getRows() == m2Result.getRows());
  CHECK(m2.getCols() == m2Result.getCols());

  CHECK(m3.getRows() == m3Result.getRows());
  CHECK(m3.getCols() == m3Result.getCols());

  CHECK(m4.getRows() == m4Result.getRows());
  CHECK(m4.getCols() == m4Result.getCols());

  CHECK(m5.getRows() == m5Result.getRows());
  CHECK(m5.getCols() == m5Result.getCols());
}
TEST_CASE("sub of diferent shape RealMatrix with ComplexMatrix", "[sub]") {
  sclMath::ComplexMatrix m1(1, 2);
  sclMath::RealMatrix m2(3, 1);
  sclMath::ComplexMatrix m3(7, 8);
  sclMath::RealMatrix m4(9, 4);
  sclMath::ComplexMatrix m5(2, 9);

  CHECK_THROWS(m1 - m2);
  CHECK_THROWS(m2 - m3);
  CHECK_THROWS(m1 - m3);
  CHECK_THROWS(m3 - m5);
  CHECK_THROWS(m2 - m4);
}
TEST_CASE("sub of compatible non-square shape RealMatrix with ComplexMatrix",
          "[sub]") {

  sclMath::ComplexMatrix m1(3, 2);
  sclMath::RealMatrix m2(3, 2);
  sclMath::RealMatrix m3(4, 8);
  sclMath::ComplexMatrix m4(4, 8);
  sclMath::RealMatrix m5(2, 9);
  sclMath::ComplexMatrix m6(2, 9);

  CHECK_NOTHROW(m1 - m2);
  CHECK_NOTHROW(m2 - m1);
  CHECK_NOTHROW(m3 - m4);
  CHECK_NOTHROW(m4 - m4);
  CHECK_NOTHROW(m5 - m6);
  CHECK_NOTHROW(m6 - m5);
}
TEST_CASE("sub  of same shape RealMatrix with ComplexMatrix", "[sub]") {
  sclMath::ComplexMatrix m1(1, 1);
  sclMath::RealMatrix m2(3, 3);
  sclMath::ComplexMatrix m3(7, 7);
  sclMath::RealMatrix m4(9, 9);
  sclMath::RealMatrix m5(2, 2);

  CHECK_NOTHROW(m1 - m1);
  CHECK_NOTHROW(m2 - m2);
  CHECK_NOTHROW(m3 - m3);
  CHECK_NOTHROW(m4 - m4);
  CHECK_NOTHROW(m5 - m5);
}
TEST_CASE("sub right output shape RealMatrix with ComplexMatrix", "[sub]") {
  sclMath::RealMatrix m1(1, 1);
  sclMath::ComplexMatrix m2(3, 3);
  sclMath::RealMatrix m3(7, 7);
  sclMath::RealMatrix m4(9, 9);
  sclMath::ComplexMatrix m5(2, 2);

  sclMath::RealMatrix m1Result = m1 - m1;
  sclMath::ComplexMatrix m2Result = m2 - m2;
  sclMath::RealMatrix m3Result = m3 - m3;
  sclMath::RealMatrix m4Result = m4 - m4;
  sclMath::ComplexMatrix m5Result = m5 - m5;

  CHECK(m1.getRows() == m1Result.getRows());
  CHECK(m1.getCols() == m1Result.getCols());

  CHECK(m2.getRows() == m2Result.getRows());
  CHECK(m2.getCols() == m2Result.getCols());

  CHECK(m3.getRows() == m3Result.getRows());
  CHECK(m3.getCols() == m3Result.getCols());

  CHECK(m4.getRows() == m4Result.getRows());
  CHECK(m4.getCols() == m4Result.getCols());

  CHECK(m5.getRows() == m5Result.getRows());
  CHECK(m5.getCols() == m5Result.getCols());
}
