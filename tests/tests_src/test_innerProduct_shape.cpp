
#include <catch2/catch_test_macros.hpp>
#include  "matrix.h"
#include  "matrixOperations.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <iostream>
TEST_CASE("innerProduct of diferent shape matrix ","[trace]" )
{
  sclMath::matrix m1 (1,2);
  sclMath::matrix m2 (3,1);
  sclMath::matrix m3 (7,8);
  sclMath::matrix m4 (9,4);
  sclMath::matrix m5 (2,9);
  sclMath::matrix m6 (3,2);

  CHECK_THROWS(sclMath::innerProduct(m1,m2));
  CHECK_THROWS(sclMath::innerProduct(m2,m3));
  CHECK_THROWS(sclMath::innerProduct(m1,m3));
  CHECK_THROWS(sclMath::innerProduct(m3,m5));
  CHECK_THROWS(sclMath::innerProduct(m2,m4));
  CHECK_THROWS(sclMath::innerProduct(m2,m6));

}
TEST_CASE("innerProduct  of same shape matrix","[trace]" )
{
  sclMath::matrix m1 (1,1);
  sclMath::matrix m2 (3,3);
  sclMath::matrix m3 (7,7);
  sclMath::matrix m4 (9,9);
  sclMath::matrix m5 (2,2);

  CHECK_NOTHROW(sclMath::innerProduct(m1,m1));
  CHECK_NOTHROW(sclMath::innerProduct(m2,m2));
  CHECK_NOTHROW(sclMath::innerProduct(m3,m3));
  CHECK_NOTHROW(sclMath::innerProduct(m4,m4));
  CHECK_NOTHROW(sclMath::innerProduct(m5,m5));


}
