/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-12-11
 */

#ifndef UTIL_H_
#define UTIL_H_

#include <iostream>
#include <vector>

#define NAME_VAL(v) #v << "=" << v
#define NAME_VAL_COMMA(v) NAME_VAL(v) << ", "
#define NV_ NAME_VAL
#define NVC_ NAME_VAL_COMMA
#define NVE_(v) NV_(v) << "\n"

template<typename T>
static void Output(const std::vector<T>& vec, std::ostream& os = std::cout) {
  os << "[";
  if (vec.size() > 0) {
    os << vec[0];
  }
  for (size_t i = 1; i < vec.size(); ++i) {
    os << ", " << vec[i];
  }
  os << "]\n";
}

template<typename T>
static void Output(const T* vec, size_t n, std::ostream& os = std::cout) {
  os << "[";
  if (n > 0) {
    os << vec[0];
  }
  for (size_t i = 1; i < n; ++i) {
    os << ", " << vec[i];
  }
  os << "]\n";
}

template<typename T>
static void Output(const std::vector<std::vector<T> >& vecs, std::ostream& os = std::cout) {
  os << "[\n";
  for (size_t i = 0; i < vecs.size(); ++i) {
    os << "  [";
    if (vecs[i].size() > 0) {
      os << vecs[i][0];
    }
    for (size_t j = 1; j < vecs[i].size(); ++j) {
      os << ", " << vecs[i][j];
    }
    os << "]\n";
  }
  os << "]\n";
}

template<typename T>
static void Output(const T& x, std::ostream& os = std::cout) {
  os << x << "\n";
}

template<typename T>
static void ToVector(const T* arr, int sz, std::vector<T>* vec) {
  vector<T> tmp(arr, arr + sz);
  vec->swap(tmp);
}

#endif /* UTIL_H_ */
