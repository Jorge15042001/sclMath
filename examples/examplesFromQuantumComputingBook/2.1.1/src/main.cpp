/*
 * problem adding vectors
 */
#include <iostream>
#include <matrix.h>
#include <matrixOperations.h>

int main(){

  sclMath::matrix m1 (4,1);
  sclMath::matrix m2 (4,1);

  // set each value

  m1.set(0,0,sclMath::ComplexScalar(5,13));
  m1.set(1,0,sclMath::ComplexScalar(6,2));
  m1.set(2,0,sclMath::ComplexScalar(0.53,-6));
  m1.set(3,0,sclMath::ComplexScalar(12));

  m2.set(0,0,sclMath::ComplexScalar(7,-8));
  m2.set(1,0,sclMath::ComplexScalar(0,-4));
  m2.set(2,0,sclMath::ComplexScalar(2));
  m2.set(3,0,sclMath::ComplexScalar(9.4,3));

  std::cout<<m1+m2;
  
  //TODO: easier api to initialize matrix
  //TODO: better print formatting 
}
