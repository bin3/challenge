/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-12-12
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int> > subsetsWithDup(vector<int> &S) {
    map<int, size_t> i2cnt;
    for (size_t i = 0; i < S.size(); ++i) {
      ++i2cnt[S[i]];
    }

    seq_.clear();
    for (map<int, size_t>::iterator it = i2cnt.begin(); it != i2cnt.end(); ++it) {
      seq_.push_back(*it);
    }

    vecs_.clear();
    vec_.clear();
    subsets(0);
    return vecs_;
  }
private:
  vector<pair<int, size_t> > seq_;
  vector<int> vec_;
  vector<vector<int> > vecs_;

  void subsets(size_t i) {
    if (i >= seq_.size()) {
      vecs_.push_back(vec_);
      return;
    }
    for (size_t j = 0; j < seq_[i].second; ++j) {
      vec_.push_back(seq_[i].first);
    }
    for (size_t j = 0; j < seq_[i].second; ++j) {
      subsets(i + 1);
      vec_.pop_back();
    }
    subsets(i + 1);
  }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

//  int arr[] = {1, 2, 3};
  int arr[] = {1, 2, 2};
  int sz = sizeof(arr) / sizeof(arr[0]);
  vector<int> num(arr, arr + sz);

  std::cout << "Input:\n";
  Output(num);

  Solution s;
  vector<vector<int> > vecs = s.subsetsWithDup(num);

  std::cout << "Output:\n";
  Output(vecs);

  return 0;
}
