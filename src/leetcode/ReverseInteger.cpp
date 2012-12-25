/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-12-13
 */

#include <stdint.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int reverse(int x) {
    int sig = (x >= 0) ? 1: -1;
    if (x < 0) x = -x;

    int64_t r = 0;
    while (x > 0) {
      r = r * 10 + x % 10;
      x /= 10;
    }

    r *= sig;
    return r;
  }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  int arr[] = {1, 123, -123, 10000, 123456, 1000000045};
  int sz = sizeof(arr) / sizeof(arr[0]);

  Solution s;
  for (int i = 0; i < sz; ++i) {
    std::cout << arr[i] << ", " << s.reverse(arr[i]) << std::endl;
  }

  return 0;
}
