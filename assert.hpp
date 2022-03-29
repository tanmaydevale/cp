#pragma once

#include"string.hpp"

namespace cp {  
  /**
   * @brief Checks if the given expression holds. 
   * Throws a logical error (with the given optional message) if it does not.
   * 
   * @throws std::logic_error if expression does not hold
   */
  void check(bool expression, const cp::string& message = cp::EMPTY_STR);
}