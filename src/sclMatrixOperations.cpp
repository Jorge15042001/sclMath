#include "sclMatrixOperations.hpp"
namespace sclMath {
// implementation

// distance
// ###########################################################################################################
// distance for sclmath::complexmatrix, sclmath::complexmatrix
// distance for sclmath::realmatrix, sclmath::realmatrix
RealScalar distance(const RealMatrix &m1, const RealMatrix &m2) {
  // TODO: check rigth type, is <T_SCALAR> required in this case
  return (m1 - m2).norm();
}
RealScalar distance(const ComplexMatrix &m1, const ComplexMatrix &m2) {
  // TODO: check rigth type, is <T_SCALAR> required in this case
  return (m1 - m2).norm();
}
// TODO: daise this make sense?
// distance for sclMath::ComplexMatrix, sclMath::RealMatrix
RealScalar distance(const ComplexMatrix &m1, const RealMatrix &m2) {
  return (m1 - m2).norm();
}
// distance for sclMath::RealMatrix, sclMath::ComplexMatrix
RealScalar distance(const RealMatrix &m1, const ComplexMatrix &m2) {
  return (m1 - m2).norm();
}

//  angle for sclMath::ComplexMatrix, sclMath::ComplexMatrix
//  angle for sclMath::RealMatrix, sclMath::RealMatrix
RealScalar angle(const RealMatrix &m1, const RealMatrix &m2) {
  const RealScalar m1Norm = m1.norm();
  const RealScalar m2Norm = m2.norm();

  const RealScalar innerP = innerProduct(m1, m2);

  return std::acos(innerP / (m1Norm * m2Norm));
}
RealScalar angle(const ComplexMatrix &m1, const ComplexMatrix &m2) {
  const RealScalar m1Norm = m1.norm();
  const RealScalar m2Norm = m2.norm();

  const ComplexScalar innerP = innerProduct(m1, m2);

  return std::acos(innerP.real() / (m1Norm * m2Norm));
}
} // namespace sclMath

// matrix addition
// ###########################################################################################################
// overloading operator + for sclMath::ComplexMatrix, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator+(const sclMath::ComplexMatrix &m1,
                                 const sclMath::ComplexMatrix &m2) {
  sclMathError::ASSERT2(
      m1.getRows() == m2.getRows(),
      "Addition requires both matrices to have the same shape");
  sclMathError::ASSERT2(
      m1.getCols() == m2.getCols(),
      "Addition requires both matrices to have the same shape");

  const std::size_t rows = m1.getRows();
  const std::size_t cols = m1.getCols();
  sclMath::ComplexMatrix result(rows, cols);

  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      const sclMath::ComplexScalar sum = m1.get(i, j) + m2.get(i, j);
      result.set(i, j, sum);
    }
  }
  return result;
}
// overloading operator + for sclMath::RealMatrix, sclMath::RealMatrix
sclMath::RealMatrix operator+(const sclMath::RealMatrix &m1,
                              const sclMath::RealMatrix &m2) {
  sclMathError::ASSERT2(
      m1.getRows() == m2.getRows(),
      "Addition requires both matrices to have the same shape");
  sclMathError::ASSERT2(
      m1.getCols() == m2.getCols(),
      "Addition requires both matrices to have the same shape");

  const std::size_t rows = m1.getRows();
  const std::size_t cols = m1.getCols();
  sclMath::RealMatrix result(rows, cols);

  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      const sclMath::RealScalar sum = m1.get(i, j) + m2.get(i, j);
      result.set(i, j, sum);
    }
  }
  return result;
}
// overloading operator + for sclMath::RealMatrix, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator+(const sclMath::RealMatrix &m1,
                                 const sclMath::ComplexMatrix &m2) {
  sclMathError::ASSERT2(
      m1.getRows() == m2.getRows(),
      "Addition requires both matrices to have the same shape");
  sclMathError::ASSERT2(
      m1.getCols() == m2.getCols(),
      "Addition requires both matrices to have the same shape");

  const std::size_t rows = m1.getRows();
  const std::size_t cols = m1.getCols();
  sclMath::ComplexMatrix result(rows, cols);

  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      const sclMath::ComplexScalar sum = m1.get(i, j) + m2.get(i, j);
      result.set(i, j, sum);
    }
  }
  return result;
}
// overloading operator + for sclMath::ComplexMatrix, sclMath::RealMatrix
sclMath::ComplexMatrix operator+(const sclMath::ComplexMatrix &m1,
                                 const sclMath::RealMatrix &m2) {
  return m2 + m1;
}

// matrix Subtraction
// ###########################################################################################################
// overloading operator - for sclMath::ComplexMatrix, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator-(const sclMath::ComplexMatrix &m1,
                                 const sclMath::ComplexMatrix &m2) {
  sclMathError::ASSERT2(
      m1.getRows() == m2.getRows(),
      "Subtraction requires both matrices to have the same shape");
  sclMathError::ASSERT2(
      m1.getCols() == m2.getCols(),
      "Subtraction requires both matrices to have the same shape");

  const std::size_t rows = m1.getRows();
  const std::size_t cols = m1.getCols();
  sclMath::ComplexMatrix result(rows, cols);

  // TODO: get data as vector and useit like that
  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      const sclMath::ComplexScalar subs = m1.get(i, j) - m2.get(i, j);
      result.set(i, j, subs);
    }
  }
  return result;
}
// overloading operator - for sclMath::RealMatrix, sclMath::RealMatrix
sclMath::RealMatrix operator-(const sclMath::RealMatrix &m1,
                              const sclMath::RealMatrix &m2) {
  sclMathError::ASSERT2(
      m1.getRows() == m2.getRows(),
      "Subtraction requires both matrices to have the same shape");
  sclMathError::ASSERT2(
      m1.getCols() == m2.getCols(),
      "Subtraction requires both matrices to have the same shape");

  const std::size_t rows = m1.getRows();
  const std::size_t cols = m1.getCols();
  sclMath::RealMatrix result(rows, cols);

  // TODO: get data as vector and useit like that
  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      const sclMath::RealScalar subs = m1.get(i, j) - m2.get(i, j);
      result.set(i, j, subs);
    }
  }
  return result;
}
// overloading operator - for sclMath::RealMatrix, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator-(const sclMath::RealMatrix &m1,
                                 const sclMath::ComplexMatrix &m2) {
  sclMathError::ASSERT2(
      m1.getRows() == m2.getRows(),
      "Subtraction requires both matrices to have the same shape");
  sclMathError::ASSERT2(
      m1.getCols() == m2.getCols(),
      "Subtraction requires both matrices to have the same shape");

  const std::size_t rows = m1.getRows();
  const std::size_t cols = m1.getCols();
  sclMath::ComplexMatrix result(rows, cols);

  // TODO: get data as vector and useit like that
  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      const sclMath::ComplexScalar subs = m1.get(i, j) - m2.get(i, j);
      result.set(i, j, subs);
    }
  }
  return result;
}
// overloading operator - for sclMath::ComplexMatrix, sclMath::RealMatrix
sclMath::ComplexMatrix operator-(const sclMath::ComplexMatrix &m1,
                                 const sclMath::RealMatrix &m2) {
  return m2 - m1;
}

// matrix multiplication
// ###########################################################################################################
// overloading operator * for sclMath::ComplexMatrix, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator*(const sclMath::ComplexMatrix &m1,
                                 const sclMath::ComplexMatrix &m2) {
  sclMathError::ASSERT2(
      m1.getCols() == m2.getRows(),
      "sclMath::matrix multiplication is not defined, incompatible shapes");

  const std::size_t n = m1.getCols();
  const std::size_t rows = m1.getRows();
  const std::size_t cols = m2.getCols();

  sclMath::ComplexMatrix result(rows, cols);

  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      sclMath::ComplexScalar sum = 0;
      for (std::size_t h = 0; h < n; h++) {
        sum += m1.get(i, h) * m2.get(h, j);
      }
      result.set(i, j, sum);
    }
  }

  return result;
}
// overloading operator * for sclMath::RealMatrix, sclMath::RealMatrix
sclMath::RealMatrix operator*(const sclMath::RealMatrix &m1,
                              const sclMath::RealMatrix &m2) {
  sclMathError::ASSERT2(
      m1.getCols() == m2.getRows(),
      "sclMath::matrix multiplication is not defined, incompatible shapes");

  const std::size_t n = m1.getCols();
  const std::size_t rows = m1.getRows();
  const std::size_t cols = m2.getCols();

  sclMath::RealMatrix result(rows, cols);

  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      sclMath::RealScalar sum = 0;
      for (std::size_t h = 0; h < n; h++) {
        sum += m1.get(i, h) * m2.get(h, j);
      }
      result.set(i, j, sum);
    }
  }

  return result;
}
// overloading operator * for sclMath::RealMatrix, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator*(const sclMath::RealMatrix &m1,
                                 const sclMath::ComplexMatrix &m2) {
  sclMathError::ASSERT2(
      m1.getCols() == m2.getRows(),
      "sclMath::matrix multiplication is not defined, incompatible shapes");

  const std::size_t n = m1.getCols();
  const std::size_t rows = m1.getRows();
  const std::size_t cols = m2.getCols();

  sclMath::ComplexMatrix result(rows, cols);

  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      sclMath::ComplexScalar sum = 0;
      for (std::size_t h = 0; h < n; h++) {
        sum += m1.get(i, h) * m2.get(h, j);
      }
      result.set(i, j, sum);
    }
  }

  return result;
}
// overloading operator * for sclMath::ComplexMatrix, sclMath::RealMatrix
sclMath::ComplexMatrix operator*(const sclMath::ComplexMatrix &m1,
                                 const sclMath::RealMatrix &m2) {
  sclMathError::ASSERT2(
      m1.getCols() == m2.getRows(),
      "sclMath::matrix multiplication is not defined, incompatible shapes");

  const std::size_t n = m1.getCols();
  const std::size_t rows = m1.getRows();
  const std::size_t cols = m2.getCols();

  sclMath::ComplexMatrix result(rows, cols);

  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      sclMath::ComplexScalar sum = 0;
      for (std::size_t h = 0; h < n; h++) {
        sum += m1.get(i, h) * m2.get(h, j);
      }
      result.set(i, j, sum);
    }
  }

  return result;
}

// scale matric
// ###########################################################################################################
// overloading operator * for sclMath::ComplexScalar, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator*(const sclMath::ComplexScalar s,
                                 const sclMath::ComplexMatrix &m) {
  return sclMath::copyMatrix(m).scale(s);
}
// overloading operator * for sclMath::Scalar, sclMath::RealMatrix
sclMath::RealMatrix operator*(const sclMath::RealScalar s,
                              const sclMath::RealMatrix &m) {
  // TODO: test performance, without convertion real to complex,
  // overloading methhod to take ral number
  return sclMath::copyMatrix(m).scale(s);
}
// overloading operator * for sclMath::Scalar, sclMath::ComplexMatrix
sclMath::ComplexMatrix operator*(const sclMath::RealScalar s,
                                 const sclMath::ComplexMatrix &m) {
  return sclMath::copyMatrix(m).scale(s);
}
// overloading operator * for sclMath::ComplexScalar, sclMath::RealMatrix
sclMath::ComplexMatrix operator*(const sclMath::ComplexScalar s,
                                 const sclMath::RealMatrix &m) {
  // convert the RealMatrix to a complex matrix, so it can be scaled
  return sclMath::copyMatrix_asComplex(m).scale(s);
}
// == operator for matrices
// ###########################################################################################################
// TODO: almost equal neeeds to be tested with complex numbers
// TODO: write a test for this function
// overloading == for sclMath::ComplexMatrix
bool operator==(const sclMath::ComplexMatrix &m1,
                const sclMath::ComplexMatrix &m2) {
  if (m1.getRows() != m2.getRows())
    return false;
  if (m1.getCols() != m2.getCols())
    return false;

  const std::size_t rows = m1.getRows();
  const std::size_t cols = m1.getCols();

  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      if (!sclMathUtility::areaAlmostEqual(m1.get(i, j), m2.get(i, j)))
        return false;
    }
  }
  return true;
}
// TODO:DONE overloading == between sclMath::RealMatrix
bool operator==(const sclMath::RealMatrix &m1, const sclMath::RealMatrix &m2) {
  if (m1.getRows() != m2.getRows())
    return false;
  if (m1.getCols() != m2.getCols())
    return false;

  const std::size_t rows = m1.getRows();
  const std::size_t cols = m1.getCols();

  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      if (!sclMathUtility::areaAlmostEqual(m1.get(i, j), m2.get(i, j)))
        return false;
    }
  }
  return true;
}
// overloading operator == for sclMath::RealMatrix and sclMath::ComplexMatrix
bool operator==(const sclMath::RealMatrix &m1,
                const sclMath::ComplexMatrix &m2) {
  if (m1.getRows() != m2.getRows())
    return false;
  if (m1.getCols() != m2.getCols())
    return false;

  const std::size_t rows = m1.getRows();
  const std::size_t cols = m1.getCols();

  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      if (!sclMathUtility::areaAlmostEqual(m1.get(i, j), m2.get(i, j)))
        return false;
    }
  }
  return true;
}
// overloading operator == for sclMath::ComplexMatrix and sclMath::RealMatrix
bool operator==(const sclMath::ComplexMatrix &m1,
                const sclMath::RealMatrix &m2) {
  return m2 == m1;
}
