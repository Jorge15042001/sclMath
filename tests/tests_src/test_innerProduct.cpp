#include "sclMatrix.hpp"
#include "sclMatrixOperations.hpp"
#include <catch2/catch_test_macros.hpp>
#include <cstdlib>
#include <iostream>
#include <vector>
TEST_CASE("innerProduct operation", "[innerProduct]") {

  sclMath::ComplexMatrix m1(3, 4);
  sclMath::ComplexMatrix m2(3, 4);

  m1.set(0, 0, sclMath::ComplexScalar(1, 1));
  m1.set(0, 2, sclMath::ComplexScalar(0, 1));
  m1.set(0, 3, sclMath::ComplexScalar(1, 0));
  m1.set(1, 0, sclMath::ComplexScalar(3, 3));
  m1.set(2, 0, sclMath::ComplexScalar(1, 3));
  m1.set(2, 3, sclMath::ComplexScalar(3, 1));

  m2.set(0, 1, sclMath::ComplexScalar(2, 1));
  m2.set(0, 2, sclMath::ComplexScalar(0, 2));
  m2.set(0, 3, sclMath::ComplexScalar(3, 0));
  m2.set(1, 1, sclMath::ComplexScalar(1, 9));
  m2.set(2, 1, sclMath::ComplexScalar(2, 2));
  m2.set(2, 2, sclMath::ComplexScalar(1, 0));

  const sclMath::ComplexScalar result = sclMath::innerProduct(m1, m2);

  REQUIRE(result == sclMath::ComplexScalar(5, 0));
}
TEST_CASE("innerProduct operation on vector", "[innerProduct]") {
  sclMath::ComplexMatrix m1(3, 1);
  sclMath::ComplexMatrix m2(3, 1);

  m1.set(0, 0, sclMath::ComplexScalar(1, 1));
  m1.set(1, 0, sclMath::ComplexScalar(0, 1));
  m1.set(2, 0, sclMath::ComplexScalar(1, 0));

  m2.set(0, 0, sclMath::ComplexScalar(2, 1));
  m2.set(1, 0, sclMath::ComplexScalar(0, 2));
  m2.set(2, 0, sclMath::ComplexScalar(3, 0));

  const sclMath::ComplexScalar result = sclMath::innerProduct(m1, m2);
  REQUIRE(result == sclMath::ComplexScalar(8, -1));
}
TEST_CASE("innerProduct operation on real matrix", "[innerProduct]") {

  sclMath::RealMatrix m1(3, 4);
  sclMath::RealMatrix m2(3, 4);

  m1.set(0, 0, 1);
  m1.set(0, 2, 0);
  m1.set(0, 3, 1);
  m1.set(1, 0, 3);
  m1.set(2, 0, 1);
  m1.set(2, 3, 3);

  m2.set(0, 1, 2);
  m2.set(0, 2, 0);
  m2.set(0, 3, 3);
  m2.set(1, 1, 1);
  m2.set(2, 1, 2);
  m2.set(2, 2, 1);

  const sclMath::RealScalar result = sclMath::innerProduct(m1, m2);

  REQUIRE(result == 3);
}
TEST_CASE("innerProduct operation on real vector", "[innerProduct]") {
  sclMath::RealMatrix m1(3, 1);
  sclMath::RealMatrix m2(3, 1);

  m1.set(0, 0, 1);
  m1.set(1, 0, 1);
  m1.set(2, 0, 0);

  m2.set(0, 0, 1);
  m2.set(1, 0, 2);
  m2.set(2, 0, 0);

  const sclMath::RealScalar result = sclMath::innerProduct(m1, m2);
  REQUIRE(result == 3);
}
