#include "sclMathUtility.h"
#include <cmath>

namespace  sclMathUtility{
  //taken from https://en.cppreference.com/w/cpp/types/numeric_limits/epsilon
  //save comparison for flotating types
  template<class T>
  typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
      floating_almost_equal(T x, T y, int ulp=6)
  {
      // the machine epsilon has to be scaled to the magnitude of the values used
      // and multiplied by the desired precision in ULPs (units in the last place)
      return std::fabs(x-y) <= std::numeric_limits<T>::epsilon() * std::fabs(x+y) * ulp
          // unless the result is subnormal
          || std::fabs(x-y) < std::numeric_limits<T>::min();
  }
  //save comparison between two sclMath::complexScalar 
  bool areaAlmostEqual(sclMath::ComplexScalar a, sclMath::ComplexScalar b){
    return floating_almost_equal(a.real(),b.real()) && floating_almost_equal(a.imag(),b.imag());
  }
  //save comparison between two sclMath::Scalar  aka(real number)
  bool areaAlmostEqual(sclMath::Scalar a, sclMath::Scalar b){
    return floating_almost_equal(a,b) ;
  }

 
}