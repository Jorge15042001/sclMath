#include <catch2/catch_test_macros.hpp>
#include  "matrix.h"
#include  "matrixOperations.h"
#include <iostream>


TEST_CASE( "test creation", "[creation]" ) {
  sclMath::matrix m (2,2);
  REQUIRE(m.getRows()==2);
  REQUIRE(m.getCols()==2);
}

