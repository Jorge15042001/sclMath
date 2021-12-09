#include "sclMatrix/sclMatrixComparison.hpp"
#include "sclMatrix/sclMatrixMultiplication.hpp"

#include <catch2/catch_test_macros.hpp>

SCENARIO("matrix multiplication result", "[sclMatrixMultiplication]") {

  GIVEN("2  complex matrices of compatible sizes") {
    // TODO: write indentity matrix class;
    sclMath::ComplexMatrix identity(4, 4);
    // TODO: write zero matrix class
    sclMath::ComplexMatrix zero_4_4(4, 4);
    sclMath::ComplexMatrix zero_3_4(3, 4);

    sclMath::ComplexMatrix m1(3, 4);
    sclMath::ComplexMatrix m2(4, 4);

    m1.set(0, 0, sclMath::ComplexScalar(1, 1));
    m1.set(0, 2, sclMath::ComplexScalar(0, 1));
    m1.set(0, 3, sclMath::ComplexScalar(1, 0));
    m1.set(1, 0, sclMath::ComplexScalar(3, 3));
    m1.set(2, 0, sclMath::ComplexScalar(1, 3));
    m1.set(2, 3, sclMath::ComplexScalar(3, 1));

    m2.set(0, 1, sclMath::ComplexScalar(2, 1));
    m2.set(0, 2, sclMath::ComplexScalar(0, 2));
    m2.set(0, 3, sclMath::ComplexScalar(3, 0));
    m2.set(1, 1, sclMath::ComplexScalar(1, 9));
    m2.set(2, 1, sclMath::ComplexScalar(2, 2));
    m2.set(2, 2, sclMath::ComplexScalar(1, 0));

    identity.set(0, 0, sclMath::ComplexScalar(1, 0));
    identity.set(1, 1, sclMath::ComplexScalar(1, 0));
    identity.set(2, 2, sclMath::ComplexScalar(1, 0));
    identity.set(3, 3, sclMath::ComplexScalar(1, 0));

    WHEN("a matrix is multiplied by the identity") {
      const sclMath::ComplexMatrix copyOfm1 = m1 * identity;
      const sclMath::ComplexMatrix copyOfm2 = m2 * identity;

      THEN("is the same matrix") {
        REQUIRE(m1 == copyOfm1);
        REQUIRE(m2 == copyOfm2);
      }
    }
    WHEN("is multiplied by 0") {
      const sclMath::ComplexMatrix copyOfm1 = m1 * zero_4_4;
      const sclMath::ComplexMatrix copyOfm2 = m2 * zero_4_4;

      THEN("is the same as zero") {
        REQUIRE(zero_3_4 == copyOfm1);
        REQUIRE(zero_4_4 == copyOfm2);
      }
    }
    WHEN("A and b are multiplied togeter") {
      const sclMath::ComplexMatrix result = m1 * m2;

      // TODO: complete the test
      THEN("the result should match the definition of matrix multiplication") {
        // TODO: easier api to set this values is required
        sclMath::ComplexMatrix expectedResult(3, 4);

        expectedResult.set(0, 1, sclMath::ComplexScalar(-1, 5));
        expectedResult.set(0, 2, sclMath::ComplexScalar(-2, 3));
        expectedResult.set(0, 3, sclMath::ComplexScalar(3, 3));

        expectedResult.set(1, 1, sclMath::ComplexScalar(3, 9));
        expectedResult.set(1, 2, sclMath::ComplexScalar(-6, 6));
        expectedResult.set(1, 3, sclMath::ComplexScalar(9, 9));

        expectedResult.set(2, 1, sclMath::ComplexScalar(-1, 7));
        expectedResult.set(2, 2, sclMath::ComplexScalar(-6, 2));
        expectedResult.set(2, 3, sclMath::ComplexScalar(3, 9));

        REQUIRE(expectedResult == result);
      }
    }
  }
  GIVEN("2 real matrices of compatible sizes") {
    // TODO: write indentity matrix class;
    sclMath::RealMatrix identity(4, 4);
    // TODO: write zero matrix class
    sclMath::RealMatrix zero_4_4(4, 4);
    sclMath::RealMatrix zero_3_4(3, 4);

    sclMath::RealMatrix m1(3, 4);
    sclMath::RealMatrix m2(4, 4);

    m1.set(0, 0, 1);
    m1.set(0, 2, 0);
    m1.set(0, 3, 1);
    m1.set(1, 0, 3);
    m1.set(2, 0, 1);
    m1.set(2, 3, 3);

    m2.set(0, 1, 2);
    m2.set(0, 2, 0);
    m2.set(0, 3, 3);
    m2.set(1, 1, 1);
    m2.set(2, 1, 2);
    m2.set(2, 2, 1);

    identity.set(0, 0, 1);
    identity.set(1, 1, 1);
    identity.set(2, 2, 1);
    identity.set(3, 3, 1);

    WHEN("a matrix is multiplied by the identity") {
      const sclMath::RealMatrix copyOfm1 = m1 * identity;
      const sclMath::RealMatrix copyOfm2 = m2 * identity;

      THEN("is the same matrix") {
        REQUIRE(m1 == copyOfm1);
        REQUIRE(m2 == copyOfm2);
      }
    }
    WHEN("is multiplied by 0") {
      const sclMath::RealMatrix copyOfm1 = m1 * zero_4_4;
      const sclMath::RealMatrix copyOfm2 = m2 * zero_4_4;

      THEN("is the same as zero") {
        REQUIRE(zero_3_4 == copyOfm1);
        REQUIRE(zero_4_4 == copyOfm2);
      }
    }
    WHEN("A and b are multiplied togeter") {
      const sclMath::RealMatrix result = m1 * m2;

      // TODO: complete the test
      THEN("the result should match the definition of matrix multiplication") {
        // TODO: easier api to set this values is required
        sclMath::RealMatrix expectedResult(3, 4);

        expectedResult.set(0, 1, 2);
        expectedResult.set(0, 3, 3);

        expectedResult.set(1, 1, 6);
        expectedResult.set(1, 3, 9);

        expectedResult.set(2, 1, 2);
        expectedResult.set(2, 3, 3);

        REQUIRE(expectedResult == result);
      }
    }
  }
  GIVEN("real matrices and complex matrices of compatible sizes") {
    // TODO: write indentity matrix class;
    sclMath::ComplexMatrix identity(4, 4);
    // TODO: write zero matrix class
    sclMath::RealMatrix zero_4_4(4, 4);
    sclMath::ComplexMatrix zero_3_4(3, 4);

    sclMath::RealMatrix m1(3, 4);
    sclMath::ComplexMatrix m2(4, 4);

    m1.set(0, 0, 1);
    m1.set(0, 2, 0);
    m1.set(0, 3, 1);
    m1.set(1, 0, 3);
    m1.set(2, 0, 1);
    m1.set(2, 3, 3);

    m2.set(0, 1, {2, 1});
    m2.set(0, 2, {0, 1});
    m2.set(0, 3, {3, -1});
    m2.set(1, 1, {1, -2});
    m2.set(2, 1, {2, 4});
    m2.set(2, 2, {1, -4});

    identity.set(0, 0, 1);
    identity.set(1, 1, 1);
    identity.set(2, 2, 1);
    identity.set(3, 3, 1);

    WHEN("a matrix is multiplied by the identity") {
      const sclMath::ComplexMatrix copyOfm1 = m1 * identity;
      const sclMath::ComplexMatrix copyOfm2 = m2 * identity;

      THEN("is the same matrix") {
        REQUIRE(m1 == copyOfm1);
        REQUIRE(m2 == copyOfm2);
      }
    }
    WHEN("is multiplied by 0") {
      const sclMath::RealMatrix copyOfm1 = m1 * zero_4_4;
      const sclMath::ComplexMatrix copyOfm2 = m2 * zero_4_4;

      THEN("is the same as zero") {
        REQUIRE(zero_3_4 == copyOfm1);
        REQUIRE(zero_4_4 == copyOfm2);
      }
    }
    WHEN("A and b are multiplied togeter") {
      const sclMath::ComplexMatrix result = m1 * m2;

      // TODO: complete the test
      THEN("the result should match the definition of matrix multiplication") {
        // TODO: easier api to set this values is required
        sclMath::ComplexMatrix expectedResult(3, 4);

        expectedResult.set(0, 1, {2, 1});
        expectedResult.set(0, 2, {0, 1});
        expectedResult.set(0, 3, {3, -1});

        expectedResult.set(1, 1, {6, 3});
        expectedResult.set(1, 2, {0, 3});
        expectedResult.set(1, 3, {9, -3});

        expectedResult.set(2, 1, {2, 1});
        expectedResult.set(2, 2, {0, 1});
        expectedResult.set(2, 3, {3, -1});

        REQUIRE(expectedResult == result);
      }
    }
  }
}
SCENARIO("matrix multiplication with ZeroMatrix", "[sclMatrixMultiplication]") {
  GIVEN("A real matrix ") {
    sclMath::RealMatrix m(4, 4,
                          {1, 3, 5, 1, 7, 2, 6, 5, 1, 3, 5, 1, 7, 2, 6, 5});
    /* sclMath::RealMatrix result = m * sclMath::ZeroMatrix(4, 4); */
  }
  GIVEN("A complex matrix ") {}
}
