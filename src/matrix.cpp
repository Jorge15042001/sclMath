#include "matrix.h"
#include "sclMathErrors.h"
#include <cmath>
#include <complex>
#include <assert.h>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <type_traits>
#include <vector>


namespace sclMath {
  matrix::matrix(const std::int64_t rows,  const std::int64_t cols)
      :rows(rows),cols(cols),m_data(rows*cols)
  {
    sclMathError::ASSERT2(rows > 0," number of rows can not be negative or zero");
    sclMathError::ASSERT2(cols > 0," number of columns can not be negative or zero");
  }

  std::size_t matrix::getRows()const{
    return this->rows;
  }

  std::size_t matrix::getCols()const{
    return this->cols;
  }

  matrix& matrix::conjugate(){
    for (auto & c:this->m_data){
      c=std::conj(c);
    }
    return *this;
  }

  matrix& matrix::transpose(){
    //AT[i,] = A[j,i]
    std::vector<ComplexScalar> new_m_data (this->m_data.size());

    auto f_finalPosition = [this](const std::size_t x ){return (x%this->cols)*this->rows+ x/this->cols;};

    for (std::size_t i = 0; i<this->m_data.size(); i ++){
      new_m_data[f_finalPosition(i)]=this->m_data[i];
    }
    this->m_data = new_m_data;

    std::swap(this->cols,this->rows);
    return *this;
  }

  matrix& matrix::dagger(){
    this->conjugate();
    this->transpose();

    return *this;
  }

  ComplexScalar matrix::trace()const {
    sclMathError::ASSERT2(this->rows == this->cols ,"trace() is not valid for non squared matrices");
    ComplexScalar result = 0;
    for (std::size_t i = 0 ; i<this->rows; i++){
      result += this->get(i,i);
    }
    return result;
  }

  Scalar matrix::normSquared()const{
    Scalar reuslt = 0 ;
    for (const ComplexScalar s : this->m_data) reuslt += (s*std::conj(s)).real();
    return reuslt;
  }
  Scalar matrix::norm()const{
    return std::sqrt(this->normSquared());
  }

  bool matrix::isHermitia()const{
    //if is not square matrix return false;
    if (this->rows!= this->cols)return false;
    // A[j,k]=conjugate(A[k,j]
    for(std::size_t i = 0; i < this->m_data.size(); i ++){
      //find position in matrix
      const std::size_t j = i/this->cols;
      const std::size_t k = i%this->cols;
      //check hermitian condition
      if (this->get(j,k) != std::conj(this->get(k,j))) return false;

    }
    return true;
  }

  matrix& matrix::scale(const ComplexScalar c){
    for (ComplexScalar& s : this->m_data) s*=c;
    return *this;
  }


  ComplexScalar matrix::get(const std::int64_t i,const std::int64_t j)const{
    sclMathError::ASSERT2(i>=0 && i<this->rows,"requested row index is out of range");
    sclMathError::ASSERT2(j>=0 && j<this->cols,"requested column index is out of range");

    const std::size_t index = this->cols * i + j;

    return this->m_data[index];

  }
  void matrix::set(const std::size_t i, const std::size_t j, const ComplexScalar s){
    sclMathError::ASSERT2(i>=0 && i<this->rows,"requested row index is out of range");
    sclMathError::ASSERT2(j>=0 && j<this->cols,"requested column index is out of range");

    this->m_data[this->cols*i+j] = s;
  }

  std::ostream& operator<< (std::ostream& os, const matrix& m){
    const std::size_t rows = m.getRows();
    const std::size_t cols = m.getCols();

    os<<"sclMath::Matrix["<<rows<<","<<cols<<"]\n{";
    
    for (std::size_t i = 0; i<rows;i++){
      os<<"{";
      for (std::size_t j = 0; j<cols;j++){
        os <<m.get(i,j)<<",";
      }
      os<<"}\n";
    }


    os<<"}\n";
    return os;
  }
}
