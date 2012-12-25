/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-12-13
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    if (n < 0)
      return 0;
    vector<int> fib(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
      fib[i] = fib[i - 2] + fib[i - 1];
    }
    return fib[n];
  }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution s;
  for (int n = 0; n <= 10; ++n) {
    std::cout << n << ", " << s.climbStairs(n) << std::endl;
  }

  return 0;
}
