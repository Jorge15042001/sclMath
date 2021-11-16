
#include <catch2/catch_test_macros.hpp>
#include "sclMatrix.hpp"
#include  "matrixOperations.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <iostream>
TEST_CASE("isHermitian operation","[isHermitian]" ){

  sclMath::matrix m1 (3,4);
  sclMath::matrix m2 (3,4);

  REQUIRE_FALSE(m1.isHermitian());
  REQUIRE_FALSE(m2.isHermitian());

  //zero is hermitian
  sclMath::matrix zero1(4,4);
  sclMath::matrix zero2(6,6);
  sclMath::matrix zero3(7,7);

  REQUIRE(zero1.isHermitian());
  REQUIRE(zero2.isHermitian());
  REQUIRE(zero3.isHermitian());

  // identity is hermitian
  sclMath::matrix identity1(2,2);
  sclMath::matrix identity2(5,5);
  sclMath::matrix identity3(3,3);

  identity1.set(0,0,1);
  identity1.set(1,1,1);

  identity2.set(0,0,1);
  identity2.set(1,1,1);
  identity2.set(2,2,1);
  identity2.set(3,3,1);
  identity2.set(4,4,1);


  identity3.set(0,0,1);
  identity3.set(1,1,1);
  identity3.set(2,2,1);

  REQUIRE(identity1.isHermitian());
  REQUIRE(identity2.isHermitian());
  REQUIRE(identity3.isHermitian());

  // diagonal matrices with complex entries aren't hermitian

  sclMath::matrix diagonal1(2,2);
  sclMath::matrix diagonal2(5,5);
  sclMath::matrix diagonal3(3,3);

  diagonal1.set(0,0,sclMath::ComplexScalar(2,2));
  diagonal1.set(1,1,sclMath::ComplexScalar(-1,-2));

  diagonal2.set(0,0,sclMath::ComplexScalar(1,2));
  diagonal2.set(1,1,sclMath::ComplexScalar(-2,1));
  diagonal2.set(2,2,sclMath::ComplexScalar(6,-2));
  diagonal2.set(3,3,sclMath::ComplexScalar(-5,.2));
  diagonal2.set(4,4,sclMath::ComplexScalar(7,.4));


  diagonal3.set(0,0,sclMath::ComplexScalar(-1,0));
  diagonal3.set(1,1,sclMath::ComplexScalar(-2,-9));
  diagonal3.set(2,2,sclMath::ComplexScalar(-1,8));

  REQUIRE_FALSE(diagonal1.isHermitian());
  REQUIRE_FALSE(diagonal2.isHermitian());
  REQUIRE_FALSE(diagonal3.isHermitian());

  //diagonal matrices with all real entries in the diagonal are hermitian
  sclMath::matrix realDiagonal1(2,2);
  sclMath::matrix realDiagonal2(5,5);
  sclMath::matrix realDiagonal3(3,3);

  realDiagonal1.set(0,0,sclMath::ComplexScalar(2,0));
  realDiagonal1.set(1,1,sclMath::ComplexScalar(-1,0));

  realDiagonal2.set(0,0,sclMath::ComplexScalar(1,0));
  realDiagonal2.set(1,1,sclMath::ComplexScalar(-2,0));
  realDiagonal2.set(2,2,sclMath::ComplexScalar(6,-0));
  realDiagonal2.set(3,3,sclMath::ComplexScalar(-5,.0));
  realDiagonal2.set(4,4,sclMath::ComplexScalar(7,.0));

  
  realDiagonal3.set(0,0,sclMath::ComplexScalar(-1,0));
  realDiagonal3.set(1,1,sclMath::ComplexScalar(-2,-0));
  realDiagonal3.set(2,2,sclMath::ComplexScalar(-1,0));

  REQUIRE(realDiagonal1.isHermitian());
  REQUIRE(realDiagonal2.isHermitian());
  REQUIRE(realDiagonal3.isHermitian());

  // hermitian matrices
  
  sclMath::matrix hermitian1(3,3);
  sclMath::matrix hermitian2(3,3);
  
  hermitian1.set(0,0,sclMath::ComplexScalar(5,0));
  hermitian1.set(0,1,sclMath::ComplexScalar(4,5));
  hermitian1.set(0,2,sclMath::ComplexScalar(6,-16));

  hermitian1.set(1,0,sclMath::ComplexScalar(4,-5));
  hermitian1.set(1,1,sclMath::ComplexScalar(13,0));
  hermitian1.set(1,2,sclMath::ComplexScalar(7));

  hermitian1.set(2,0,sclMath::ComplexScalar(6,16));
  hermitian1.set(2,1,sclMath::ComplexScalar(7));
  hermitian1.set(2,2,sclMath::ComplexScalar(-2.1));

  hermitian2.set(0,0,sclMath::ComplexScalar(7));
  hermitian2.set(0,1,sclMath::ComplexScalar(6,5));

  hermitian2.set(1,0,sclMath::ComplexScalar(6,-5));
  hermitian2.set(1,1,sclMath::ComplexScalar(-3));

  REQUIRE(hermitian1.isHermitian());
  REQUIRE(hermitian2.isHermitian());

}
