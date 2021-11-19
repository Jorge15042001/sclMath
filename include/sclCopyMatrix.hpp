#include "sclComplexMatrix.hpp"
#include "sclRealMatrix.hpp"

namespace sclMath {
// copy matrix for sclMath::RealMatrix, sclMath::RealMatrix
RealMatrix copyMatrix(const RealMatrix &m);
// copy matrix for sclMath::ComplexMatrix, sclMath::ComplexMatrix
ComplexMatrix copyMatrix(const ComplexMatrix &m);
// TODO: copy real matrix as complex matrix, and viseversa
RealMatrix copyMatrix_asComplex(const ComplexMatrix &m);
} // namespace sclMath