#include "sclMatrix/sclMatrix.hpp"
#include "sclMatrix/sclZeroMatrix.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("zero matrix creation", "[zero matrix]") {
  // constructor
  sclMath::ZeroMatrix zero(3, 4);

  zero.transpose();
  REQUIRE(zero.getRows() == 4);
  REQUIRE(zero.getCols() == 3);
  zero.transpose();
  REQUIRE(zero.getRows() == 3);
  REQUIRE(zero.getCols() == 4);

  // implicit conversion
  sclMath::ComplexMatrix zeroComplex = sclMath::ZeroMatrix(3, 4);
  sclMath::RealMatrix zeroReal = sclMath::ZeroMatrix(3, 4);

  REQUIRE(zeroComplex.get(0, 0) == 0.0);
  REQUIRE(zeroComplex.get(0, 1) == 0.0);
  REQUIRE(zeroComplex.get(0, 2) == 0.0);
  REQUIRE(zeroComplex.get(0, 3) == 0.0);

  REQUIRE(zeroComplex.get(1, 0) == 0.0);
  REQUIRE(zeroComplex.get(1, 1) == 0.0);
  REQUIRE(zeroComplex.get(1, 2) == 0.0);
  REQUIRE(zeroComplex.get(1, 3) == 0.0);

  REQUIRE(zeroComplex.get(2, 0) == 0.0);
  REQUIRE(zeroComplex.get(2, 1) == 0.0);
  REQUIRE(zeroComplex.get(2, 2) == 0.0);
  REQUIRE(zeroComplex.get(2, 3) == 0.0);

  REQUIRE(zeroReal.get(0, 0) == 0.0);
  REQUIRE(zeroReal.get(0, 1) == 0.0);
  REQUIRE(zeroReal.get(0, 2) == 0.0);
  REQUIRE(zeroReal.get(0, 3) == 0.0);

  REQUIRE(zeroReal.get(1, 0) == 0.0);
  REQUIRE(zeroReal.get(1, 1) == 0.0);
  REQUIRE(zeroReal.get(1, 2) == 0.0);
  REQUIRE(zeroReal.get(1, 3) == 0.0);

  REQUIRE(zeroReal.get(2, 0) == 0.0);
  REQUIRE(zeroReal.get(2, 1) == 0.0);
  REQUIRE(zeroReal.get(2, 2) == 0.0);
  REQUIRE(zeroReal.get(2, 3) == 0.0);

  CHECK_NOTHROW(sclMath::RealMatrix(sclMath::ZeroMatrix(2, 2)));
  CHECK_NOTHROW(sclMath::ComplexMatrix(sclMath::ZeroMatrix(2, 2)));
}
