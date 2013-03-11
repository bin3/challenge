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
 * @date		2013-3-11
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    static const char kQ = 'Q';
    static const char kS = '.';

    void init(int n) {
        n_ = n;
        string row(n, kS);
        sol_ = vector<string>(n, row);
        sols_.clear();
        cused_ = vector<bool>(n, false);
    }
    vector<vector<string> > solveNQueens(int n) {
        init(n);
        dfs(0);
        return sols_;
    }
private:
    int n_;
    vector<vector<string> > sols_;
    vector<string> sol_;
    vector<bool> cused_;

    bool valid(int x) {
      return x >= 0 && x < n_;
    }
    bool checkDiagonal(int r, int c) {
      for (int i = 1; valid(r - i) && valid(c - i); ++i) {
        if (sol_[r-i][c-i] == kQ) return false;
      }
      for (int i = 1; valid(r - i) && valid(c + i); ++i) {
        if (sol_[r-i][c+i] == kQ) return false;
      }
      return true;
    }
    void dfs(int r) {
        if (r == n_) {
            sols_.push_back(sol_);
            return;
        }
        for (int c = 0; c < n_; ++c) {
            if (!cused_[c] && checkDiagonal(r, c)) {
                cused_[c] = true;
                sol_[r][c] = kQ;
                dfs(r + 1);
                sol_[r][c] = kS;
                cused_[c] = false;
            }
        }
    }
};

#include "../util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;
  for (int n = 0; n <= 4; ++n) {
    std::cout << NVE_(n);
    Output(sol.solveNQueens(n));
  }

  return 0;
}
