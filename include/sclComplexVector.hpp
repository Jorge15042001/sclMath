#include "sclComplexMatrix.hpp"
namespace sclMath {
class ComplexVector {
  ComplexMatrix m_matrix; // a vector is just a (1xn) matrix
public:
  ComplexMatrix &conjugate();

  RealScalar normSquared() const;
  RealScalar norm() const;

  ComplexVector &scale(const ComplexScalar s);

  std::size_t getSize() const;

  void set(const std::size_t i, const std::size_t j, const ComplexScalar s);
  RealScalar get(const std::int64_t i, const std::int64_t j) const;
};
std::ostream &operator<<(std::ostream &os, const ComplexVector &m);
} // namespace sclMath
