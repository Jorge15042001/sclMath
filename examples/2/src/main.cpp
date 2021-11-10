/*
 * mathematical solution to 2.4.7 form the book Quantum Computing to Computer Scientist
 * code's Author: Jorge Vulgarin
 */
#include "../../../src/matrix.h"
#include "../../../src/matrixOperations.h"

#include <cmath>
#include <iostream>

int main(){
  sclMath::matrix v1(3,1);
  sclMath::matrix v2(3,1);


  v1.set(0,0, sclMath::Scalar(3));
  v1.set(1,0, sclMath::Scalar(1));
  v1.set(2,0, sclMath::Scalar(2));
  
  v2.set(0,0, sclMath::Scalar(2));
  v2.set(1,0, sclMath::Scalar(2));
  v2.set(2,0, sclMath::Scalar(-1));

  std::cout<<v1;
  std::cout<<v2;

  //approach 1
  sclMath::matrix m1_m2 = v1-v2;
  sclMath::Scalar s = sclMath::innerProduct(m1_m2,m1_m2).real();// imaginary component must be zero up to the floating point precision
  std::cout<<std::sqrt(s)<<'\n';

  //method encapsulating the approach
  std::cout<<sclMath::distance(v1,v2);



}

