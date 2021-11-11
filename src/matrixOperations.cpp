#include "matrixOperations.h"
#include "matrix.h"
#include <assert.h>
#include <cmath>
#include <iostream>

namespace sclMath {
  matrix copyMatrix(const matrix &m){
    const std::size_t rows = m.getRows();
    const std::size_t cols = m.getCols();

    matrix mCopy (rows,cols);
    for (std::size_t i = 0; i<rows; i++){
      for (std::size_t j = 0; j<cols; j++){
        mCopy.set(i,j,m.get(i,j));
      }
    }
    return mCopy;
  }
  ComplexScalar innerProduct(const matrix& m1, const matrix& m2){
    //TODO: since matrix multiplication also validates this, for performance reasons may be a good idea to remove this check on non debug build
    if (m1.getCols() != m2.getCols()) throw "not valid operation ammong different shapped matrices";
    if (m1.getRows() != m2.getRows()) throw "not valid operation ammong different shapped matrices";

    const matrix m1Dagger = copyMatrix(m1).dagger();
    const matrix mult = m1Dagger*m2;
    return mult.trace();

  }
  Scalar distance (const matrix& m1, const matrix& m2){
    matrix diff = m1 - m2;
    return diff.norm();
  }

  Scalar angle (const matrix& m1, const matrix& m2){
    const Scalar m1Norm = m1.norm();
    const Scalar m2Norm = m2.norm();

    const ComplexScalar innerP = innerProduct(m1,m2);

    return std::acos(innerP.real()/(m1Norm*m2Norm));
  }
  matrix operator+ (const matrix& m1, const matrix& m2){
    if (m1.getCols() != m2.getCols()) throw "not valid operation ammong different shapped matrices";
    if (m1.getRows() != m2.getRows()) throw "not valid operation ammong different shapped matrices";

    const std::size_t rows =  m1.getRows();
    const std::size_t cols = m1.getCols();
    matrix result = matrix(rows,cols);
    
    for (std::size_t i = 0; i<rows; i++){
      for (std::size_t j = 0; j<cols; j++){
        const ComplexScalar sum = m1.get(i,j)+m2.get(i,j);
        result.set(i,j,sum);
      }
    }
    return result;
  }
  matrix operator- (const matrix& m1, const matrix& m2){
    if (m1.getCols() != m2.getCols()) throw "not valid operation ammong different shapped matrices";
    if (m1.getRows() != m2.getRows()) throw "not valid operation ammong different shapped matrices";

    const std::size_t rows =  m1.getRows();
    const std::size_t cols = m1.getCols();
    matrix result = matrix(rows,cols);
    
    for (std::size_t i = 0; i<rows; i++){
      for (std::size_t j = 0; j<cols; j++){
        const ComplexScalar subs = m1.get(i,j)-m2.get(i,j);
        result.set(i,j,subs);
      }
    }
    return result;
  }
  matrix operator* (const matrix& m1, const matrix& m2){
    if (m1.getCols()!= m2.getRows()) throw "operants cant be multiplied because of incompatible shapes";
    
    const std::size_t n = m1.getCols();
    const std::size_t rows = m1.getRows();
    const std::size_t cols = m2.getCols();

    matrix result (rows,cols);

    for (std::size_t i = 0; i<rows; i++){
      for (std::size_t j = 0; j<cols; j++){
        ComplexScalar sum = 0;
        for (std::size_t h = 0; h<n; h++){
          sum+=m1.get(i,h)*m2.get(h,j);
        }
        result.set(i,j,sum);
      }
    }

    return result;

  }
  matrix operator* (const ComplexScalar s, const matrix& m){
    matrix mCopy = copyMatrix(m);
    mCopy.scale(s);
    return mCopy;
  }

}
