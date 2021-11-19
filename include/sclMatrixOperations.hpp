#pragma once

#include "sclAngle.hpp"        //TODO: remove
#include "sclCopyMatrix.hpp"   //TODO: remove
#include "sclDistance.hpp"     //TODO remove
#include "sclInnerProduct.hpp" //TODO: remove
#include "sclMathErrors.hpp"
#include "sclMathUtility.hpp"
#include "sclMatrix.hpp"
#include "sclMatrixAddition.hpp"    //TODO: remove
#include "sclMatrixSubtraction.hpp" //TODO: remove
#include <cmath>
#include <cstdint>
#include <iostream>

// == operator for matrices
// ###########################################################################################################
// TODO: almost equal neeeds to be tested with complex numbers
// TODO: write a test for this function
// overloading operator == for ComplexMatrix
bool operator==(const sclMath::ComplexMatrix &m1,
                const sclMath::ComplexMatrix &m2);
// overloading operator == for realmatrices
bool operator==(const sclMath::RealMatrix &m1, const sclMath::RealMatrix &m2);
// overloading operator == for sclMath::RealMatrix and sclMath::ComplexMatrix
bool operator==(const sclMath::RealMatrix &m1,
                const sclMath::ComplexMatrix &m2);
// overloading operator == for sclMath::ComplexMatrix and sclMath::RealMatrix
bool operator==(const sclMath::ComplexMatrix &m1,
                const sclMath::RealMatrix &m2);
