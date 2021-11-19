#include "sclComplexMatrix.hpp"
#include "sclRealMatrix.hpp"
// scale matric
// ###########################################################################################################
// overloading operator * for sclMath::ComplexScalar, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator*(const sclMath::ComplexScalar s,
                                 const sclMath::ComplexMatrix &m);
// overloading operator * for sclMath::Scalar, sclMath::RealMatrix
sclMath::RealMatrix operator*(const sclMath::RealScalar s,
                              const sclMath::RealMatrix &m);
// overloading operator * for sclMath::Scalar, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator*(const sclMath::RealScalar s,
                                 const sclMath::ComplexMatrix &m);
// overloading operator * for sclMath::ComplexScalar, sclMath::RealMatrix
sclMath::ComplexMatrix operator*(const sclMath::ComplexScalar s,
                                 const sclMath::RealMatrix &m);
