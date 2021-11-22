#pragma once

#include <complex>
#include <type_traits> //TODO:remove
#include <vector>

namespace sclMath {
typedef std::complex<double> ComplexScalar;
typedef double RealScalar;

template <typename T>
concept c_Scalar =
    std::is_same_v<T, RealScalar> || std::is_same_v<T, ComplexScalar>;

template <c_Scalar T_SCALAR> class Matrix {
private:
  std::vector<T_SCALAR> m_data;
  std::size_t rows;
  std::size_t cols;

public:
  Matrix(const std::int64_t rows, const std::int64_t cols);

  Matrix<T_SCALAR> &transpose();
  Matrix<T_SCALAR> &conjugate();
  Matrix<T_SCALAR> &dagger();

  T_SCALAR trace() const;
  RealScalar normSquared() const;
  RealScalar norm() const;

  // TODO: is transpose methood missing
  bool isHermitian() const;

  Matrix<T_SCALAR> &scale(const T_SCALAR s);

  std::size_t getRows() const;
  std::size_t getCols() const;

  void set(const std::size_t i, const std::size_t j, const T_SCALAR s);

  T_SCALAR get(const std::int64_t i, const std::int64_t j) const;
};

template <typename T>
concept c_Matrix = std::is_same_v<T, Matrix<RealScalar>> ||
    std::is_same_v<T, Matrix<ComplexScalar>>;

std::ostream &operator<<(std::ostream &os, const c_Matrix auto &m);

typedef Matrix<RealScalar> RealMatrix;
typedef Matrix<ComplexScalar> ComplexMatrix;

} // namespace sclMath
