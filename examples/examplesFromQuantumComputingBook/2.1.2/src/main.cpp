/*
 * prove the associativity property
 * brute force approch, not formal niether complete
 */
#include <cstdlib>
#include <iostream>
#include <matrix.h>
#include "matrix.h"
#include "matrixOperations.h"
#include <random>

const unsigned int randomSeed = 7483710;
const std::size_t repetitions = 1000;
sclMath::ComplexScalar randomComplex()
{
    static std::default_random_engine e;
    static std::uniform_real_distribution<> dis(0, 1); // rage 0 - 1
    return {dis(e),dis(e)};
}
int main(){

  std::srand(randomSeed); 

  sclMath::matrix m1 (4,1);
  sclMath::matrix m2 (4,1);
  sclMath::matrix m3 (4,1);

  for (std::size_t i = 0; i < repetitions; i++){
    //fill the matrices with radnom values
    m1.set(0,0,randomComplex());
    m1.set(1,0,randomComplex());
    m1.set(2,0,randomComplex());
    m1.set(3,0,randomComplex());

    m2.set(0,0,randomComplex());
    m2.set(1,0,randomComplex());
    m2.set(2,0,randomComplex());
    m2.set(3,0,randomComplex());

    m3.set(0,0,randomComplex());
    m3.set(1,0,randomComplex());
    m3.set(2,0,randomComplex());
    m3.set(3,0,randomComplex());

    sclMath::matrix result1 = (m1+m2)+m3;
    sclMath::matrix result2 = m1+(m2+m3);

    std::cout<<result1;
    std::cout<<result2;

  //   if (!(result1 == result2)){
  //     std::cout<<"FALSE";
  //     return 1;
  //   }
  //
  }
  // return 1;
  //
  
  //TODO:[creation] easier api to initialize matrix
  //TODO:[creation] better print formatting 
  //TODO:[creation] possible random matrice intitlzation  my be useefull
  //TODO:[comparison] overload != operator
}
