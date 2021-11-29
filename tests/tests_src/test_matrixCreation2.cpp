#include "sclMatrix/sclMatrix.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("sclMatrix constructor with list parameter for RealMatrix",
          "[sclMatrix constructor]") {
  sclMath::RealMatrix m1(2, 2, {1, 1, 1, 1});

  REQUIRE(m1.get(0, 0) == 1);
  REQUIRE(m1.get(0, 1) == 1);
  REQUIRE(m1.get(1, 0) == 1);
  REQUIRE(m1.get(1, 1) == 1);

  sclMath::RealMatrix m2(2, 2, {0, 1, 0, 1});

  REQUIRE(m2.get(0, 0) == 0);
  REQUIRE(m2.get(0, 1) == 1);
  REQUIRE(m2.get(1, 0) == 0);
  REQUIRE(m2.get(1, 1) == 1);

  CHECK_NOTHROW(
      sclMath::RealMatrix{2, 2, std::vector<sclMath::RealScalar>{1, 1, 1, 1}});

  CHECK_THROWS(sclMath::RealMatrix{1, 1, {0, 0, 0, 0}});
  CHECK_THROWS(sclMath::RealMatrix{2, 1, {0, 0, 0, 0}});
  CHECK_THROWS(sclMath::RealMatrix{1, 8, {0, 0, 0, 0}});
  CHECK_THROWS(sclMath::RealMatrix{2, 3, {0, 0, 0, 0}});
  CHECK_THROWS(sclMath::RealMatrix{1, 3, {0, 0, 0, 0}});
  CHECK_THROWS(sclMath::RealMatrix{1, 3, {0, 0, 0, 0}});

  CHECK_NOTHROW(sclMath::RealMatrix{1, 1, {1}});
  CHECK_NOTHROW(sclMath::RealMatrix{2, 1, {1, 1}});
  CHECK_NOTHROW(sclMath::RealMatrix{1, 2, {1, 1}});
  CHECK_NOTHROW(sclMath::RealMatrix{1, 3, {1, 1, 1}});
  CHECK_NOTHROW(sclMath::RealMatrix{3, 1, {1, 1, 1}});
  CHECK_NOTHROW(sclMath::RealMatrix{1, 4, {1, 1, 1, 1}});
  CHECK_NOTHROW(sclMath::RealMatrix{4, 1, {1, 1, 1, 1}});
  CHECK_NOTHROW(sclMath::RealMatrix{2, 2, {1, 1, 1, 1}});
}

TEST_CASE("sclMatrix constructor with list parameter for ComplexMatrix",
          "[sclMatrix constructor]") {
  sclMath::ComplexMatrix m1(2, 2, {1, {1, 1}, {1, 2}, {1}});

  REQUIRE(m1.get(0, 0) == sclMath::ComplexScalar{1});
  REQUIRE(m1.get(0, 1) == sclMath::ComplexScalar{1, 1});
  REQUIRE(m1.get(1, 0) == sclMath::ComplexScalar{1, 2});
  REQUIRE(m1.get(1, 1) == sclMath::ComplexScalar{1});

  sclMath::ComplexMatrix m2(
      2, 2, {0, sclMath::ComplexScalar(1, 1), 0, sclMath::RealScalar(1)});

  REQUIRE(m2.get(0, 0) == sclMath::ComplexScalar{0});
  REQUIRE(m2.get(0, 1) == sclMath::ComplexScalar{1, 1});
  REQUIRE(m2.get(1, 0) == sclMath::ComplexScalar{0});
  REQUIRE(m2.get(1, 1) == sclMath::ComplexScalar(1));

  CHECK_NOTHROW(sclMath::ComplexMatrix{
      2, 2, std::vector<sclMath::ComplexScalar>{1, 1, 1, 1}});

  CHECK_THROWS(sclMath::ComplexMatrix{1, 1, {0, 0, 0, 0}});
  CHECK_THROWS(sclMath::ComplexMatrix{2, 1, {0, 0, 0, 0}});
  CHECK_THROWS(sclMath::ComplexMatrix{1, 8, {0, 0, 0, 0}});
  CHECK_THROWS(sclMath::ComplexMatrix{2, 3, {0, 0, 0, 0}});
  CHECK_THROWS(sclMath::ComplexMatrix{1, 3, {0, 0, 0, 0}});
  CHECK_THROWS(sclMath::ComplexMatrix{1, 3, {0, 0, 0, 0}});

  CHECK_NOTHROW(sclMath::ComplexMatrix{1, 1, {1}});
  CHECK_NOTHROW(sclMath::ComplexMatrix{2, 1, {1, 1}});
  CHECK_NOTHROW(sclMath::ComplexMatrix{1, 2, {1, 1}});
  CHECK_NOTHROW(sclMath::ComplexMatrix{1, 3, {1, 1, 1}});
  CHECK_NOTHROW(sclMath::ComplexMatrix{3, 1, {1, 1, 1}});
  CHECK_NOTHROW(sclMath::ComplexMatrix{1, 4, {1, 1, 1, 1}});
  CHECK_NOTHROW(sclMath::ComplexMatrix{4, 1, {1, 1, 1, 1}});
  CHECK_NOTHROW(sclMath::ComplexMatrix{2, 2, {1, 1, 1, 1}});
}
