#pragma once
#include <exception>
template <typename T> class Array {
public:
  unsigned int _n;
  T *_array;

  Array();
  Array(unsigned int n);
  ~Array();

  unsigned int size() const;
  Array(Array const &other);
  Array &operator=(Array const &other);
  T &operator[](unsigned int idx);
  T const &operator[](unsigned int idx) const;

  class OutOfBoundsException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

#include "Array.tpp"
