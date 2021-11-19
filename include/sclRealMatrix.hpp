#pragma once
#include <complex>
#include <vector>

namespace sclaMath {
typedef std::complex<double> ComplexScalar;
typedef double RealScalar;
class RealMatrix {

private:
  std::vector<RealScalar> m_data;
  std::size_t rows;
  std::size_t cols;

public:
  RealMatrix(const std::int64_t rows, const std::int64_t cols);

  RealMatrix &transpose();

  RealScalar trace() const;
  RealScalar normSquared() const;
  RealScalar norm() const;

  // TODO: is transpose methood missing

  RealMatrix &scale(const RealScalar s);

  std::size_t getRows() const;
  std::size_t getCols() const;

  void set(const std::size_t i, const std::size_t j, const RealScalar s);

  RealScalar get(const std::int64_t i, const std::int64_t j) const;
};
std::ostream &operator<<(std::ostream &os, const RealMatrix &m);
} // namespace sclaMath
