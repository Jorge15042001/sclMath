#pragma once
#include "sclMathErrors.hpp"
#include "sclTypeTraits.hpp"
#include <iostream>
namespace sclMath {

class ZeroMatrix {
  std::size_t cols;
  std::size_t rows;

public:
  ZeroMatrix(const std::int64_t r, const std::int64_t c) : rows(r), cols(c) {
    sclMathError::ASSERT2(r > 0, "invalid size");
    sclMathError::ASSERT2(c > 0, "invalid size");
  }
  RealScalar get(const std::int64_t r, const std::int64_t c) const {
    sclMathError::ASSERT2(r > 0, "rows count needs to be positive");
    sclMathError::ASSERT2(c > 0, "columns count needs to be positive");
    return 0;
  }
  ZeroMatrix &transpose() {
    std::swap(rows, cols);
    return *this;
  };
  ZeroMatrix &conjugate() { return *this; };
  ZeroMatrix &dagger() {
    transpose();
    /* conjugate();// does nothing */
    return *this;
  };

  RealScalar trace() const { return 0.0; };
  RealScalar normSquared() const { return 0.0; };
  RealScalar norm() const { return 0.0; };

  bool isSymmetric() const { return rows == cols; };
  bool isHermitian() const { return isSymmetric(); };

  ZeroMatrix &scale(const c_Scalar auto s) { return *this; };

  std::size_t getCols() const { return cols; }
  std::size_t getRows() const { return rows; }
};

} // namespace sclMath
