#include <catch2/catch_test_macros.hpp>
#include "sclMatrix.hpp"
#include "sclMatrixOperations.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <iostream>
TEST_CASE("trace shape of non-square matrix","[trace]" )
{
  sclMath::matrix m1 (1,2);
  sclMath::matrix m2 (3,1);
  sclMath::matrix m3 (7,8);
  sclMath::matrix m4 (9,4);
  sclMath::matrix m5 (2,9);

  CHECK_THROWS(m1.trace());
  CHECK_THROWS(m2.trace());
  CHECK_THROWS(m3.trace());
  CHECK_THROWS(m4.trace());
  CHECK_THROWS(m5.trace());

}
TEST_CASE("trace shape of suare matrix","[trace]" )
{
  sclMath::matrix m1 (1,1);
  sclMath::matrix m2 (3,3);
  sclMath::matrix m3 (7,7);
  sclMath::matrix m4 (9,9);
  sclMath::matrix m5 (2,2);

  CHECK_NOTHROW(m1.trace());
  CHECK_NOTHROW(m2.trace());
  CHECK_NOTHROW(m3.trace());
  CHECK_NOTHROW(m4.trace());
  CHECK_NOTHROW(m5.trace());

}
