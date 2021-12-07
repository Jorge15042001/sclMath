#pragma once

#include "sclMathErrors.hpp"
#include <algorithm>>
#include <cmath>
#include <complex>
#include <numeric>>
#include <type_traits>
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
  Matrix(const std::int64_t rows, const std::int64_t cols,
         std::vector<T_SCALAR> &&data);

  Matrix<T_SCALAR> &transpose();
  Matrix<T_SCALAR> &conjugate();
  Matrix<T_SCALAR> &dagger();

  T_SCALAR trace() const;
  RealScalar normSquared() const;
  RealScalar norm() const;

  bool isSymmetric() const;
  bool isHermitian() const;

  Matrix<T_SCALAR> &scale(const T_SCALAR s);

  std::size_t getRows() const;
  std::size_t getCols() const;

  void set(const std::size_t i, const std::size_t j, const T_SCALAR s);
  const std::vector<T_SCALAR> &getDataVector() const;

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
// tempalte to get the scalar type of a matrix type
template <sclMath::c_Matrix MT> struct ScalarTypeOfMatrix {
  using type = sclMath::ComplexScalar;
};
template <> struct ScalarTypeOfMatrix<RealMatrix> {
  using type = sclMath::RealScalar;
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
template <c_Scalar T_SCALAR>
Matrix<T_SCALAR>::Matrix(const std::int64_t rows, const std::int64_t cols,
                         std::vector<T_SCALAR> &&data)
    : rows(rows), cols(cols), m_data(std::move(data)) {
  sclMathError::ASSERT2(rows > 0,
                        " number of rows can not be negative or zero");
  sclMathError::ASSERT2(cols > 0,
                        " number of columns can not be negative or zero");
  sclMathError::ASSERT2(
      rows * cols == this->m_data.size(),
      " number of elementes is array musy be equal (rows*columns)");
}

template <c_Scalar T_SCALAR> std::size_t Matrix<T_SCALAR>::getRows() const {
  return this->rows;
}

template <c_Scalar T_SCALAR> std::size_t Matrix<T_SCALAR>::getCols() const {
  return this->cols;
}

template <c_Scalar T_SCALAR> Matrix<T_SCALAR> &Matrix<T_SCALAR>::transpose() {
  const std::size_t size = this->m_data.size() - 1;
  // at the begining no elements have been swap
  std::vector<bool> swapLookUP(size + 1, false);
  // the last and first element are never moved
  swapLookUP[0] = swapLookUP[size] = true;

  // i walks trough each position of the loop that must be swap
  std::size_t i = 1; // iterator

  while (i < size) { // if i greater size all elementes hav been swap

    const std::size_t cycleBegin = i; // holds start of cycle
    T_SCALAR prevValue = this->m_data[i];

    do {
      // new position for the prev element in the lopp
      i = (i * this->rows) % size;
      std::swap(this->m_data[i], prevValue);
      // set the position as swap
      swapLookUP[i] = true;
    } while (i != cycleBegin); // while the end of the loop hasnt been reach

    // Get Next Move
    for (i = 1; i < size && swapLookUP[i]; i++)
      ; // if i is set to size that means all elements have been swap
  }
  std::swap(this->rows, this->cols);
  return *this;
}
template <c_Scalar T_SCALAR> Matrix<T_SCALAR> &Matrix<T_SCALAR>::conjugate() {
  if constexpr (std::is_same_v<T_SCALAR, RealScalar>)
    return *this;

  if constexpr (std::is_same_v<T_SCALAR, ComplexScalar>)
    std::transform(this->m_data.begin(), this->m_data.end(),
                   this->m_data.begin(),
                   [](ComplexScalar s) { return std::conj(s); });
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

  return std::real(std::accumulate(this->m_data.begin(), this->m_data.end(),
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
  if constexpr (std::is_same_v<T_SCALAR,
                               RealScalar>) // every symmetric real matrix is
                                            // also hermitian
    return this->isSymmetric();
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
const std::vector<T_SCALAR> &Matrix<T_SCALAR>::getDataVector() const {
  return this->m_data;
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
