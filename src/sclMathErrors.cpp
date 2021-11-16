#include "sclMathErrors.hpp"
namespace sclMathError {

sclMathRuntime_error::sclMathRuntime_error(const std::string &err_data,
                                           const source_location &err_location)
    : std::runtime_error(err_data), errorLocation(err_location) {}

void ASSERT2(bool condition, const std::string &err_data,
             const source_location &location) {
#ifdef SCLMATH_DEBUG_BUILD
  if (!condition)
    throw sclMathRuntime_error(err_data, location);
#endif
#ifdef SCLMATH_RELEASE_BUILD
#endif
}
} // namespace sclMathError
