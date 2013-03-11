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

#include "../util.h"

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if (n <= 1) return;
        for (int r = 0; r <= n / 2 - 1; ++r) {
            for (int c = 0; c <= (n - 1) / 2; ++c) {
                int cr = r;
                int cc = c;
                int prv = matrix[r][c];
                for (int i = 0; i < 4; ++i) {
                    int nr = cc;
                    int nc = n - 1 - cr;
                    int nxt = matrix[nr][nc];
                    matrix[nr][nc] = prv;
                    cr = nr;
                    cc = nc;
                    prv = nxt;
                }
            }
        }
    }
};

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  for (int n = 1; n <= 4; ++n) {
    vector<vector<int> > matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        matrix[i][j] = i * n + j + 1;
      }
    }
    std::cout << NVE_(n);
    Output(matrix);
    sol.rotate(matrix);
    Output(matrix);
  }

  return 0;
}
