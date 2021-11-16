
#include <catch2/catch_test_macros.hpp>
#include "sclMatrix.hpp"
#include "sclMatrixOperations.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <iostream>
SCENARIO("scale matrix","[scale]" )
{
    sclMath::matrix m (3,4);
    //check the shape
    REQUIRE(m.getRows()==3);
    REQUIRE(m.getCols()==4);

    const sclMath::ComplexScalar c1 (1,1);
    const sclMath::ComplexScalar c2 (1,1);
    const sclMath::ComplexScalar c3 (1,1);

    //setting up the state of the matrix
    m.set(0,0,sclMath::ComplexScalar(c1)); 
    m.set(1,0,sclMath::ComplexScalar(c1)); 
    m.set(2,1,sclMath::ComplexScalar(c2)); 
    m.set(2,3,sclMath::ComplexScalar(c1)); 
    m.set(0,3,sclMath::ComplexScalar(c3)); 

    GIVEN("a complex matrix"){
      WHEN("scaled by zero"){
        m.scale(0);
        THEN("all are zero"){
          REQUIRE(m.get(0,0)==sclMath::ComplexScalar(0)); 
          REQUIRE(m.get(1,0)==sclMath::ComplexScalar(0)); 
          REQUIRE(m.get(2,1)==sclMath::ComplexScalar(0)); 
          REQUIRE(m.get(2,3)==sclMath::ComplexScalar(0)); 
          REQUIRE(m.get(0,3)==sclMath::ComplexScalar(0)); 
          
        }
      }

      WHEN("scale by 1 " ){
        m.scale(1);
        THEN("no value should chage"){
          REQUIRE(m.get(0,0)==sclMath::ComplexScalar(c1));
          REQUIRE(m.get(1,0)==sclMath::ComplexScalar(c1));
          REQUIRE(m.get(2,1)==sclMath::ComplexScalar(c2));
          REQUIRE(m.get(2,3)==sclMath::ComplexScalar(c1));
          REQUIRE(m.get(0,3)==sclMath::ComplexScalar(c3));
        }
      }
      WHEN("scale by 1+1i " ){
        m.scale(sclMath::ComplexScalar(1,1));
        THEN("all values should be multiplied by 1+i"){
          REQUIRE(m.get(0,0)==sclMath::ComplexScalar(c1)*sclMath::ComplexScalar(1,1));
          REQUIRE(m.get(1,0)==sclMath::ComplexScalar(c1)*sclMath::ComplexScalar(1,1));
          REQUIRE(m.get(2,1)==sclMath::ComplexScalar(c2)*sclMath::ComplexScalar(1,1));
          REQUIRE(m.get(2,3)==sclMath::ComplexScalar(c1)*sclMath::ComplexScalar(1,1));
          REQUIRE(m.get(0,3)==sclMath::ComplexScalar(c3)*sclMath::ComplexScalar(1,1));
        }
      }
      WHEN("scale by +1i " ){
        m.scale(sclMath::ComplexScalar(0,1));
        THEN("all values should be multiplied by i"){
          REQUIRE(m.get(0,0)==sclMath::ComplexScalar(c1)*sclMath::ComplexScalar(0,1));
          REQUIRE(m.get(1,0)==sclMath::ComplexScalar(c1)*sclMath::ComplexScalar(0,1));
          REQUIRE(m.get(2,1)==sclMath::ComplexScalar(c2)*sclMath::ComplexScalar(0,1));
          REQUIRE(m.get(2,3)==sclMath::ComplexScalar(c1)*sclMath::ComplexScalar(0,1));
          REQUIRE(m.get(0,3)==sclMath::ComplexScalar(c3)*sclMath::ComplexScalar(0,1));
        }
      }
      WHEN("scale by 3+0.5i " ){
        m.scale(sclMath::ComplexScalar(3,0.5));
        THEN("all values should be multiplied by 3+0.5i"){
          REQUIRE(m.get(0,0)==sclMath::ComplexScalar(c1)*sclMath::ComplexScalar(3,0.5));
          REQUIRE(m.get(1,0)==sclMath::ComplexScalar(c1)*sclMath::ComplexScalar(3,0.5));
          REQUIRE(m.get(2,1)==sclMath::ComplexScalar(c2)*sclMath::ComplexScalar(3,0.5));
          REQUIRE(m.get(2,3)==sclMath::ComplexScalar(c1)*sclMath::ComplexScalar(3,0.5));
          REQUIRE(m.get(0,3)==sclMath::ComplexScalar(c3)*sclMath::ComplexScalar(3,0.5));
        }
      }
    }


}
