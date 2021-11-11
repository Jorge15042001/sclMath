
#include <catch2/catch_test_macros.hpp>
#include  "matrix.h"
#include  "matrixOperations.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <iostream>
SCENARIO("matrix addition result","[result]" )
{

  GIVEN ("2 matrices of compatible sizes"){
    //TODO: write indentity matrix class;
    sclMath::matrix identity(4,4);
    //TODO: write zero matrix class
    sclMath::matrix zero_4_4(4,4);
    sclMath::matrix zero_3_4(3,4);

    sclMath::matrix m1 (3,4);
    sclMath::matrix m2 (3,4);

    m1.set(0,0,sclMath::ComplexScalar(1,1));
    m1.set(0,2,sclMath::ComplexScalar(0,1));
    m1.set(0,3,sclMath::ComplexScalar(1,0));
    m1.set(1,0,sclMath::ComplexScalar(3,3));
    m1.set(2,0,sclMath::ComplexScalar(1,3));
    m1.set(2,3,sclMath::ComplexScalar(3,1));


    m2.set(0,1,sclMath::ComplexScalar(2,1));
    m2.set(0,2,sclMath::ComplexScalar(0,2));
    m2.set(0,3,sclMath::ComplexScalar(3,0));
    m2.set(1,1,sclMath::ComplexScalar(1,9));
    m2.set(2,1,sclMath::ComplexScalar(2,2));
    m2.set(2,2,sclMath::ComplexScalar(1,0));
    
    identity.set(0,0,sclMath::ComplexScalar(1,0));
    identity.set(1,1,sclMath::ComplexScalar(1,0));
    identity.set(2,2,sclMath::ComplexScalar(1,0));
    identity.set(3,3,sclMath::ComplexScalar(1,0));

    WHEN ("a matrix is added with the nullity"){
      const sclMath::matrix copyOfm1 = m1+zero_3_4;
      const sclMath::matrix copyOfm2 = m2+zero_3_4;

      THEN ("the result is the same matrix"){
        REQUIRE(m1 == copyOfm1);
        REQUIRE(m2 == copyOfm2);
      }
    }
    WHEN("A and B are added togeter"){
      const sclMath::matrix result = m1+m2;

      //TODO: complete the test
      THEN("the result should match the definition of matrix addition")      {
        //TODO: easier api to set this values is required
        //array([[1.+1.j, 2.+1.j, 0.+3.j, 4.+0.j],
         // [3.+3.j, 1.+9.j, 0.+0.j, 0.+0.j],
         // [1.+3.j, 2.+2.j, 1.+0.j, 3.+1.j]])
         //
        sclMath::matrix expectedResult (3,4);

        expectedResult.set(0,0,sclMath::ComplexScalar(1,1));
        expectedResult.set(0,1,sclMath::ComplexScalar(2,1));
        expectedResult.set(0,2,sclMath::ComplexScalar(0,3));
        expectedResult.set(0,3,sclMath::ComplexScalar(4,0));

        expectedResult.set(1,0,sclMath::ComplexScalar(3,3));
        expectedResult.set(1,1,sclMath::ComplexScalar(1,9));
        expectedResult.set(1,2,sclMath::ComplexScalar(0,0));
        expectedResult.set(1,3,sclMath::ComplexScalar(0,0));

        expectedResult.set(2,0,sclMath::ComplexScalar(1,3));
        expectedResult.set(2,1,sclMath::ComplexScalar(2,2));
        expectedResult.set(2,2,sclMath::ComplexScalar(1,0));
        expectedResult.set(2,3,sclMath::ComplexScalar(3,1));

        REQUIRE(expectedResult==result);

      }

    }

  }
}
