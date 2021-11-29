#include "sclMatrix/sclCopyMatrix.hpp"
#include "sclMatrix/sclMatrix.hpp"
#include "sclMatrix/sclMatrixComparison.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Copy RealMatrix", "[copyMatrix]") {
  sclMath::RealMatrix m1(2, 2);
  sclMath::RealMatrix m1_copy = sclMath::copyMatrix(m1);

  REQUIRE(m1 == m1_copy);

  m1.set(0, 0, 1);
  m1_copy = sclMath::copyMatrix(m1);
  REQUIRE(m1 == m1_copy);

  m1.set(0, 1, 2);
  m1_copy = sclMath::copyMatrix(m1);
  REQUIRE(m1 == m1_copy);

  m1.set(1, 1, 3);
  m1_copy = sclMath::copyMatrix(m1);
  REQUIRE(m1 == m1_copy);
}
TEST_CASE("Copy ComplexMatrix", "[copyMatrix]") {
  sclMath::ComplexMatrix m1(2, 2);
  sclMath::ComplexMatrix m1_copy = sclMath::copyMatrix(m1);

  REQUIRE(m1 == m1_copy);

  m1.set(0, 0, {1, 1});
  m1_copy = sclMath::copyMatrix(m1);
  REQUIRE(m1 == m1_copy);

  m1.set(0, 1, {2, 1});
  m1_copy = sclMath::copyMatrix(m1);
  REQUIRE(m1 == m1_copy);

  m1.set(1, 1, 3);
  m1_copy = sclMath::copyMatrix(m1);
  REQUIRE(m1 == m1_copy);
}
TEST_CASE("Copy RealMatrix to ComplexMatrix", "[copyMatrix]") {
  sclMath::RealMatrix m1(2, 2);
  sclMath::ComplexMatrix m1_copy =
      sclMath::copyMatrix<sclMath::RealMatrix, sclMath::ComplexMatrix>(m1);

  REQUIRE(m1 == m1_copy);

  m1.set(0, 0, 1);
  m1_copy =
      sclMath::copyMatrix<sclMath::RealMatrix, sclMath::ComplexMatrix>(m1);
  REQUIRE(m1 == m1_copy);

  m1.set(0, 1, 2);
  m1_copy =
      sclMath::copyMatrix<sclMath::RealMatrix, sclMath::ComplexMatrix>(m1);
  REQUIRE(m1 == m1_copy);

  m1.set(1, 1, 3);
  m1_copy =
      sclMath::copyMatrix<sclMath::RealMatrix, sclMath::ComplexMatrix>(m1);
  REQUIRE(m1 == m1_copy);
}
