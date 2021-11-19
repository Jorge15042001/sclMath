#include "sclAngle.hpp"
#include "sclInnerProduct.hpp"
namespace sclMath {
// implementation

//  angle for sclMath::ComplexMatrix, sclMath::ComplexMatrix
//  angle for sclMath::RealMatrix, sclMath::RealMatrix
RealScalar angle(const RealMatrix &m1, const RealMatrix &m2) {
  const RealScalar m1Norm = m1.norm();
  const RealScalar m2Norm = m2.norm();

  const RealScalar innerP = innerProduct(m1, m2);

  return std::acos(innerP / (m1Norm * m2Norm));
}
RealScalar angle(const ComplexMatrix &m1, const ComplexMatrix &m2) {
  const RealScalar m1Norm = m1.norm();
  const RealScalar m2Norm = m2.norm();

  const ComplexScalar innerP = innerProduct(m1, m2);

  return std::acos(innerP.real() / (m1Norm * m2Norm));
}
} // namespace sclMath
