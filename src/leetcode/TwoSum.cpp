/*
 * Copyright (c) 2013 Binson Zhang.
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2013-3-12
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
  typedef pair<int, int> Pair;
  typedef vector<pair<int, int> > Vector;
  struct PairCmp {
    bool operator()(const Pair& lhs, const Pair& rhs) const {
      return lhs.first < rhs.first;
    }
  };
  vector<int> twoSum(vector<int> &numbers, int target) {
    Vector v(numbers.size());
    for (int i = 0; i < numbers.size(); ++i) {
      v[i].first = numbers[i];
      v[i].second = i + 1;
    }
    PairCmp cmp;
    sort(v.begin(), v.end(), cmp);
    vector<int> res;
    for (int i = 0; i < v.size(); ++i) {
      pair<Vector::iterator, Vector::iterator> range = std::equal_range(
          v.begin(), v.end(), Pair(target - v[i].first, 0), cmp);
      for (Vector::iterator it = range.first; it != range.second; ++it) {
        if (it->second != v[i].second) {
          res.push_back(v[i].second);
          res.push_back(it->second);
          if (res[0] > res[1]) std::swap(res[0], res[1]);
          return res;
        }
      }
    }
    return res;
  }
};

#include "../util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  vector<int> v;
  v.push_back(5);
  v.push_back(75);
  v.push_back(25);
  int target = 100;

  Output(v);
  Output(sol.twoSum(v, target));

  return 0;
}
