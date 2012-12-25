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
  vector<vector<int> > threeSum(vector<int> &num) {
    sort(num.begin(), num.end());
    vector<vector<int> > triples;
    for (size_t i = 0; i < num.size(); ++i) {
      if (i > 0 && num[i - 1] == num[i]) continue;
      for (size_t j = i + 1; j < num.size(); ++j) {
        if (j > i + 1 && num[j - 1] == num[j]) continue;
        int sum = num[i] + num[j];
        if (binary_search(num.begin() + j + 1, num.end(), -sum)) {
          triples.push_back(vector<int>());
          vector<int>& triple = triples.back();
          triple.push_back(num[i]);
          triple.push_back(num[j]);
          triple.push_back(-sum);
        }
      }
    }
    return triples;
  }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

//  int arr[] = {-1, 0, 1, 2, -1, -4};
  int arr[] = {-1, 0, 0, 1, 1, 2, -1, -4};
  int sz = sizeof(arr) / sizeof(arr[0]);
  vector<int> num(arr, arr + sz);

  Output(num);

  Solution s;
  vector<vector<int> > triples = s.threeSum(num);

  Output(triples);

  return 0;
}
