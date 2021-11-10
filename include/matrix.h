#pragma once

#include <complex>
#include <type_traits>
#include <vector>

namespace sclMath {
  typedef std::complex<double> ComplexScalar;
  typedef double Scalar;

  class matrix{
    private:

      std::vector<ComplexScalar> m_data;
      std::size_t rows ;
      std::size_t cols ;

      ComplexScalar& getReferece (const std::size_t i,const std::size_t j);

    public:
      matrix(const  std::int64_t rows,  const std::int64_t cols);

      matrix& transpose() ;
      matrix& conjugate() ;
      matrix& dagger() ;

      ComplexScalar trace()const;
      Scalar normSquared()const;
      Scalar norm()const;

      bool isHermitia()const;

      matrix& scale(const ComplexScalar s);


      std::size_t getRows() const;
      std::size_t getCols() const;

      void set(const std::size_t i, const std::size_t j, const ComplexScalar s);

      ComplexScalar get(const std::int64_t i,const std::int64_t j)const;

  };
  std::ostream& operator<< (std::ostream& os, const matrix& m);
}
