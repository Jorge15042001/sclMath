/*
 * prove that (c1*c2) . V = c1 . v + c2 . V
 * brute force approach, not formal neither complete
 */
#include <cstdlib>
#include <iostream>
#include <matrix.h>
#include <matrix.h>
#include <matrixOperations.h>
#include <sclMathUtility.h>
#include <random>



const std::size_t repetitions = 1000;
sclMath::ComplexScalar randomComplex()//NOTE:[random] possible random implementation
{
    static std::default_random_engine e;
    static std::uniform_real_distribution<> dis(0, 1); // rage 0 - 1
    return {dis(e),dis(e)};
}
int main(){

  sclMathUtility::setUPL(1975);


  sclMath::matrix m1 (4,1);

  sclMath::ComplexScalar c1;
  sclMath::ComplexScalar c2;

  for (std::size_t i = 0; i < repetitions; i++){
    // chose 2 random constants
    c1 = randomComplex();
    c2 = randomComplex();
    //fill the matrices with random values
    m1.set(0,0,randomComplex());
    m1.set(1,0,randomComplex());
    m1.set(2,0,randomComplex());
    m1.set(3,0,randomComplex());



    sclMath::matrix result1 = (c1+c2)*m1;
    sclMath::matrix result2 = c1*m1 + c2*m1;

    if (!(result2==result1)){
      
      std::cout<<"iteration "<<i<<'\n';
      std::cout.precision(30);
      std::cout<<result1;
      std::cout<<result2;

      std::cout<<"counter example found, property does not holds";
      return 1;
    }

  }
  std::cout<<"no counter examples were found";
  //
  
  //TODO:[creation] easier api to initialize matrix
  //TODO:[creation] better print formatting 
  //TODO:[strategy,not_urgent] condition tester for "proving this sort of problems"
  //TODO:what the hell is going on with safe number comparison
}
