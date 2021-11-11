

#include <catch2/catch_test_macros.hpp>
#include  "matrix.h"
#include  "matrixOperations.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <iostream>
TEST_CASE("sum of diferent shape matrix ","[sum]" )
{
  sclMath::matrix m1 (1,2);
  sclMath::matrix m2 (3,1);
  sclMath::matrix m3 (7,8);
  sclMath::matrix m4 (9,4);
  sclMath::matrix m5 (2,9);

  CHECK_THROWS(m1+m2);
  CHECK_THROWS(m2+m3);
  CHECK_THROWS(m1+m3);
  CHECK_THROWS(m3+m5);
  CHECK_THROWS(m2+m4);

}
TEST_CASE("sum  of same shape matrix","[sum]" )
{
  sclMath::matrix m1 (1,1);
  sclMath::matrix m2 (3,3);
  sclMath::matrix m3 (7,7);
  sclMath::matrix m4 (9,9);
  sclMath::matrix m5 (2,2);

  CHECK_NOTHROW(m1+m1);
  CHECK_NOTHROW(m2+m2);
  CHECK_NOTHROW(m3+m3);
  CHECK_NOTHROW(m4+m4);
  CHECK_NOTHROW(m5+m5);


}
