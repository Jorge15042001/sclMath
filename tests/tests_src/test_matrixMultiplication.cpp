#include <catch2/catch_test_macros.hpp>
#include  "matrix.h"
#include  "matrixOperations.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <iostream>
SCENARIO("matrix multiplication result","[result]" )
{

  GIVEN ("2 matrices of compatible sizes"){
    //TODO: write indentity matrix class;
    sclMath::matrix identity(4,4);
    //TODO: write zero matrix class
    sclMath::matrix zero_4_4(4,4);
    sclMath::matrix zero_3_4(3,4);

    sclMath::matrix m1 (3,4);
    sclMath::matrix m2 (4,4);

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

    WHEN ("a matrix is multiplied by the identity"){
      const sclMath::matrix copyOfm1 = m1*identity;
      const sclMath::matrix copyOfm2 = m2*identity;

      THEN ("is the same matrix"){
        REQUIRE(m1 == copyOfm1);
        REQUIRE(m2 == copyOfm2);
      }
    }
    WHEN ("is multiplied by 0"){
      const sclMath::matrix copyOfm1 = m1*zero_4_4;
      const sclMath::matrix copyOfm2 = m2*zero_4_4;

      THEN ("is the same as zero"){
        REQUIRE(zero_3_4 == copyOfm1);
        REQUIRE(zero_4_4 == copyOfm2);
      }

    }
    WHEN("A and b are multiplied togeter"){
      const sclMath::matrix result = m1*m2;

      //TODO: complete the test
      THEN("the result should match the definition of matrix multiplication")      {
        //TODO: easier api to set this values is required
        sclMath::matrix expectedResult (3,4);

        expectedResult.set(0,1,sclMath::ComplexScalar(-1,5));
        expectedResult.set(0,2,sclMath::ComplexScalar(-2,3));
        expectedResult.set(0,3,sclMath::ComplexScalar(3,3));

        expectedResult.set(1,1,sclMath::ComplexScalar(3,9));
        expectedResult.set(1,2,sclMath::ComplexScalar(-6,6));
        expectedResult.set(1,3,sclMath::ComplexScalar(9,9));

        expectedResult.set(2,1,sclMath::ComplexScalar(-1,7));
        expectedResult.set(2,2,sclMath::ComplexScalar(-6,2));
        expectedResult.set(2,3,sclMath::ComplexScalar(3,9));

        REQUIRE(expectedResult==result);

      }

    }

  }
}
