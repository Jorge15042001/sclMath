#pragma once
#include <complex>

namespace sclMath {
typedef std::complex<double> ComplexScalar;
typedef double RealScalar;

// useful concepts for generic programming
template <typename T>
concept c_Scalar =
    std::is_same_v<T, RealScalar> || std::is_same_v<T, ComplexScalar>;

// Matrix types declaration
template <c_Scalar T_SCALAR> class Matrix;

typedef Matrix<RealScalar> RealMatrix;
typedef Matrix<ComplexScalar> ComplexMatrix;

class ZeroMatrix;
class IdentityMatrix;

// more useful concepts for generic programming

template <typename T>
concept c_RealMatrix = std::is_same_v<T, RealMatrix> ||
    std::is_same_v<T, ZeroMatrix> || std::is_same_v<T, IdentityMatrix>;

template <typename T>
concept c_ComplexMatrix = std::is_same_v<T, ComplexMatrix>;

template <typename T>
concept c_AnyMatrix = c_RealMatrix<T> || c_ComplexMatrix<T>;

template <typename T>
concept c_FullMatrix = std::is_same_v<T, Matrix<RealScalar>> ||
    std::is_same_v<T, Matrix<ComplexScalar>>;

// tempalte to get the scalar type of a matrix type
template <sclMath::c_AnyMatrix MT> struct MatrixScalarType {
  using type = ComplexScalar;
};
template <> struct MatrixScalarType<RealMatrix> { using type = RealScalar; };
template <> struct MatrixScalarType<ZeroMatrix> { using type = RealScalar; };

// useful for return type deduction
template <c_AnyMatrix MT1, c_AnyMatrix MT2> struct MatrixResultType {
  using type = ComplexMatrix;
};
template <> struct MatrixResultType<RealMatrix, RealMatrix> {
  using type = RealMatrix;
};
template <c_Scalar ST1, c_Scalar ST2> struct ScalarResultType {
  using type = ComplexScalar;
};
template <> struct ScalarResultType<RealScalar, RealScalar> {
  using type = RealScalar;
};

// any of the matrices is a ZeroMatrix
template <c_AnyMatrix M_any1, c_AnyMatrix M_any2>
constexpr inline bool anyIsZeroMatrix =
    std::is_same_v<M_any1, ZeroMatrix> || std::is_same_v<M_any2, ZeroMatrix>;

template <c_AnyMatrix M_type>
constexpr inline bool isZeroMatrix = std::is_same_v<M_type, ZeroMatrix>;

} // namespace sclMath
