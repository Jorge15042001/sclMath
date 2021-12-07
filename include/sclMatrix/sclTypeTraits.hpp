#include <complex>

namespace sclMath {
typedef std::complex<double> ComplexScalar;
typedef double RealScalar;

template <typename T>
concept c_Scalar =
    std::is_same_v<T, RealScalar> || std::is_same_v<T, ComplexScalar>;

template <c_Scalar T_SCALAR> class Matrix;

typedef Matrix<RealScalar> RealMatrix;
typedef Matrix<ComplexScalar> ComplexMatrix;

template <typename T>
concept c_Matrix = std::is_same_v<T, Matrix<RealScalar>> ||
    std::is_same_v<T, Matrix<ComplexScalar>>;

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
