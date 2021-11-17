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

template <typename T>
concept c_ScalarType =
    std::is_same_v<T, RealScalar> || std::is_same_v<T, ComplexScalar>;

template <c_ScalarType T_SCALAR> class matrix {
private:
  std::vector<T_SCALAR> m_data;
  std::size_t rows;
  std::size_t cols;

public:
  matrix(const std::int64_t rows, const std::int64_t cols);

  matrix &transpose();
  matrix &conjugate();
  matrix &dagger();

  ComplexScalar trace() const;
  Scalar normSquared() const;
  Scalar norm() const;

  bool isHermitian() const;

  matrix &scale(const ComplexScalar s);

  std::size_t getRows() const;
  std::size_t getCols() const;

  void set(const std::size_t i, const std::size_t j, const ComplexScalar s);

  ComplexScalar get(const std::int64_t i, const std::int64_t j) const;
};
std::ostream &operator<<(std::ostream &os, const matrix &m);
} // namespace sclMath
