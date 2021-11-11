#include <catch2/catch_test_macros.hpp>
#include  "matrix.h"
#include  "matrixOperations.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <iostream>
SCENARIO("trace of suare matrix","[trace]" )
{
  GIVEN("square matices"){
    sclMath::matrix m1 (1,1);
    sclMath::matrix m2 (3,3);
    sclMath::matrix m3 (6,6);
    WHEN ("one element in the main diagonal is changes"){
      m1.set(0,0,sclMath::ComplexScalar(1,1));

      m2.set(0,0,sclMath::ComplexScalar(1,1));
      m2.set(1,1,sclMath::ComplexScalar(0,1));
      m2.set(2,2,sclMath::ComplexScalar(1,0));

      m3.set(0,0,sclMath::ComplexScalar(1,1));
      m3.set(2,2,sclMath::ComplexScalar(1,0));
      m3.set(5,5,sclMath::ComplexScalar(0,1));

      THEN("the trace changes"){
        const sclMath::ComplexScalar m1Trace = m1.trace();
        const sclMath::ComplexScalar m2Trace = m2.trace();
        const sclMath::ComplexScalar m3Trace = m3.trace();

        REQUIRE(m1Trace==sclMath::ComplexScalar(1,1));
        REQUIRE(m2Trace==sclMath::ComplexScalar(2,2));
        REQUIRE(m3Trace==sclMath::ComplexScalar(2,2));

        WHEN ("elements outside the main diagonal changed"){
          m2.set(1,0,sclMath::ComplexScalar(0,1));

          m3.set(1,0,sclMath::ComplexScalar(0,1));
          m3.set(1,2,sclMath::ComplexScalar(1,.1));

          THEN("the trace does not change"){
            REQUIRE(m1Trace==sclMath::ComplexScalar(1,1));
            REQUIRE(m2Trace==sclMath::ComplexScalar(2,2));
            REQUIRE(m3Trace==sclMath::ComplexScalar(2,2));
          }
        }
        WHEN ("elements in the main diagonal changed"){

          m1.set(0,0,sclMath::ComplexScalar(0,1));

          m2.set(0,0,sclMath::ComplexScalar(0,1));

          m3.set(1,1,sclMath::ComplexScalar(0,1));
          
          REQUIRE(m1.trace()!=m1Trace);
          REQUIRE(m2.trace()!=m2Trace);
          REQUIRE(m3.trace()!=m3Trace);

        }
      }
    }
  }




  // sclMath::matrix m3 (7,7);
  // sclMath::matrix m4 (9,9);
  // sclMath::matrix m5 (2,2);


}
