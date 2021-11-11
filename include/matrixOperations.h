#pragma once

#include "matrix.h"
#include <cstdint>
namespace sclMath {
  matrix copyMatrix(const matrix&);
  ComplexScalar innerProduct(const matrix&, const matrix&);
  Scalar distance (const matrix&, const matrix&);
  Scalar angle (const matrix&, const matrix&);

  matrix operator+ (const matrix&, const matrix&);
  matrix operator- (const matrix&, const matrix&);
  matrix operator* (const matrix&, const matrix&);
  matrix operator* (const ComplexScalar, const matrix&);
  std::int64_t operator== (const matrix&, const matrix&);
}
