#pragma once

#include <string>

namespace cp {
  /**
   * @brief Represents a string of characters with `std::string` as the underlying representation.
   * 
   */
  class string {
  private:
    std::string value;

  public:
    /**
     * @brief Construct an empty string.
     *
     */
    string();

    /**
     * @brief Construct a new string object from a character array.
     * 
     */
    string(const char* const other);

    /**
     * @brief Construct a new string object from the given `std::string`.
     * 
     */
    string(const std::string& other);

    /**
     * @brief Destroy the string object.
     * 
     */
    ~string();

    /**
     * @brief Report the position of the *leftmost* occurrance of the given character in the string if it exists, -1 otherwise.
     * 
     * @return `pos` such that `this[pos]==c` if `c` is in `this`; -1 otherwise
     * 
     * @retval 0 if `this` is "india" and `c` is 'i'
     * @retval 1 if `this` is "india" and `c` is 'n'
     * @retval 2 if `this` is "india" and `c` is 'd'
     * @retval 4 if `this` is "india" and `c` is 'a'
     * @retval -1 if `this` is "india" and `c` is 'x'
     */
    int index_of(char c) const;

    /**
     * @brief Make this string an empty string.
     * 
     */
    void clear();

    /**
     * @brief Report the number of characters in `this` string.
     * 
     */
    int length() const;

    /**
     * @brief Reports the integer representation of `this` string.
     * 
     * @pre `this` must be in a numeric format and in the valid integer range
     * 
     * @throws std::invalid_argument if the string is not in a numeric format
     * @throws std::out_of_range if the string's numeric equivalent is not in the `int` range
     * 
     * @retval 1 if `this` is "1"
     * @retval -5 if `this` is "-5"
     */
    int to_int() const;


    /**
     * @brief Reports the double representation of `this` string.
     * 
     * @pre `this` must be in a proper format and in the valid range
     * 
     * @throws std::invalid_argument if the string is not in a numeric format
     * @throws std::out_of_range if the string's numeric equivalent is not in the `double` range
     * 
     * @retval 3.14 if `this` is "3.14"
     * @retval -2.5e4 if `this` is "-2.5e4"
     */
    double to_double() const;

    /**
     * @brief Reports the boolean equivalent of `this` string.
     * 
     * @throws std::invalid_argument if the string is neither "true" or "false"
     * 
     * @retval true if `this` is "true"
     * @retval false if `this` is "false"
     */
    bool to_bool() const;

    /**
     * @brief Implicit converstion to `std::string`.
     * 
     * @return the underlying representation
     */
    operator std::string() const;

    /**
     * @brief Replace the contents of `this` with `str`.
     *
     * @param str string to be used as source to initialize the string with
     * @return `*this`
     */
    cp::string& operator=(const cp::string str);
    cp::string& operator=(const std::string str);
    cp::string& operator=(const char* str);

    /**
     * @brief Returns a reference to the character at specified location `pos` with bounds check.
     * 
     * @pre `0 <= pos < length(this)`
     * 
     * @return Reference to the requested character
     * 
     * @throws std::invalid_argument if precondition not met
     */
    char& operator[](int pos);

    /**
     * @brief Reports if `this` and `other` are equal.
     * 
     * @return true iff `this` and `other` are equal
     */
    bool operator==(const string& other) const;

    /**
     * @brief Produces the concatenation of `this` with `other`.
     * 
     * @return the concatenated string
     * 
     * @retval "india" if `this` is "in" and `other` is "dia"
     */
    cp::string operator+(const string& other) const;

    /**
     * @brief Returns the iterator at the start of `this` string.
     * 
     */
    std::string::iterator begin();
    
    /**
     * @brief Returns the iterator at the end of `this` string.
     * 
     */
    std::string::iterator end();

    /**
     * @brief Performs stream output for `cp::string`.
     * 
     * @throws std::ios_base::failure if an exception is thrown during output.
     * 
     */
    friend std::ostream& operator<<(std::ostream &os, const cp::string &s) {
      os << s.value;
      return os;
    }

    /**
     * @brief Performs stream input for `cp::string`.
     * 
     * @throws std::ios_base::failure if no characters are extracted from is (e.g the stream is at end of file, or consists of whitespace only), or if an exception is thrown during input.
     * 
     */
    friend std::istream& operator>>(std::istream &is, cp::string &s) {
      std::string t;
      is >> t;
      s.value = t;
      return is;
    }
  };

  /**
   * @brief Converts the given integer to its string representation.
   * 
   */
  cp::string to_string(int val);

  /**
   * @brief Converts the given double to its string representation.
   * 
   */
  cp::string to_string(double val);

  /**
   * @brief Converts the given boolean to its string representation.
   * 
   */
  cp::string to_string(bool val);

  /**
   * @brief Converts the given character to its string representation.
   * 
   */
  cp::string to_string(char val);

  /**
   * @brief Empty string.
   * 
   */
  const cp::string EMPTY_STR = string();
  /**
   * @brief New line.
   * 
   */
  const cp::string NEWLINE = string("\n");

}
