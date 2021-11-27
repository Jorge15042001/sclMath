#include "sclMatrix/sclMatrix.hpp"
#include <catch2/catch_test_macros.hpp>
TEST_CASE("zero matrix creation", "[zero matrix]") {
  // constructor
  /* sclMath::ZeroMatrix<RealMatrix> zero(1, 4); */
  /* sclMath::ZeroMatrix<ComplexMatrix> zero(1, 4); */
  // implicit conversion
  /* sclMath::ComplexMatrix zeroComplex = sclMath::ZeroMatrix(1, 4); */
  /* sclMath::RealMatrix zeroReal = sclMath::ZeroMatrix(1, 4); */
  // explicit conversion
  /* sclMath::RealMatrix zeroReal2(sclMath::ZeroMatrix(2, 2)); */
  /* sclMath::ComplexMatrix zeroComplex2(sclMath::ZeroMatrix(2, 2)); */

  // casting no implement
  /* sclMath::RealMatrix a = (sclMath::RealMatrix) sclMath::Zero(1,1); */
  /* sclMath::ComplexMatrix b = (sclMath::ComplexMatrix) sclMath::Zero(1,1); */
}
