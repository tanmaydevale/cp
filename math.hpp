#pragma once

namespace cp {
  /**
   * @brief A very small value.
   *
   */
  const double EPSILON = 1e-6;

  /**
   * @brief The math constant PI.
   * 
   */
  const double PI = 3.14159255358979323846;

  /**
   * @brief Euler's number e.
   * 
   */
  const double E = 2.71828182845904523536;

  /**
   * @brief Returns a non-negative square-root of the given number.
   *
   * @pre `num >= 0`
   * @post `sqrt * sqrt = num`
   *
   * @throws std::logic_error if `num < 0`
   */
  double sqrt(double num);

  /**
   * @brief Returns lowest integer greater than or equal to the given number.
   *
   * @retval 42 ceiling(42)
   * @retval -4 ceiling(-4.2)
   * @retval 5 ceiling(4.2)
   * @retval 0 ceiling(0)
   */
  double ceiling(double);

  /**
   * @brief Returns largest integer less than or equal to the given number.
   * 
   * @retval 42 floor(42)
   * @retval -5 floor(-4.2)
   * @retval 4 floor(4.2)
   * @retval 0 floor(0)
   */
  double floor(double);

  /**
   * @brief Returns the absolute value of the given number.
   * 
   * @retval 42 abs(42)
   * @retval 42 abs(-42)
   * @retval 0 abs(0)
   * @retval 4.2 abs(4.2)
   * @retval 4.2 abs(-4.2)
   */
  double abs(double);
  int abs(int);


}
