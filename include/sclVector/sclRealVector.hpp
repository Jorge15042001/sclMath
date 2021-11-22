#include "sclMatrix/sclRealMatrix.hpp"
namespace sclMath {
class RealVector {
  RealMatrix m_matrix; // a vector is just a (1xn) matrix
public:
  RealScalar normSquared() const;
  RealScalar norm() const;

  RealVector &scale(const RealScalar s);

  std::size_t getSize() const;

  void set(const std::size_t i, const std::size_t j, const RealScalar s);
  RealScalar get(const std::int64_t i, const std::int64_t j) const;
};
std::ostream &operator<<(std::ostream &os, const RealVector &m);
} // namespace sclMath
