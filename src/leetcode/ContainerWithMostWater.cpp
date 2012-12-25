/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-12-12
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
      int n = height.size();
      int maxh = -1;
      int maxi = 0;
      for (int i = 0; i < n; ++i) {
        if (maxh < height[i]) {
          maxh = height[i];
          maxi = i;
        }
      }

      int maxa = 0;
      for (int lt = 0, rt = n - 1; lt <= maxi; ) {
        while (height[lt] > height[rt]) {
          maxa = std::max(maxa, height[rt] * (rt - lt));
          --rt;
        }
        maxa = std::max(maxa, height[lt] * (rt - lt));
        int prvh = height[lt];
        while (++lt <= maxi && height[lt] <= prvh) {}
      }
      return maxa;
    }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

//  int arr[] = {0, 0, 0, 0};
//  int arr[] = {1, 3, 3, 1};
//  int arr[] = {5, 3, 3, 1};
//  int arr[] = {1, 3, 3, 5};
  int arr[] = { 1, 3, 4, 1, 1};
  int sz = sizeof(arr) / sizeof(arr[0]);
  vector<int> vec(arr, arr + sz);
  int target = 0;

  std::cout << "Input:\n";
  Output(vec);

  Solution s;
  int area = s.maxArea(vec);

  std::cout << "Output:\n";
  std::cout << area << std::endl;

  return 0;
}
