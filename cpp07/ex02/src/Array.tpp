#ifndef ARRAY_TPP
# define ARRAY_TPP

#include <cstddef>
#include "Array.hpp"

template <typename T> Array<T>::Array() : _n(0), _array(NULL) {}

template <typename T>
Array<T>::Array(unsigned int n) : _n(n), _array(new T[n]) {}

template <typename T>
Array<T>::Array(Array const &other) :  _n(other._n), _array(new T[other._n]) {
  for (unsigned int i = 0; i < _n; i++) {
    _array[i] = other._array[i];
  }
}

template <typename T> Array<T>::~Array() { delete[] _array; }

template <typename T> Array<T> &Array<T>::operator=(Array const &other) {
  if (this != &other) {
    delete[] _array;
    _n = other._n;
    _array = new T[_n];
    for (unsigned int i = 0; i < _n; i++) {
      _array[i] = other._array[i];
    }
  }
  return *this;
}

template <typename T> T &Array<T>::operator[](unsigned int idx) {
  if (idx >= _n) {
    throw OutOfBoundsException();
  }
  return _array[idx];
}
template <typename T> T const &Array<T>::operator[](unsigned int idx) const {
  if (idx >= _n) {
    throw OutOfBoundsException();
  }
  return _array[idx];
}
template <typename T> unsigned int Array<T>::size() const { return _n; }

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw() {
  return ("Index out of bounds");
}

#endif
