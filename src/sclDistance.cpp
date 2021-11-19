#include "sclDistance.hpp"
#include "sclMatrixSubtraction.hpp"
namespace sclMath {
// distance
// ###########################################################################################################
// distance for sclmath::complexmatrix, sclmath::complexmatrix
// distance for sclmath::realmatrix, sclmath::realmatrix
RealScalar distance(const RealMatrix &m1, const RealMatrix &m2) {
  // TODO: check rigth type, is <T_SCALAR> required in this case
  return (m1 - m2).norm();
}
RealScalar distance(const ComplexMatrix &m1, const ComplexMatrix &m2) {
  // TODO: check rigth type, is <T_SCALAR> required in this case
  return (m1 - m2).norm();
}
// TODO: daise this make sense?
// distance for sclMath::ComplexMatrix, sclMath::RealMatrix
RealScalar distance(const ComplexMatrix &m1, const RealMatrix &m2) {
  return (m1 - m2).norm();
}
// distance for sclMath::RealMatrix, sclMath::ComplexMatrix
RealScalar distance(const RealMatrix &m1, const ComplexMatrix &m2) {
  return (m1 - m2).norm();
}
} // namespace sclMath
