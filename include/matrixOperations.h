#pragma once

#include "matrix.h"
#include <cstdint>
namespace sclMath {
matrix copyMatrix(const matrix &);
ComplexScalar innerProduct(const matrix &, const matrix &);
Scalar distance(const matrix &, const matrix &);
Scalar angle(const matrix &, const matrix &);

} // namespace sclMath
sclMath::matrix operator+(const sclMath::matrix &, const sclMath::matrix &);
sclMath::matrix operator-(const sclMath::matrix &, const sclMath::matrix &);
sclMath::matrix operator*(const sclMath::matrix &, const sclMath::matrix &);
sclMath::matrix operator*(const sclMath::ComplexScalar,
                          const sclMath::matrix &);
bool operator==(const sclMath::matrix &, const sclMath::matrix &);
