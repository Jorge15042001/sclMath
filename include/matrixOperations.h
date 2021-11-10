#pragma once

#include "matrix.h"
namespace sclMath {
  matrix copyMatrix(const matrix&);
  ComplexScalar innerProduct(const matrix&, const matrix&);
  //TODO: create  realScalar type and complexScalar
  Scalar distance (const matrix&, const matrix&);
  Scalar angle (const matrix&, const matrix&);

  matrix operator+ (const matrix&, const matrix&);
  matrix operator- (const matrix&, const matrix&);
  matrix operator* (const matrix&, const matrix&);
  matrix operator* (const ComplexScalar, const matrix&);
}
