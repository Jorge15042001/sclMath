#include "sclInnerProduct.hpp"
#include "sclCopyMatrix.hpp"
#include "sclMatrixMultiplication.hpp"
namespace sclMath {
// innerProduct
// inner Product for sclMath::RealMatrix, sclMath::RealMatrix
RealScalar innerProduct(const RealMatrix &m1, const RealMatrix &m2) {
  sclMathError::ASSERT2(
      m1.getRows() == m2.getRows(),
      "Inner Product requires both matrices to have the same shape");
  sclMathError::ASSERT2(
      m1.getCols() == m2.getCols(),
      "Inner Product requires both matrices to have the same shape");

  return (copyMatrix(m1).transpose() * m2).trace();
}
// inner Product for sclMath::ComplexMatrix, sclMath::ComplexMatrix
ComplexScalar innerProduct(const ComplexMatrix &m1, const ComplexMatrix &m2) {
  sclMathError::ASSERT2(
      m1.getRows() == m2.getRows(),
      "Inner Product requires both matrices to have the same shape");
  sclMathError::ASSERT2(
      m1.getCols() == m2.getCols(),
      "Inner Product requires both matrices to have the same shape");

  return (copyMatrix(m1).dagger() * m2).trace();
}
// inner Product for sclMath::ComplexMatrix, sclMath::RealMatrix
ComplexScalar innerProduct(const ComplexMatrix &m1, const RealMatrix &m2) {
  sclMathError::ASSERT2(
      m1.getRows() == m2.getRows(),
      "Inner Product requires both matrices to have the same shape");
  sclMathError::ASSERT2(
      m1.getCols() == m2.getCols(),
      "Inner Product requires both matrices to have the same shape");

  return (copyMatrix(m2).transpose() * m1).trace();
}
// inner Product for sclMath::RealMatrix, sclMath::ComplexMatrix
ComplexScalar innerProduct(const RealMatrix &m1, const ComplexMatrix &m2) {
  return innerProduct(m2, m1);
}
} // namespace sclMath
