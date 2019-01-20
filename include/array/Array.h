#ifndef ARRAY_H
#define ARRAY_H

#include "error.h"

#include <cstddef>
#include <initializer_list>

namespace array {

// single dimension array
template <typename T, std::size_t N> class Array;

template <typename T, std::size_t N> class Array {
public:
  //------------------------- ALIAS -----------------------------
  using value_type = T;
  using size_type = std::size_t;
  using difference_type = std::ptrdiff_t;
  using reference = T &;
  using const_reference = const T &;
  using pointer = T *;
  using const_pointer = const T *;
  using iterator = T *;
  using const_iterator = const T *;
  //-------------------------------------------------------------

public:

  //--------------------- Constructors --------------------------
  Array() {
    static_assert((N > 0), "Invalid Array Size!");
    n = N;
  }

  Array(const Array &copy) : n(copy.n) {
    for (size_type i = 0; i < this->n; ++i) {
      this->_data[i] = copy._data[i];
    }
  }

  template <typename U> Array(const Array<U, N> &copy) : n(copy.n) {
    for (size_type i = 0; i < this->n; ++i) {
      this->_data[i] = copy._data[i];
    }
  }

  Array(std::initializer_list<T> list) {
    if (N != list.size()) {
      InvalidInitialListSizeException exception;
      throw exception;
    }
    auto it = list.begin(), ie = list.end();
    size_type i = 0;
    for (; it != ie; ++it, ++i) {
      _data[i] = *it;
    }
  }

  Array &operator=(const Array<T, N> &copy) {
    this->n = copy.n;
    if (&copy == this) {
      return (*this);
    }
    for (size_type i = 0; i < this->n; ++i) {
      this->_data[i] = copy._data[i];
    }
    return (*this);
  }

  template <typename U> Array &operator=(const Array<U, N> &copy) {
    this->n = copy.n;
    for (size_type i = 0; i < this->n; ++i) {
      this->_data[i] = copy._data[i];
    }
    return (*this);
  }

  Array &operator=(std::initializer_list<T> list) {
    if (N != list.size()) {
      InvalidInitialListSizeException exception;
      throw exception;
    }
    this->n = N;
    auto it = list.begin(), ie = list.end();
    size_type i = 0;
    for (; (it != ie) && (i < this->n); ++it, ++i) {
      _data[i] = *it;
    }
    return (*this);
  }
  //-------------------------------------------------------------

  //------------------------ Operators --------------------------
  bool operator!=(const Array<T, N> &array) {
    if (this->n != array.n)
      return true;
    for (size_type i = 0; i < N; ++i) {
      if (this->_data[i] != array._data[i])
        return true;
    }
    return false;
  }

  bool operator==(const Array<T, N> &array) { return !((*this) != array); }
  //-------------------------------------------------------------

  //--------------------- Basic Operations ----------------------
  reference at(size_type pos) {
    if (pos > n) {
      OutOfRangeException exception;
      throw exception;
    }
    return _data[pos];
  }

  const_reference at(size_type pos) const {
    if (pos > n) {
      OutOfRangeException exception;
      throw exception;
    }
    return _data[pos];
  }

  T &operator[](size_type pos) {
    if (pos > n) {
      OutOfRangeException exception;
      throw exception;
    }
    return _data[pos];
  }

  const T &operator[](size_type pos) const {
    if (pos > n) {
      OutOfRangeException exception;
      throw exception;
    }
    return _data[pos];
  }

  reference front() { return _data[0]; }

  reference back() { return _data[(this->n - 1)]; }

  constexpr size_type size() { return N; }

  iterator begin() { return _data; }
  iterator end() { return _data + n; }
  const_iterator begin() const { return _data; }
  const_iterator end() const { return _data + n; }

  void fill(const T &value) {
    for (size_type i = 0; i < this->n; ++i) {
      _data[i] = value;
    }
  }

  T* data() { return (T*)_data; }

  constexpr const T* data() const { return (T*)_data; }
  //-------------------------------------------------------------

private:
  T _data[N];
  // TODO: for static array, n maybe needless
  size_type n;
};

// TODO: multiple dimension array

} // end of namespace array

#endif // ARRAY_H
