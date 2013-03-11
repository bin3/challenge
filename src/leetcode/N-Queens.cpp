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
    static const char kM = 'M';

    void init(int n) {
        n_ = n;
        string row(n, kS);
        sol_ = vector<string>(n, row);
        cused_ = vector<bool>(n, false);
        dused_ = vector<vector<int> >(n, vector<int>(n, 0));
        sols_ = 0;
    }
    int totalNQueens(int n) {
        init(n);
        dfs(0);
        return sols_;
    }
private:
    int n_;
    int sols_;
    vector<string> sol_;
    vector<bool> cused_;
    vector<vector<int> > dused_;

    bool valid(int r, int c) {
      return r >= 0 && r < n_ && c >= 0 && c < n_;
    }
    void markDiagonal(int r, int c, int val) {
        static const int kN = 4;
        static const int rex[kN] = {-1, -1, 1, 1};
        static const int cex[kN] = {-1, 1, 1, -1};

        for (int i = 0; i < kN; ++i) {
            for (int j = 1; ; ++j) {
                int newr = r + j * rex[i];
                int newc = c + j * cex[i];
                if (!valid(newr, newc)) break;
                dused_[newr][newc] += val;
            }
        }
    }
    void dfs(int r) {
        if (r == n_) {
            ++sols_;
            return;
        }
        for (int c = 0; c < n_; ++c) {
            if (!cused_[c] && dused_[r][c] == 0) {
                cused_[c] = true;
                sol_[r][c] = kQ;
                markDiagonal(r, c, 1);
                dfs(r + 1);
                markDiagonal(r, c, -1);
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
    Output(sol.totalNQueens(n));
  }

  return 0;
}
