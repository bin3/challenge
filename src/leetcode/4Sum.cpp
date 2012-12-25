/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-12-11
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  struct TwoSum {
    int sum;
    size_t a;
    size_t b;
    TwoSum(int sum = 0, size_t a = 0, size_t b = 0): sum(sum), a(a), b(b) {}
    bool operator<(const TwoSum& other) const {
      if (sum == other.sum) {
        if (a == other.a) {
          return b < other.b;
        }
        return a < other.a;
      }
      return sum < other.sum;
    }
  };
  struct SumABCmp {
    bool operator()(const TwoSum& lhs, const TwoSum& rhs) const {
      if (lhs.sum == rhs.sum) {
        if (lhs.a == rhs.a) {
          return lhs.b < rhs.b;
        }
        return lhs.a < rhs.a;
      }
      return lhs.sum < rhs.sum;
    }
  } sumabcmp;
  struct SumCmp {
    bool operator()(const TwoSum& lhs, const TwoSum& rhs) const {
      return lhs.sum < rhs.sum;
    }
  } sumcmp;

  vector<vector<int> > fourSum(vector<int> &num, int target) {
    sort(num.begin(), num.end());

    size_t n = num.size();
    vector<TwoSum> sums;
    for (size_t i = 0; i < n; ++i) {
      for (size_t j = i + 1; j < n; ++j) {
        sums.push_back(TwoSum(num[i] + num[j], i, j));
      }
    }
    sort(sums.begin(), sums.end(), sumabcmp);

    vector<vector<int> > vecs;
    TwoSum val;
    for (size_t i = 0; i < n; ++i) {
      if (i > 0 && num[i - 1] == num[i]) continue;
      for (size_t j = i + 1; j + 2 < n; ++j) {
        if (j > i + 1 && num[j - 1] == num[j]) continue;
        val.sum = target - (num[i] + num[j]);
        pair<vector<TwoSum>::iterator,vector<TwoSum>::iterator> bounds =
            equal_range(sums.begin(), sums.end(), val, sumcmp);
        bool prv = false;
        int prv_third = 0;
        for (vector<TwoSum>::iterator it = bounds.first; it != bounds.second; ++it) {
          if (it->a <= j) continue;
          if (!prv) {
            prv = true;
          } else if (prv_third == num[it->a]) {
            continue;
          }
          prv_third = num[it->a];

          vecs.push_back(vector<int>());
          vector<int>& v = vecs.back();
          v.push_back(num[i]);
          v.push_back(num[j]);
          v.push_back(num[it->a]);
          v.push_back(num[it->b]);
        }
      }
    }

    return vecs;
  }
};

#include "util.h"

int main(int argc, char **argv) {
	std::cout << "------" << argv[0] << "------" << std::endl;
	
//	int arr[] = {1, 0, -1, 0, -2, 2};
//  int arr[] = {-2, -1, 0, 0, 1, 2};
//	int arr[] = {0};
	int arr[] = {0, 0, 0, 0};
	int sz = sizeof(arr) / sizeof(arr[0]);
  vector<int> num(arr, arr + sz);
  int target = 0;

  std::cout << "Input:\n";
  Output(num);

  Solution s;
  vector<vector<int> > vecs = s.fourSum(num, target);

  std::cout << "Output:\n";
  Output(vecs);

  return 0;
}
