#include <catch2/catch_test_macros.hpp>
#include  "matrix.h"
#include  "matrixOperations.h"
#include <cstdlib>
#include <iostream>
#include <vector>

SCENARIO("getting and setting in matrix","[set,get]" )
{
  GIVEN("A comlex matrix of shape (4,4)"){
    sclMath::matrix m (4,4);
    //check the shape
    REQUIRE(m.getRows()==4);
    REQUIRE(m.getCols()==4);
    
    WHEN ("When the a value in the matrix is set"){
      m.set(0,0,sclMath::ComplexScalar(0,1)); 
      m.set(1,3,sclMath::ComplexScalar(1,1)); 
      m.set(2,1,sclMath::ComplexScalar(2,1.1)); 
      m.set(3,0,sclMath::ComplexScalar(0.5,1.2)); 

      m.set(3,1,sclMath::ComplexScalar(0,-1.1)); 
      m.set(2,2,sclMath::ComplexScalar(-9,1)); 
      m.set(1,2,sclMath::ComplexScalar(-0.4,1.3)); 
      m.set(1,1,sclMath::ComplexScalar(0.2,1.2)); 

      THEN("the geet should return the same value"){
        REQUIRE(m.get(0,0)==sclMath::ComplexScalar(0,1)); 
        REQUIRE(m.get(1,3)==sclMath::ComplexScalar(1,1)); 
        REQUIRE(m.get(2,1)==sclMath::ComplexScalar(2,1.1)); 
        REQUIRE(m.get(3,0)==sclMath::ComplexScalar(0.5,1.2)); 

        REQUIRE(m.get(3,1)==sclMath::ComplexScalar(0,-1.1)); 
        REQUIRE(m.get(2,2)==sclMath::ComplexScalar(-9,1)); 
        REQUIRE(m.get(1,2)==sclMath::ComplexScalar(-0.4,1.3)); 
        REQUIRE(m.get(1,1)==sclMath::ComplexScalar(0.2,1.2)); 

      }
    }
  }
}
