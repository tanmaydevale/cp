#pragma once

#include <iostream>
#include <stdexcept>

#include "string.hpp"

namespace cp {

  /**
   * @brief Prints the given value to the console.
   *
   */
  void print(auto value) {
    std::cout << value;
  }

  /**
   * @brief Prints the given boolean to the console.
   *
   */
  void print(bool value);

  void println();

  /**
   * @brief Prints the given value to the console, followed by a new line.
   *
   */
  void println(auto value) {
    std::cout << value << std::endl;
  }

  /**
   * @brief Prints the given boolean to the console, followed by a new line.
   *
   */
  void println(bool value);

  /**
   * @brief Reads an integer from the command line interface.
   * 
   * @throws std::invalid_argument if the input is not in an integer format
   * 
   */
  int read_int();

  /**
   * @brief Reads a boolean value from the command line interface.
   * 
   * @throws std::invalid_argument if the input is not "true" or "false"
   * 
   */
  bool read_bool();

  /**
   * @brief Reads a character (except newline) from the command line interface.
   */
  char read_char();

  /**
   * @brief Reads a double from the command line interface.
   * 
   * @throws std::invalid_argument if the input is not in a double format
   * 
   */
  double read_double();

  /**
   * @brief Reads a line as a `cp::string` from the command line interface.
   * 
   */
  cp::string read_line();

}