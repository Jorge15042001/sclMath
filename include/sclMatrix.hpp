#pragma once

#include "sclMathErrors.hpp"
#include <complex>
#include <iostream>
#include <memory>
#include <type_traits>
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
} // namespace sclMath
