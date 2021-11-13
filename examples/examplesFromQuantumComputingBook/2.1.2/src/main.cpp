/*
 * prove the associativity property
 * brute force approach, not formal neither complete
 */
#include <cstdlib>
#include <iostream>
#include <matrix.h>
#include <matrix.h>
#include <matrixOperations.h>
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
    //fill the matrices with random values
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



    if (!(result1 == result2)){
      std::cout<<result1;
      std::cout<<result2;

      
      std::cout<<"counter example found, associativity property is not real";
      return 1;
    }

  }
  std::cout<<"no counter examples were found";
  //
  
  //TODO:[creation] easier api to initialize matrix
  //TODO:[creation] better print formatting 
  //TODO:[creation] possible random matrices initialization  my be useful
  //TODO:[comparison] overload != operator
}
