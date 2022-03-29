#pragma once

#include "string.hpp"
#include "assert.hpp"
#include "logical.hpp"
#include <list>

namespace cp {
  template <class T>
  /**
   * @brief A list of things. 
   * Implemented as a doubly linked list of type `T`.
   *
   */
  class list {
  private:
    std::list<T> value;

  public:
    /**
     * @brief Creates an empty list.
     *
     */
    list() { value = std::list<T>(); }

    /**
     * @brief Creates a list by copying the elements of the given list.
     *
     */
    list(const list& other): value(other) {}

    /**
     * @brief Destroys this list.
     *
     */
    ~list() { value.clear(); }

    /**
     * @brief Returns the iterator to the beginning of this list.
     *
     */
    auto begin() {
      return value.begin();
    }

    /**
     * @brief Returns the iterator to the end of this list.
     *
     */
    auto end() { return value.end(); }

    /**
     * @brief Returns the number of elements in this list.
     *
     */
    auto size() const { return value.size(); }

    /**
     * @brief Deletes all the elements in this list.
     *
     */
    void clear() { value.clear(); }

    /**
     * @brief Inserts the given `value` at the given `pos`.
     *
     * @pre `0 <= pos <= size()`
     *
     * @throws std::logic_error if precondition not met
     */
    void insert_at(auto pos, const T& val) {
      cp::check(cp::and_op(0 <= pos, pos <= size()));
      
      auto it = value.begin();
      std::advance(it, pos);
      value.insert(it, val);
    }

    /**
     * @brief Removes the element from the given position.
     *
     * @pre `0 <= pos < size()`
     *
     * @returns A reference to the removed element
     *
     * @throws std::logic_error if precondition not met
     */
    T& remove_from(auto pos) {
      cp::check(cp::and_op(0 <= pos, pos < size()));

      auto it = value.begin();
      std::advance(it, pos);
      T& hold_to_return = *it;
      value.erase(it);
      return hold_to_return;
    }

    /**
     * @brief Returns a reference to the element at the given position.
     * 
     * @pre `0 <= pos < size()` 
     * @throws std::invalid_argument if precondition not met
     */
    T& operator[](auto pos) {
      cp::check(cp::and_op(0 <= pos, pos < size()));

      auto it = value.begin();
      std::advance(it, pos);
      return *it;
    }

    /**
     * @brief Reports if this list and the other list are equal.
     *
     * @returns `true` iff the two lists are equal, `false` otherwise
     *
     */
    bool operator==(const list& other) const {
      return (value==other.value);
    }

    /**
     * @brief Returns a string representation of this list.
     *
     */
    cp::string to_string() const {
      std::string st("[");
      auto it = value.begin();
      for (auto i = 0; i < size()-1; i++) {
        st = st + std::to_string(*it) + ", ";
        it++;
      } 
      st = st + std::to_string(*it) + "]";
      return cp::string(st);
    }
  };

  /**
   * @brief A list of integers.
   *
   */
  typedef cp::list<int> list_int;
  /**
   * @brief A list of doubles.
   * 
   */
  typedef cp::list<double> list_double;
  /**
   * @brief A list of booleans.
   * 
   */
  typedef cp::list<bool> list_bool;
  /**
   * @brief A list of characters.
   * 
   */
  typedef cp::list<char> list_char;
  /**
   * @brief A list of strings.
   * 
   */
  typedef cp::list<cp::string> list_string;
}