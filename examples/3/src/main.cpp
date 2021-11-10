/*
 * mathematical solution to 2.4.8 form the book Quantum Computing to Computer Scientist
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
  v1.set(1,0, sclMath::Scalar(-1));
  v1.set(2,0, sclMath::Scalar(0));
  
  v2.set(0,0, sclMath::Scalar(2));
  v2.set(1,0, sclMath::Scalar(-2));
  v2.set(2,0, sclMath::Scalar(1));

  std::cout<<v1;
  std::cout<<v2;

  //approach 1 using mathematical defintion for the angle
  const sclMath::Scalar v1Norm = v1.norm();
  const sclMath::Scalar v2Norm = v2.norm();

  const sclMath::Scalar innerP = sclMath::innerProduct(v1,v2).real();//the imaginary component can be discarded

  const sclMath::Scalar angle = std::acos(innerP/(v1Norm*v2Norm));

  std::cout<<angle<<'\n';



  //method encapsulating the approach
  std::cout<<sclMath::angle(v1,v2)<<'\n';



}

