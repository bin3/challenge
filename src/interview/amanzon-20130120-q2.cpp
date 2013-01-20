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
 * @date		2013-1-20
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

class PileSpliter {
public:
  static const int NOANS = -1;

  bool Input(std::vector<int>& vec) {
    std::string line;
    std::getline(std::cin, line);
    line.push_back(',');
    std::stringstream ss(line);

    int x;
    char sep;
    while (ss >> x >> sep) {
      vec.push_back(x);
      if (sep != ',') break;
    }
    return true;
  }
  int Solve(const std::vector<int>& vec) {
    if (!QuickCheck(vec)) return NOANS;
    best_splits_ = NOANS;
    vec_ = &vec;
    half_ = std::accumulate(vec.begin(), vec.end(), 0) / 2;
    n_ = vec.size();
    Search(0, 0, 0);
    return best_splits_;
  }
private:
  int best_splits_;
  int n_;
  int half_;
  const std::vector<int>* vec_;

  bool QuickCheck(const std::vector<int>& vec) {
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    if (sum % 2 != 0) return false;
    return true;
  }
  void Search(int i, int used, int sum) {
    if (i == n_) {
      if (sum == half_) {
        best_splits_ = std::max(best_splits_, std::min(used, n_ - used));
      }
      return;
    }
    if (sum > half_) return;
    Search(i + 1, used + 1, sum + vec_->at(i));
    Search(i + 1, used, sum);
  }
};

int main(int argc, char **argv) {
  std::vector<int> vec;
  PileSpliter spliter;
  spliter.Input(vec);
  std::cout << spliter.Solve(vec) << std::endl;

  return 0;
}
