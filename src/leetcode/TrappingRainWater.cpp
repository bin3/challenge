/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-12-15
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int trap(int A[], int n) {
    if (n == 0) return 0;

    int me = 0;
    int mi = 0;
    for (int i = 0; i < n; ++i) {
      if (me < A[i]) {
        me = A[i];
        mi = i;
      }
    }

    int res = 0;
    for (int i = 1, a = A[0]; i < mi; ++i) {
      if (a < A[i]) {
        a = A[i];
      } else {
        res += a - A[i];
      }
    }
    for (int i = n - 2, a = A[n - 1]; i > mi; --i) {
      if (a < A[i]) {
        a = A[i];
      } else {
        res += a - A[i];
      }
    }

    return res;
  }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
  int sz = sizeof(arr) / sizeof(arr[0]);
  vector<int> vec(arr, arr + sz);

  std::cout << "Input:\n";
  Output(vec);

  Solution s;

  std::cout << "Output:\n" << s.trap(arr, sz) << std::endl;

  return 0;
}
