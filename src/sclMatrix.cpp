#include "sclMatrix.hpp"
#include "sclMathErrors.hpp"
#include <cmath>
#include <cstdlib>
#include <memory>
#include <type_traits>
#include <vector>

// implementation

namespace sclMath {
RealMatrix::RealMatrix(const std::int64_t rows, const std::int64_t cols)
    : rows(rows), cols(cols), m_data(rows * cols) {
  sclMathError::ASSERT2(rows > 0,
                        " number of rows can not be negative or zero");
  sclMathError::ASSERT2(cols > 0,
                        " number of columns can not be negative or zero");
}

std::size_t RealMatrix::getRows() const { return this->rows; }

std::size_t RealMatrix::getCols() const { return this->cols; }

RealMatrix &RealMatrix::transpose() {
  // AT[i,] = A[j,i]
  std::vector<RealScalar> new_m_data(this->m_data.size());

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

RealScalar RealMatrix::trace() const {
  sclMathError::ASSERT2(this->rows == this->cols,
                        "trace() is not valid for non squared matrices");
  RealScalar result = 0;
  for (std::size_t i = 0; i < this->rows; i++) {
    result += this->get(i, i);
  }
  return result;
}

// TODO: test this function
RealScalar RealMatrix::normSquared() const {
  // TODO:replace with stl algorith?
  RealScalar reuslt = 0;
  for (const RealScalar s : this->m_data)
    // TODO: check if std::conj(float) may cause perfonmance issues
    reuslt += s * s;
  return reuslt;
}
RealScalar RealMatrix::norm() const { return std::sqrt(this->normSquared()); }

// TODO: no everload for sclMath::Scalar and sclMath::ComplexScalar
RealMatrix &RealMatrix::scale(const RealScalar c) {
  // TODO: range for loop, read as copy not as reference
  for (RealScalar &s : this->m_data)
    s *= c;
  return *this;
}

RealScalar RealMatrix::get(const std::int64_t i, const std::int64_t j) const {
  sclMathError::ASSERT2(i >= 0 && i < this->rows,
                        "requested row index is out of range");
  sclMathError::ASSERT2(j >= 0 && j < this->cols,
                        "requested column index is out of range");

  const std::size_t index = this->cols * i + j;

  return this->m_data[index];
}
void RealMatrix::set(const std::size_t i, const std::size_t j,
                     const RealScalar s) {
  sclMathError::ASSERT2(i >= 0 && i < this->rows,
                        "requested row index is out of range");
  sclMathError::ASSERT2(j >= 0 && j < this->cols,
                        "requested column index is out of range");

  this->m_data[this->cols * i + j] = s;
}

std::ostream &operator<<(std::ostream &os, const RealMatrix &m) {
  const std::size_t rows = m.getRows();
  const std::size_t cols = m.getCols();

  os << "sclMath::RealMatrix[" << rows << "," << cols << "]\n{";

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
namespace sclMath {
RealMatrix::RealMatrix(const std::int64_t rows, const std::int64_t cols)
    : rows(rows), cols(cols), m_data(rows * cols) {
  sclMathError::ASSERT2(rows > 0,
                        " number of rows can not be negative or zero");
  sclMathError::ASSERT2(cols > 0,
                        " number of columns can not be negative or zero");
}

std::size_t RealMatrix::getRows() const { return this->rows; }

std::size_t RealMatrix::getCols() const { return this->cols; }

RealMatrix &RealMatrix::conjugate() {
  for (auto &c : this->m_data) {
    c = std::conj(c);
  }
  return *this;
}

template <c_ScalarType T_SCALAR>
RealMatrix<T_SCALAR> &RealMatrix<T_SCALAR>::transpose() {
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

template <c_ScalarType T_SCALAR>
RealMatrix<T_SCALAR> &RealMatrix<T_SCALAR>::dagger() {
  this->conjugate();
  this->transpose();

  return *this;
}

template <c_ScalarType T_SCALAR> T_SCALAR RealMatrix<T_SCALAR>::trace() const {
  sclMathError::ASSERT2(this->rows == this->cols,
                        "trace() is not valid for non squared matrices");
  T_SCALAR result = 0;
  for (std::size_t i = 0; i < this->rows; i++) {
    result += this->get(i, i);
  }
  return result;
}

template <c_ScalarType T_SCALAR>
RealScalar RealMatrix<T_SCALAR>::normSquared() const {
  RealScalar reuslt = 0;
  for (const ComplexScalar s : this->m_data)
    // TODO: check if std::conj(float) may cause perfonmance issues
    reuslt += (s * std::conj(s)).real();
  return reuslt;
}
template <c_ScalarType T_SCALAR> RealScalar RealMatrix<T_SCALAR>::norm() const {
  return std::sqrt(this->normSquared());
}

template <c_ScalarType T_SCALAR>
bool RealMatrix<T_SCALAR>::isHermitian() const {
  // if is not square matrix return false;
  if (this->rows != this->cols)
    return false;
  // A[j,k]=conjugate(A[k,j]
  for (std::size_t i = 0; i < this->m_data.size(); i++) {
    // find position in matrix
    const std::size_t j = i / this->cols;
    const std::size_t k = i % this->cols;
    // check hermitian condition
    if (this->get(j, k) != std::conj(this->get(k, j)))
      return false;
  }
  return true;
}
// TODO: no everload for sclMath::Scalar and sclMath::ComplexScalar
template <c_ScalarType T_SCALAR>
RealMatrix<T_SCALAR> &RealMatrix<T_SCALAR>::scale(const T_SCALAR c) {
  for (T_SCALAR &s : this->m_data)
    s *= c;
  return *this;
}

template <c_ScalarType T_SCALAR>
T_SCALAR RealMatrix<T_SCALAR>::get(const std::int64_t i,
                                   const std::int64_t j) const {
  sclMathError::ASSERT2(i >= 0 && i < this->rows,
                        "requested row index is out of range");
  sclMathError::ASSERT2(j >= 0 && j < this->cols,
                        "requested column index is out of range");

  const std::size_t index = this->cols * i + j;

  return this->m_data[index];
}
template <c_ScalarType T_SCALAR>
void RealMatrix<T_SCALAR>::set(const std::size_t i, const std::size_t j,
                               const T_SCALAR s) {
  sclMathError::ASSERT2(i >= 0 && i < this->rows,
                        "requested row index is out of range");
  sclMathError::ASSERT2(j >= 0 && j < this->cols,
                        "requested column index is out of range");

  this->m_data[this->cols * i + j] = s;
}

template <c_ScalarType T_SCALAR>
std::ostream &operator<<(std::ostream &os, const RealMatrix<T_SCALAR> &m) {
  const std::size_t rows = m.getRows();
  const std::size_t cols = m.getCols();

  os << "sclMath::Matrix[" << rows << "," << cols << "]\n{";

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
