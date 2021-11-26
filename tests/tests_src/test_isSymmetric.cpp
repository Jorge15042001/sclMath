#include "sclMatrix/sclMatrix.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("isSymmetric operation for complex matrix", "[isHermitian]") {

  sclMath::ComplexMatrix m1(3, 4);
  sclMath::ComplexMatrix m2(3, 4);

  REQUIRE_FALSE(m1.isHermitian());
  REQUIRE_FALSE(m2.isHermitian());

  // zero is Symmetric
  sclMath::ComplexMatrix zero1(4, 4);
  sclMath::ComplexMatrix zero2(6, 6);
  sclMath::ComplexMatrix zero3(7, 7);

  REQUIRE(zero1.isSymmetric());
  REQUIRE(zero2.isSymmetric());
  REQUIRE(zero3.isSymmetric());

  // identity is Symmetric
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

  REQUIRE(identity1.isSymmetric());
  REQUIRE(identity2.isSymmetric());
  REQUIRE(identity3.isSymmetric());

  // Symmetric matrices

  sclMath::ComplexMatrix symmetric2(3, 3);
  sclMath::ComplexMatrix symmetric1(3, 3);

  symmetric1.set(0, 0, sclMath::ComplexScalar(5, 0));
  symmetric1.set(0, 1, sclMath::ComplexScalar(4, 5));
  symmetric1.set(0, 2, sclMath::ComplexScalar(6, -16));

  symmetric1.set(1, 0, sclMath::ComplexScalar(4, 5));
  symmetric1.set(1, 1, sclMath::ComplexScalar(13, 0));
  symmetric1.set(1, 2, sclMath::ComplexScalar(7));

  symmetric1.set(2, 0, sclMath::ComplexScalar(6, -16));
  symmetric1.set(2, 1, sclMath::ComplexScalar(7));
  symmetric1.set(2, 2, sclMath::ComplexScalar(-2.1));

  symmetric2.set(0, 0, sclMath::ComplexScalar(7));
  symmetric2.set(0, 1, sclMath::ComplexScalar(6, 5));

  symmetric2.set(1, 0, sclMath::ComplexScalar(6, 5));
  symmetric2.set(1, 1, sclMath::ComplexScalar(-3));

  REQUIRE(symmetric1.isSymmetric());
  REQUIRE(symmetric2.isSymmetric());

  // unSymmetric matrices

  sclMath::ComplexMatrix unsymmetric2(3, 3);
  sclMath::ComplexMatrix unsymmetric1(3, 3);

  unsymmetric1.set(0, 0, sclMath::ComplexScalar(5, 0));
  unsymmetric1.set(0, 1, sclMath::ComplexScalar(4, -5));
  unsymmetric1.set(0, 2, sclMath::ComplexScalar(6, -16));

  unsymmetric1.set(1, 0, sclMath::ComplexScalar(4, 5));
  unsymmetric1.set(1, 1, sclMath::ComplexScalar(13, 0));
  unsymmetric1.set(1, 2, sclMath::ComplexScalar(7));

  unsymmetric1.set(2, 0, sclMath::ComplexScalar(6, -16));
  unsymmetric1.set(2, 1, sclMath::ComplexScalar(-7));
  unsymmetric1.set(2, 2, sclMath::ComplexScalar(-2.1));

  unsymmetric2.set(0, 0, sclMath::ComplexScalar(7));
  unsymmetric2.set(0, 1, sclMath::ComplexScalar(6, 5));

  unsymmetric2.set(1, 0, sclMath::ComplexScalar(-6, 5));
  unsymmetric2.set(1, 1, sclMath::ComplexScalar(-3));

  REQUIRE_FALSE(symmetric1.isSymmetric());
  REQUIRE_FALSE(symmetric2.isSymmetric());
}
TEST_CASE("isSymmetric operation for real matrix", "[isHermitian]") {
  //  mathematically for real matrices, isHermitian is equivalent to isSymmetric

  sclMath::RealMatrix m1(3, 4);
  sclMath::RealMatrix m2(3, 4);

  REQUIRE_FALSE(m1.isSymmetric());
  REQUIRE_FALSE(m2.isSymmetric());

  // zero is hermitian
  sclMath::RealMatrix zero1(4, 4);
  sclMath::RealMatrix zero2(6, 6);
  sclMath::RealMatrix zero3(7, 7);

  REQUIRE(zero1.isSymmetric());
  REQUIRE(zero2.isSymmetric());
  REQUIRE(zero3.isSymmetric());

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

  REQUIRE(identity1.isSymmetric());
  REQUIRE(identity2.isSymmetric());
  REQUIRE(identity3.isSymmetric());

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

  REQUIRE(realDiagonal1.isSymmetric());
  REQUIRE(realDiagonal2.isSymmetric());
  REQUIRE(realDiagonal3.isSymmetric());

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

  REQUIRE(hermitian1.isSymmetric());
  REQUIRE(hermitian2.isSymmetric());
}
