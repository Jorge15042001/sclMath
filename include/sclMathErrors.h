#pragma once
#include <iostream>
#include <stdexcept>
// #include <source_location>
#include <experimental/source_location>

namespace sclMathError {

typedef std::experimental::source_location source_location;

class sclMathRuntime_error : public std::runtime_error {
  source_location errorLocation;

public:
  sclMathRuntime_error(const std::string &err_data,
                       const source_location &err_location);
};

void ASSERT2(bool condition, const std::string &err_data,
             const source_location &location = source_location::current());
} // namespace sclMathError
