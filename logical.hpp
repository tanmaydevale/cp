#pragma once

namespace cp {
  /**
   * @brief Returns `true` iff *both* the given expressions are `true`, `false` otherwise.
   * 
   */
  bool and_op(bool expr1, bool expr2);

  /**
   * @brief Returns `true` if *at least one* of the given expressions is `true`, `false` if both are `false`.
   * 
   */
  bool or_op(bool expr1, bool expr2);

  /**
   * @brief Returns `true` if the given expression is `false` and returns `false` if the given expression is `true`.
   * 
   */
  bool not_op(bool expr);
}
