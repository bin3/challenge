/*
 * Copyright (c) 2012 Binson Zhang.
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
 * @date		2012-12-24
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> v;
    if (matrix.size() == 0 || matrix[0].size() == 0) return v;

    int n = matrix[0].size();
    int m = matrix.size() - 1;
    int d = 1;
    for (int x = 0, y = 0; n > 0 && m >= 0; --n, --m, d = -d) {
      for (int i = 0; i < n; ++i, y += d) {
        v.push_back(matrix[x][y]);
      }
      y -= d;
      x += d;
      for (int i = 0; i < m; ++i, x += d) {
        v.push_back(matrix[x][y]);
      }
      x -= d;
      y -= d;
    }
    return v;
  }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  int m = 5;
  int n = 2;
  vector<vector<int> > vecs(m, vector<int>(n));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      vecs[i][j] = i * n + j + 1;
    }
  }

  std::cout << "Input:\n";
  Output(vecs);

  Solution s;
  vector<int> vec = s.spiralOrder(vecs);

  std::cout << "Output:\n";
  Output(vec);

  return 0;
}
