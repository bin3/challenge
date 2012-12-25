/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-12-11
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int> &num, int target) {
    sort(num.begin(), num.end());
    int best = num[0] + num[1] + num[2];
    for (size_t i = 0; i < num.size(); ++i) {
      for (size_t j = i + 1; j < num.size() - 1; ++j) {
        int sum = num[i] + num[j];
        int val = target - sum;
        vector<int>::const_iterator it = lower_bound(num.begin() + j + 1, num.end(), val);
        if (it == num.end()) {
          int x = sum + num.back();
          if (abs(x - target) < abs(best - target)) {
            best = x;
          }
        } else {
          int x = sum + *it;
          if (abs(x - target) < abs(best - target)) {
            best = x;
          }
          if (num.begin() + j < it - 1) {
            x = sum + *(it - 1);
            if (abs(x - target) < abs(best - target)) {
              best = x;
            }
          }
        }
        if (best == target) {
          return best;
        }
      }
    }
    return best;
  }
};


#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  int arr[] = {-1, 2, 1, -4};
  int sz = sizeof(arr) / sizeof(arr[0]);
  vector<int> num(arr, arr + sz);
  int target = 1;

  Output(num);

  Solution s;
  std::cout << "threeSumClosest=" << s.threeSumClosest(num, target) << std::endl;

  return 0;
}
