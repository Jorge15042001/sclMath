#pragma once

#include "sclMathErrors.hpp"
#include <cmath>
#include <complex>
#include <numeric>>
#include <type_traits>
#include <vector>

namespace sclMath {
typedef std::complex<double> ComplexScalar;
typedef double RealScalar;

inline RealScalar projectToReal(RealScalar s) { return s; }
inline RealScalar projectToReal(ComplexScalar s) { return s.real(); }
inline ComplexScalar projectToComplex(RealScalar s) { return s; }
inline ComplexScalar projectToComplex(ComplexScalar s) { return s; }

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

  // TODO: isSymmetric missing
  bool isSymmetric() const;
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

// useful for return type deduction
template <c_Matrix MT1, c_Matrix MT2> struct resultType {
  using type = ComplexMatrix;
};
template <> struct resultType<RealMatrix, RealMatrix> {
  using type = RealMatrix;
};
template <c_Scalar ST1, c_Scalar ST2> struct resultTypeSclar {
  using type = ComplexScalar;
};
template <> struct resultTypeSclar<RealScalar, RealScalar> {
  using type = RealScalar;
};

} // namespace sclMath

// implementation

namespace sclMath {
template <c_Scalar T_SCALAR>
Matrix<T_SCALAR>::Matrix(const std::int64_t rows, const std::int64_t cols)
    : rows(rows), cols(cols), m_data(rows * cols) {
  sclMathError::ASSERT2(rows > 0,
                        " number of rows can not be negative or zero");
  sclMathError::ASSERT2(cols > 0,
                        " number of columns can not be negative or zero");
}

template <c_Scalar T_SCALAR> std::size_t Matrix<T_SCALAR>::getRows() const {
  return this->rows;
}

template <c_Scalar T_SCALAR> std::size_t Matrix<T_SCALAR>::getCols() const {
  return this->cols;
}

// TODO: implement no copy transpose function
// https://www.geeksforgeeks.org/inplace-m-x-n-size-matrix-transpose/
template <c_Scalar T_SCALAR> Matrix<T_SCALAR> &Matrix<T_SCALAR>::transpose() {
  // AT[i,] = A[j,i]
  std::vector<T_SCALAR> new_m_data(this->m_data.size());

  auto f_finalPosition = [this](const std::size_t x) {
    return (x % this->cols) * this->rows + x / this->cols;
  };

  for (std::size_t i = 0; i < this->m_data.size(); i++) {
    new_m_data[f_finalPosition(i)] = this->m_data[i];
  }
  this->m_data = new_m_data;

  std::swap(this->cols, this->rows);
  return *this;
}
template <c_Scalar T_SCALAR> Matrix<T_SCALAR> &Matrix<T_SCALAR>::conjugate() {
  if constexpr (std::is_same_v<T_SCALAR, RealScalar>)
    return *this;

  if constexpr (std::is_same_v<T_SCALAR, ComplexScalar>)
    for (auto &c : this->m_data) {
      c = std::conj(c);
    }
  return *this;
}

template <c_Scalar T_SCALAR> T_SCALAR Matrix<T_SCALAR>::trace() const {
  sclMathError::ASSERT2(this->rows == this->cols,
                        "trace() is not valid for non squared matrices");
  T_SCALAR result = 0;
  for (std::size_t i = 0; i < this->rows; i++) {
    result += this->get(i, i);
  }
  return result;
}
template <c_Scalar T_SCALAR> Matrix<T_SCALAR> &Matrix<T_SCALAR>::dagger() {

  this->conjugate();
  this->transpose();

  return *this;
}

template <c_Scalar T_SCALAR> RealScalar Matrix<T_SCALAR>::normSquared() const {
  auto SquareAndSum = [](RealScalar s1, T_SCALAR s2) {
    if constexpr (std::is_same_v<T_SCALAR, RealScalar>)
      return s1 += s2 * s2;
    if constexpr (std::is_same_v<T_SCALAR, ComplexScalar>)
      // equivalent to s1 += (std:conj(s2)*s2).real()
      return s1 += s2.real() * s2.real() + s2.imag() * s2.imag();
  };

  return projectToReal(std::accumulate(this->m_data.begin(), this->m_data.end(),
                                       0.0, SquareAndSum));
}
template <c_Scalar T_SCALAR> RealScalar Matrix<T_SCALAR>::norm() const {
  return std::sqrt(this->normSquared());
}

template <c_Scalar T_SCALAR> bool Matrix<T_SCALAR>::isSymmetric() const {
  // if is not square matrix return false;
  if (this->rows != this->cols)
    return false;
  // A[j,k]=A[k,j]
  for (std::size_t i = 0; i < this->m_data.size(); i++) {
    // find position in matrix
    const std::size_t j = (i % this->rows) * this->rows + i / this->rows;
    // check symmetry condition
    if (this->m_data[i] != this->m_data[j])
      return false;
  }
  return true;
}
template <c_Scalar T_SCALAR> bool Matrix<T_SCALAR>::isHermitian() const {
  // if is not square matrix return false;
  if (this->rows != this->cols)
    return false;
  // A[j,k]=conjugate(A[k,j]
  for (std::size_t i = 0; i < this->m_data.size(); i++) {
    // find position in matrix
    const std::size_t j = (i % this->rows) * this->rows + i / this->rows;
    // check hermitian condition
    if (this->m_data[i] != std::conj(this->m_data[j]))
      return false;
  }
  return true;
}
template <c_Scalar T_SCALAR>
Matrix<T_SCALAR> &Matrix<T_SCALAR>::scale(const T_SCALAR c) {
  for (T_SCALAR &s : this->m_data)
    s *= c;
  return *this;
}

template <c_Scalar T_SCALAR>
T_SCALAR Matrix<T_SCALAR>::get(const std::int64_t i,
                               const std::int64_t j) const {
  sclMathError::ASSERT2(i >= 0 && i < this->rows,
                        "requested row index is out of range");
  sclMathError::ASSERT2(j >= 0 && j < this->cols,
                        "requested column index is out of range");

  const std::size_t index = this->cols * i + j;

  return this->m_data[index];
}
template <c_Scalar T_SCALAR>
void Matrix<T_SCALAR>::set(const std::size_t i, const std::size_t j,
                           const T_SCALAR s) {
  sclMathError::ASSERT2(i >= 0 && i < this->rows,
                        "requested row index is out of range");
  sclMathError::ASSERT2(j >= 0 && j < this->cols,
                        "requested column index is out of range");

  this->m_data[this->cols * i + j] = s;
}

template <c_Scalar T_SCALAR>
std::ostream &operator<<(std::ostream &os, const Matrix<T_SCALAR> &m) {
  const std::size_t rows = m.getRows();
  const std::size_t cols = m.getCols();

  if constexpr (std::is_same_v<RealScalar, T_SCALAR>) {
    os << "sclMath::RealMatrix[" << rows << "," << cols << "]\n{";
  }
  if constexpr (std::is_same_v<ComplexScalar, T_SCALAR>) {
    os << "sclMath::ComplexMatrix[" << rows << "," << cols << "]\n{";
  }

  for (std::size_t i = 0; i < rows; i++) {
    os << "{";
    for (std::size_t j = 0; j < cols; j++) {
      os << m.get(i, j) << ",";
    }
    os << "}\n";
  }

  os << "}\n";
  return os;
}
} // namespace sclMath
