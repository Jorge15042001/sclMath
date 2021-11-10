#include <catch2/catch_test_macros.hpp>
#include  "matrix.h"
#include  "matrixOperations.h"
#include <iostream>
#include <vector>


TEST_CASE( "square matrix creation", "[creation]" ) {
  //prove square matrix
  sclMath::matrix m1 (2,2);
  REQUIRE(m1.getRows()==2);
  REQUIRE(m1.getCols()==2);

  sclMath::matrix m2 (4,4);
  REQUIRE(m2.getRows()==4);
  REQUIRE(m2.getCols()==4);

  sclMath::matrix m3 (10,10);
  REQUIRE(m3.getRows()==10);
  REQUIRE(m3.getCols()==10);
}

TEST_CASE( "non-squre matrix creation", "[creation]" ) {
  // non square matrices
  sclMath::matrix m4 (1,3);
  REQUIRE(m4.getRows()==1);
  REQUIRE(m4.getCols()==3);

  sclMath::matrix m5 (4,1);
  REQUIRE(m5.getRows()==4);
  REQUIRE(m5.getCols()==1);
}

TEST_CASE( "empty matrix creation", "[creation]" ) {

  //empty matrix
  CHECK_THROWS(sclMath::matrix (0,1));
  CHECK_THROWS(sclMath::matrix (0,4));
  CHECK_THROWS(sclMath::matrix (0,10));
  CHECK_THROWS(sclMath::matrix (0,5));
  CHECK_THROWS(sclMath::matrix (0,21));

  CHECK_THROWS(sclMath::matrix (1,0));
  CHECK_THROWS(sclMath::matrix (3,0));
  CHECK_THROWS(sclMath::matrix (7,0));
  CHECK_THROWS(sclMath::matrix (8,0));
  CHECK_THROWS(sclMath::matrix (22,0));

}


TEST_CASE( "negative size matrix", "[creation]" ) {
  CHECK_THROWS(sclMath::matrix (-1,2));
  CHECK_THROWS(sclMath::matrix (-3,10));
  CHECK_THROWS(sclMath::matrix (-8,0));
  CHECK_THROWS(sclMath::matrix (-2,2));
  CHECK_THROWS(sclMath::matrix (-9,10));
  CHECK_THROWS(sclMath::matrix (-18,0));

  CHECK_THROWS(sclMath::matrix (2,-1));
  CHECK_THROWS(sclMath::matrix (1,-10));
  CHECK_THROWS(sclMath::matrix (0,-1));
  CHECK_THROWS(sclMath::matrix (2,-4));
  CHECK_THROWS(sclMath::matrix (1,-10));
  CHECK_THROWS(sclMath::matrix (0,-1));

  CHECK_THROWS(sclMath::matrix (-0,-1));
  CHECK_THROWS(sclMath::matrix (-1,-9));
  CHECK_THROWS(sclMath::matrix (-9,-4));
  CHECK_THROWS(sclMath::matrix (-10,-12));
  CHECK_THROWS(sclMath::matrix (-21,-13));
  CHECK_THROWS(sclMath::matrix (-10,-10));


}

// TEST_CASE( "test get and set", "[get and set]" ) {
//   const sclMath::Scalar rows = 3;
//   const sclMath::Scalar cols = 2;
//   sclMath::matrix m (2,2);
// }
