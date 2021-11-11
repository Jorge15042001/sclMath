#include <catch2/catch_test_macros.hpp>
#include  "matrix.h"
#include  "matrixOperations.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <iostream>
TEST_CASE("mul of incompatible shapes matrices ","[mul]" )
{
  sclMath::matrix m1 (1,2);
  sclMath::matrix m2 (3,1);
  sclMath::matrix m3 (7,8);
  sclMath::matrix m4 (9,4);
  sclMath::matrix m5 (2,9);

  CHECK_THROWS(m1*m2);
  CHECK_THROWS(m2*m3);
  CHECK_THROWS(m1*m3);
  CHECK_THROWS(m3*m5);
  CHECK_THROWS(m2*m4);

}
TEST_CASE("mul of compatible shape matrices","[mul]" )
{
  sclMath::matrix m1 (1,3);
  sclMath::matrix m2 (3,2);
  sclMath::matrix m3 (7,7);
  sclMath::matrix m4 (9,7);
  sclMath::matrix m5 (2,9);


  //different shaped matrices
  CHECK_NOTHROW(m1*m2);
  CHECK_NOTHROW(m2*m5);
  CHECK_NOTHROW(m4*m3);
  CHECK_NOTHROW(m5*m4);

}
TEST_CASE("output shape of matrix mul","[sub]"){
  sclMath::matrix m1 (1,3);
  sclMath::matrix m2 (3,2);
  sclMath::matrix m3 (7,7);
  sclMath::matrix m4 (9,7);
  sclMath::matrix m5 (2,9);

  sclMath::matrix Result1 = m1*m2;
  sclMath::matrix Result2 = m2*m5;
  sclMath::matrix Result3 = m4*m3;
  sclMath::matrix Result4 = m5*m4;

  CHECK(m1.getRows()==Result1.getRows());
  CHECK(m2.getCols()==Result1.getCols());

  CHECK(m2.getRows()==Result2.getRows());
  CHECK(m5.getCols()==Result2.getCols());

  CHECK(m4.getRows()==Result3.getRows());
  CHECK(m3.getCols()==Result3.getCols());

  CHECK(m5.getRows()==Result4.getRows());
  CHECK(m4.getCols()==Result4.getCols());

}
