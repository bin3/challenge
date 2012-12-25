/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-12-14
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int firstMissingPositive(int A[], int n) {
    for (int i = 0; i < n; ++i) {
      if (A[i] - 1 != i) {
        int a = A[i];
        A[i] = 0;
        while (a >= 1 && a <= n && A[a - 1] != a) {
          int na = A[a - 1];
          A[a - 1] = a;
          a = na;
        }
      }
    }

    int min = 0;
    while (min < n && A[min]) {
      ++min;
    }
    return min + 1;
  }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

//  int arr[] = {1, 2, 0};
//  int arr[] = {3, 4, -1, 1};
//  int arr[] = {1, 2, 3};
  int arr[] = { 1, -2, 3};
//  int arr[] = {-1, 22, -3};
  int sz = sizeof(arr) / sizeof(arr[0]);
  vector<int> vec(arr, arr + sz);

  std::cout << "Input:\n";
  Output(vec);

  Solution s;

  std::cout << "Output:\n";
  std::cout << s.firstMissingPositive(arr, sz) << std::endl;

  return 0;
}
