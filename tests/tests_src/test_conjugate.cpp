
#include <catch2/catch_test_macros.hpp>
#include  "matrix.h"
#include  "matrixOperations.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <iostream>
SCENARIO("conjugate of matrix","[conjugate]" )
{
  GIVEN("A comlex matrix of shape (3,4)"){
    sclMath::matrix m (3,4);
    //check the shape
    REQUIRE(m.getRows()==3);
    REQUIRE(m.getCols()==4);

    //setting up the state of the matrix
    m.set(0,0,sclMath::ComplexScalar(0,1)); 
    m.set(1,3,sclMath::ComplexScalar(1,1)); 
    m.set(2,1,sclMath::ComplexScalar(2,1.1)); 
    m.set(2,0,sclMath::ComplexScalar(0.5,1.2)); 

    m.set(2,2,sclMath::ComplexScalar(0,-1.1)); 
    m.set(0,2,sclMath::ComplexScalar(-9,1)); 
    m.set(1,2,sclMath::ComplexScalar(-0.4,1.3)); 
    m.set(1,1,sclMath::ComplexScalar(0.2,1.2)); 
    
    WHEN ("when the matrix is conjugated"){

      m.conjugate();

      THEN("the value at each position is the conjugate"){
        REQUIRE(m.get(0,0)==sclMath::ComplexScalar(0,-1)); 
        REQUIRE(m.get(1,3)==sclMath::ComplexScalar(1,-1)); 
        REQUIRE(m.get(2,1)==sclMath::ComplexScalar(2,-1.1)); 
        REQUIRE(m.get(2,0)==sclMath::ComplexScalar(0.5,-1.2)); 

        REQUIRE(m.get(2,2)==sclMath::ComplexScalar(0,1.1)); 
        REQUIRE(m.get(0,2)==sclMath::ComplexScalar(-9,-1)); 
        REQUIRE(m.get(1,2)==sclMath::ComplexScalar(-0.4,-1.3)); 
        REQUIRE(m.get(1,1)==sclMath::ComplexScalar(0.2,-1.2)); 

        //shape does not change
        REQUIRE(m.getRows()==3);
        REQUIRE(m.getCols()==4);
      }

    }
    WHEN ("the matrix is conjugated twice "){
      m.conjugate().conjugate();

      THEN("the value at each position should e the same "){
        REQUIRE(m.get(0,0)==sclMath::ComplexScalar(0,1)); 
        REQUIRE(m.get(1,3)==sclMath::ComplexScalar(1,1)); 
        REQUIRE(m.get(2,1)==sclMath::ComplexScalar(2,1.1)); 
        REQUIRE(m.get(2,0)==sclMath::ComplexScalar(0.5,1.2)); 

        REQUIRE(m.get(2,2)==sclMath::ComplexScalar(0,-1.1)); 
        REQUIRE(m.get(0,2)==sclMath::ComplexScalar(-9,1)); 
        REQUIRE(m.get(1,2)==sclMath::ComplexScalar(-0.4,1.3)); 
        REQUIRE(m.get(1,1)==sclMath::ComplexScalar(0.2,1.2)); 

        //shape does not change
        REQUIRE(m.getRows()==3);
        REQUIRE(m.getCols()==4);
      }
    }
  }
}