#include "sclComplexMatrix.hpp"
#include "sclRealMatrix.hpp"

namespace sclMath {

// innerProduct
// ###########################################################################################################
// inner Product for sclMath::RealMatrix, sclMath::RealMatrix
RealScalar innerProduct(const RealMatrix &m1, const RealMatrix &m2);
// inner Product for sclMath::ComplexMatrix, sclMath::ComplexMatrix
ComplexScalar innerProduct(const ComplexMatrix &m1, const ComplexMatrix &m2);
// inner Product for sclMath::ComplexMatrix, sclMath::RealMatrix
ComplexScalar innerProduct(const ComplexMatrix &m1, const RealMatrix &m2);
// inner Product for sclMath::RealMatrix, sclMath::ComplexMatrix
ComplexScalar innerProduct(const RealMatrix &m1, const ComplexMatrix &m2);
} // namespace sclMath
