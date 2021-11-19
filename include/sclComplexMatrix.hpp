#pragma once

#include "sclMathErrors.hpp" //TODO: remove unsed header
#include <complex>
#include <iostream>    //TODO: remove
#include <type_traits> //TODO:remove
#include <vector>

namespace sclMath {
typedef std::complex<double> ComplexScalar;
typedef double RealScalar;

class ComplexMatrix {
private:
  std::vector<ComplexScalar> m_data;
  std::size_t rows;
  std::size_t cols;

public:
  ComplexMatrix(const std::int64_t rows, const std::int64_t cols);

  ComplexMatrix &transpose();
  ComplexMatrix &conjugate();
  ComplexMatrix &dagger();

  ComplexScalar trace() const;
  RealScalar normSquared() const;
  RealScalar norm() const;

  // TODO: is transpose methood missing
  bool isHermitian() const;

  ComplexMatrix &scale(const ComplexScalar s);

  std::size_t getRows() const;
  std::size_t getCols() const;

  void set(const std::size_t i, const std::size_t j, const ComplexScalar s);

  ComplexScalar get(const std::int64_t i, const std::int64_t j) const;
};
std::ostream &operator<<(std::ostream &os, const ComplexMatrix &m);

} // namespace sclMath
