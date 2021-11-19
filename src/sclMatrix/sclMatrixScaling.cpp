#include "sclCopyMatrix.hpp"
#include "sclMatrixScaling.hpp"

// scale matric
// ###########################################################################################################
// overloading operator * for sclMath::ComplexScalar, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator*(const sclMath::ComplexScalar s,
                                 const sclMath::ComplexMatrix &m) {
  return sclMath::copyMatrix(m).scale(s);
}
// overloading operator * for sclMath::Scalar, sclMath::RealMatrix
sclMath::RealMatrix operator*(const sclMath::RealScalar s,
                              const sclMath::RealMatrix &m) {
  // TODO: test performance, without convertion real to complex,
  // overloading methhod to take ral number
  return sclMath::copyMatrix(m).scale(s);
}
// overloading operator * for sclMath::Scalar, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator*(const sclMath::RealScalar s,
                                 const sclMath::ComplexMatrix &m) {
  return sclMath::copyMatrix(m).scale(s);
}
// overloading operator * for sclMath::ComplexScalar, sclMath::RealMatrix
sclMath::ComplexMatrix operator*(const sclMath::ComplexScalar s,
                                 const sclMath::RealMatrix &m) {
  // convert the RealMatrix to a complex matrix, so it can be scaled
  return sclMath::copyMatrix_asComplex(m).scale(s);
}
