/*
 * numerical solution to problem 2.4.6 form the book Quantum Computing for Computer scientist
 * @code's author: Jorge Vulgarin
 *
 */
#include "../../../src/matrix.h"
#include "../../../src/matrixOperations.h"

#include <cmath>
#include <iostream>

int main(){
  sclMath::matrix m(2,2);

  m.set(0,0, sclMath::Scalar(3));
  m.set(0,1, sclMath::Scalar(5));
  m.set(1,0, sclMath::Scalar(2));
  m.set(1,1, sclMath::Scalar(3));
  

  std::cout<<m;

  // using mathematical definition for the norm
  std::cout<<std::sqrt(sclMath::innerProduct(m,m).real())<<'\n';
  // using built in method form sclMath
  std::cout<<m.norm()<<'\n';

}

