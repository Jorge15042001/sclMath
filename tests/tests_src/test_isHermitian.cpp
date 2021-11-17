
#include "sclMatrix.hpp"
#include "sclMatrixOperations.hpp"
#include <catch2/catch_test_macros.hpp>
#include <cstdlib>
#include <iostream>
#include <vector>
TEST_CASE("isHermitian operation for complex matrix", "[isHermitian]") {

  sclMath::ComplexMatrix m1(3, 4);
  sclMath::ComplexMatrix m2(3, 4);

  REQUIRE_FALSE(m1.isHermitian());
  REQUIRE_FALSE(m2.isHermitian());

  // zero is hermitian
  sclMath::ComplexMatrix zero1(4, 4);
  sclMath::ComplexMatrix zero2(6, 6);
  sclMath::ComplexMatrix zero3(7, 7);

  REQUIRE(zero1.isHermitian());
  REQUIRE(zero2.isHermitian());
  REQUIRE(zero3.isHermitian());

  // identity is hermitian
  sclMath::ComplexMatrix identity1(2, 2);
  sclMath::ComplexMatrix identity2(5, 5);
  sclMath::ComplexMatrix identity3(3, 3);

  identity1.set(0, 0, 1);
  identity1.set(1, 1, 1);

  identity2.set(0, 0, 1);
  identity2.set(1, 1, 1);
  identity2.set(2, 2, 1);
  identity2.set(3, 3, 1);
  identity2.set(4, 4, 1);

  identity3.set(0, 0, 1);
  identity3.set(1, 1, 1);
  identity3.set(2, 2, 1);

  REQUIRE(identity1.isHermitian());
  REQUIRE(identity2.isHermitian());
  REQUIRE(identity3.isHermitian());

  // diagonal matrices with complex entries aren't hermitian

  sclMath::ComplexMatrix diagonal1(2, 2);
  sclMath::ComplexMatrix diagonal2(5, 5);
  sclMath::ComplexMatrix diagonal3(3, 3);

  diagonal1.set(0, 0, sclMath::ComplexScalar(2, 2));
  diagonal1.set(1, 1, sclMath::ComplexScalar(-1, -2));

  diagonal2.set(0, 0, sclMath::ComplexScalar(1, 2));
  diagonal2.set(1, 1, sclMath::ComplexScalar(-2, 1));
  diagonal2.set(2, 2, sclMath::ComplexScalar(6, -2));
  diagonal2.set(3, 3, sclMath::ComplexScalar(-5, .2));
  diagonal2.set(4, 4, sclMath::ComplexScalar(7, .4));

  diagonal3.set(0, 0, sclMath::ComplexScalar(-1, 0));
  diagonal3.set(1, 1, sclMath::ComplexScalar(-2, -9));
  diagonal3.set(2, 2, sclMath::ComplexScalar(-1, 8));

  REQUIRE_FALSE(diagonal1.isHermitian());
  REQUIRE_FALSE(diagonal2.isHermitian());
  REQUIRE_FALSE(diagonal3.isHermitian());

  // diagonal matrices with all real entries in the diagonal are hermitian
  sclMath::ComplexMatrix realDiagonal1(2, 2);
  sclMath::ComplexMatrix realDiagonal2(5, 5);
  sclMath::ComplexMatrix realDiagonal3(3, 3);

  realDiagonal1.set(0, 0, sclMath::ComplexScalar(2, 0));
  realDiagonal1.set(1, 1, sclMath::ComplexScalar(-1, 0));

  realDiagonal2.set(0, 0, sclMath::ComplexScalar(1, 0));
  realDiagonal2.set(1, 1, sclMath::ComplexScalar(-2, 0));
  realDiagonal2.set(2, 2, sclMath::ComplexScalar(6, -0));
  realDiagonal2.set(3, 3, sclMath::ComplexScalar(-5, .0));
  realDiagonal2.set(4, 4, sclMath::ComplexScalar(7, .0));

  realDiagonal3.set(0, 0, sclMath::ComplexScalar(-1, 0));
  realDiagonal3.set(1, 1, sclMath::ComplexScalar(-2, -0));
  realDiagonal3.set(2, 2, sclMath::ComplexScalar(-1, 0));

  REQUIRE(realDiagonal1.isHermitian());
  REQUIRE(realDiagonal2.isHermitian());
  REQUIRE(realDiagonal3.isHermitian());

  // hermitian matrices

  sclMath::ComplexMatrix hermitian1(3, 3);
  sclMath::ComplexMatrix hermitian2(3, 3);

  hermitian1.set(0, 0, sclMath::ComplexScalar(5, 0));
  hermitian1.set(0, 1, sclMath::ComplexScalar(4, 5));
  hermitian1.set(0, 2, sclMath::ComplexScalar(6, -16));

  hermitian1.set(1, 0, sclMath::ComplexScalar(4, -5));
  hermitian1.set(1, 1, sclMath::ComplexScalar(13, 0));
  hermitian1.set(1, 2, sclMath::ComplexScalar(7));

  hermitian1.set(2, 0, sclMath::ComplexScalar(6, 16));
  hermitian1.set(2, 1, sclMath::ComplexScalar(7));
  hermitian1.set(2, 2, sclMath::ComplexScalar(-2.1));

  hermitian2.set(0, 0, sclMath::ComplexScalar(7));
  hermitian2.set(0, 1, sclMath::ComplexScalar(6, 5));

  hermitian2.set(1, 0, sclMath::ComplexScalar(6, -5));
  hermitian2.set(1, 1, sclMath::ComplexScalar(-3));

  REQUIRE(hermitian1.isHermitian());
  REQUIRE(hermitian2.isHermitian());
}
TEST_CASE("isHermitian operation for real matrix", "[isHermitian]") {

  sclMath::RealMatrix m1(3, 4);
  sclMath::RealMatrix m2(3, 4);

  REQUIRE_FALSE(m1.isHermitian());
  REQUIRE_FALSE(m2.isHermitian());

  // zero is hermitian
  sclMath::RealMatrix zero1(4, 4);
  sclMath::RealMatrix zero2(6, 6);
  sclMath::RealMatrix zero3(7, 7);

  REQUIRE(zero1.isHermitian());
  REQUIRE(zero2.isHermitian());
  REQUIRE(zero3.isHermitian());

  // identity is hermitian
  sclMath::RealMatrix identity1(2, 2);
  sclMath::RealMatrix identity2(5, 5);
  sclMath::RealMatrix identity3(3, 3);

  identity1.set(0, 0, 1);
  identity1.set(1, 1, 1);

  identity2.set(0, 0, 1);
  identity2.set(1, 1, 1);
  identity2.set(2, 2, 1);
  identity2.set(3, 3, 1);
  identity2.set(4, 4, 1);

  identity3.set(0, 0, 1);
  identity3.set(1, 1, 1);
  identity3.set(2, 2, 1);

  REQUIRE(identity1.isHermitian());
  REQUIRE(identity2.isHermitian());
  REQUIRE(identity3.isHermitian());

  // diagonal matrices with complex entries aren't hermitian

  sclMath::RealMatrix diagonal1(2, 2);
  sclMath::RealMatrix diagonal2(5, 5);
  sclMath::RealMatrix diagonal3(3, 3);

  diagonal1.set(0, 0, 1);
  diagonal1.set(1, 1, -2);

  diagonal2.set(0, 0, 1);
  diagonal2.set(1, 1, 1);
  diagonal2.set(2, 2, 2);
  diagonal2.set(3, 3, .2);
  diagonal2.set(4, 4, 4);

  diagonal3.set(0, 0, 0);
  diagonal3.set(1, 1, -9);
  diagonal3.set(2, 2, 8);

  REQUIRE_FALSE(diagonal1.isHermitian());
  REQUIRE_FALSE(diagonal2.isHermitian());
  REQUIRE_FALSE(diagonal3.isHermitian());

  // diagonal matrices with all real entries in the diagonal are hermitian
  sclMath::RealMatrix realDiagonal1(2, 2);
  sclMath::RealMatrix realDiagonal2(5, 5);
  sclMath::RealMatrix realDiagonal3(3, 3);

  realDiagonal1.set(0, 0, 10);
  realDiagonal1.set(1, 1, 90);

  realDiagonal2.set(0, 0, 7);
  realDiagonal2.set(1, 1, 9);
  realDiagonal2.set(2, 2, -10);
  realDiagonal2.set(3, 3, .310);
  realDiagonal2.set(4, 4, .0);

  realDiagonal3.set(0, 0, 2);
  realDiagonal3.set(1, 1, -9);
  realDiagonal3.set(2, 2, 2);

  REQUIRE(realDiagonal1.isHermitian());
  REQUIRE(realDiagonal2.isHermitian());
  REQUIRE(realDiagonal3.isHermitian());

  // hermitian matrices

  sclMath::RealMatrix hermitian1(3, 3);
  sclMath::RealMatrix hermitian2(3, 3);

  hermitian1.set(0, 0, 0);
  hermitian1.set(0, 1, 5);
  hermitian1.set(0, 2, -16);

  hermitian1.set(1, 0, 5);
  hermitian1.set(1, 1, 0);
  hermitian1.set(1, 2, 7);

  hermitian1.set(2, 0, -16);
  hermitian1.set(2, 1, 7);
  hermitian1.set(2, 2, -2.1);

  hermitian2.set(0, 0, 7);
  hermitian2.set(0, 1, 6);

  hermitian2.set(1, 0, 6);
  hermitian2.set(1, 1, -3);

  REQUIRE(hermitian1.isHermitian());
  REQUIRE(hermitian2.isHermitian());
}
// TODO:test for false cases
