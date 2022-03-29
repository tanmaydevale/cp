#pragma once
#include "string.hpp"
#include <fstream>
#include <iostream>

namespace cp {

/**
 * @brief Abstract class interface for file
 *
 * Implements functions common to the input_file and output_file classes.
 *
 */
class file {
protected:
  /**
   * @brief The file handler std::fstream object
   *
   * Used in input or output mode by derived classes.
   */
  std::fstream filehandler;

  /**
   * @brief Stores the name of the file opened
   *
   */
  cp::string filename;

public:
  /**
   * @brief Construct a new file object (Do not call directly)
   *
   * Only to be used by the constructors of input_file and output_file.
   *
   * @param name: Name or path of the file
   */
  file(cp::string name);

  /**
   * @brief Destroys the file object
   *
   * Called by destructors of input_file and output_file.
   */
  virtual ~file() = 0;

  /**
   * @brief Checks if the file handler has an open file
   *
   * @return true: The file handler exists and can be used
   * @return false: The file handler has been closed and needs to be re-opened
   * if needed
   */
  bool is_open();

  /**
   * @brief Checks if the end of file has been reached (eofbit set)
   *
   * @return true: eofbit has been set
   * @return false: eofbit has not been set
   */
  bool eof();

  /**
   * @brief Closes the file from the file handler
   *
   */
  void close();

  /**
   * @brief Returns the name of the file attached to the file handler as a
   * cp::string
   *
   * @return cp::string: The name of the file
   */
  cp::string name();
};

/**
 * @brief Class Interface for an input file
 *
 * Opens a file in read-only mode and reads variables from it.
 */
class input_file : public file {

public:
  /**
   * @brief Construct a new input_file object
   *
   * Opens the file handler in read-only mode.
   *
   * @param file_name: Name or path of the file
   */
  input_file(cp::string file_name);

  /**
   * @brief Destroy the input file object
   *
   * Closes the file
   */
  ~input_file();

  /**
   * @brief Function template to read variables from an open file
   *
   * @tparam readable: A variable that can be read from the file
   * @return readable: Returns the variable to the wrapper function
   */
  template <typename readable> readable read() {
    readable variable;
    filehandler >> variable;
    if (filehandler.fail()) {
      throw "fileio_format_error";
    }
    return variable;
  }

  /**
   * @brief Reads an integer from a file using the `read()` function template
   *
   * @return An integer read from an open file
   */
  int read_int();

  /**
   * @brief Reads a boolean from a file using the `read()` function template
   *
   * @return A bool read from an open file
   */
  bool read_bool();

  /**
   * @brief Reads a double from a file using the `read()` function template
   *
   * @return A double read from an open file
   */
  double read_double();

  /**
   * @brief Reads a character from a file using the `read()` function template
   *
   * @return A character read from an open file
   */
  char read_char();
};

/**
 * @brief Class Interface for an output file
 *
 * Opens a file in write-only mode and prints variables to it.
 */
class output_file : public file {

public:
  /**
   * @brief Construct a new output_file object
   *
   * Opens the file handler in write-only mode.
   *
   * @param file_name: Name or path of the file
   */
  output_file(cp::string file_name);
  ~output_file();

  /**
   * @brief Function template to print a variable to an open file
   *
   * @tparam printable: A variable that can be printed to a file
   * @param variable: The variable be written to the file
   */
  template <typename printable> void print(printable variable) {
    filehandler << variable;
  }

  /**
   * @brief Prints a newline to an open file
   *
   */
  void println(void) { filehandler << std::endl; }

  /**
   * @brief Function template to print a variable to an open file and a newline
   *
   * @tparam printable: A variable that can be printed to a file
   * @param variable: The variable be written to the file
   */
  template <typename printable> void println(printable variable) {
    filehandler << variable << std::endl;
  }
};

} // namespace cp
