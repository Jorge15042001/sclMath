#include "sclComplexMatrix.hpp"
#include "sclRealMatrix.hpp"
namespace sclMath {
// distance
// ###########################################################################################################
// distance for sclmath::complexmatrix, sclmath::complexmatrix
RealScalar distance(const ComplexMatrix &m1, const ComplexMatrix &m2);
// distance for sclmath::realmatrix, sclmath::realmatrix
RealScalar distance(const RealMatrix &m1, const RealMatrix &m2);
// distance for sclMath::ComplexMatrix, sclMath::RealMatrixu
RealScalar distance(const ComplexMatrix &m1, const RealMatrix &m2);
// distance for sclMath::RealMatrix, sclMath::ComplexMatrix
RealScalar distance(const RealMatrix &m1, const ComplexMatrix &m2);
} // namespace sclMath
