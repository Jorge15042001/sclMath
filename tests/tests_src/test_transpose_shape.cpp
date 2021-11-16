

#include <catch2/catch_test_macros.hpp>
#include "sclMatrix.hpp"
#include "sclMatrixOperations.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <iostream>
SCENARIO("conjugate of matrix","[transpose]")
{
  GIVEN("square matrices with shape (n,m)"){
    sclMath::matrix m1 (1,1);
    sclMath::matrix m2 (2,2);
    sclMath::matrix m3 (4,4);
    sclMath::matrix m4 (7,7);
    WHEN("matrices are transposed"){
      m1.transpose();
      m2.transpose();
      m3.transpose();
      m4.transpose();
      THEN("resulting matrices are still squared "){
        REQUIRE(m1.getCols()==m1.getRows());
        REQUIRE(m2.getCols()==m2.getRows());
        REQUIRE(m3.getCols()==m3.getRows());
        REQUIRE(m4.getCols()==m4.getRows());

        REQUIRE(m1.getCols()==1);
        REQUIRE(m2.getCols()==2);
        REQUIRE(m3.getCols()==4);
        REQUIRE(m4.getCols()==7);

        REQUIRE(m1.getRows()==1);
        REQUIRE(m2.getRows()==2);
        REQUIRE(m3.getRows()==4);
        REQUIRE(m4.getRows()==7);
      }
    }
  }
  GIVEN("non-squared matrices of shape(n,m)"){
    sclMath::matrix m1 (1,4);
    sclMath::matrix m2 (2,1);
    sclMath::matrix m3 (4,7);
    sclMath::matrix m4 (7,9);
    WHEN("matrices are transposed"){
      m1.transpose();
      m2.transpose();
      m3.transpose();
      m4.transpose();
      THEN("resulting matrices have swapedthe number of colmuns and rows "){

        REQUIRE(m1.getCols()==1);
        REQUIRE(m2.getCols()==2);
        REQUIRE(m3.getCols()==4);
        REQUIRE(m4.getCols()==7);

        REQUIRE(m1.getRows()==4);
        REQUIRE(m2.getRows()==1);
        REQUIRE(m3.getRows()==7);
        REQUIRE(m4.getRows()==9);
      }
    }
  }
}

