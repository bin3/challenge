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
  vector<vector<int> > subsets(vector<int> &S) {
    seq_ = S;
    sort(seq_.begin(), seq_.end());

    vecs_.clear();
    vec_.clear();
    subsets(0);
    return vecs_;
  }
private:
  vector<int> seq_;
  vector<int> vec_;
  vector<vector<int> > vecs_;

  void subsets(size_t i) {
    if (i >= seq_.size()) {
      vecs_.push_back(vec_);
      return;
    }
    vec_.push_back(seq_[i]);
    subsets(i + 1);
    vec_.pop_back();
    subsets(i + 1);
  }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  int arr[] = {1, 2, 3};
  int sz = sizeof(arr) / sizeof(arr[0]);
  vector<int> num(arr, arr + sz);

  std::cout << "Input:\n";
  Output(num);

  Solution s;
  vector<vector<int> > vecs = s.subsets(num);

  std::cout << "Output:\n";
  Output(vecs);

  return 0;
}
