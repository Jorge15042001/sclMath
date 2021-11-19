/*
 * multiplication by scalar
 * 
 */
#include <cstdlib>
#include <iostream>
#include <matrix.h>
#include <matrix.h>
#include <matrixOperations.h>
#include <random>

const unsigned int randomSeed = 7483710;
const std::size_t repetitions = 1000;
int main(){

  sclMath::ComplexScalar c (8,-2);

  sclMath::matrix m1 (4,1);

  //NOTE: using default contructor
  m1.set(0,0,{16,2.3});
  m1.set(1,0,{0,-7});
  m1.set(2,0,{6});
  m1.set(3,0,{5,-4});

  
  const sclMath::matrix result = c*m1;//multiplication

  std::cout<<result;
  //TODO: format the printig of sclMath::matrix
}

