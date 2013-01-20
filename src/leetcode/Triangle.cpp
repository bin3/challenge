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
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int> > &triangle) {
      std::vector<int> prv(triangle.size(), 0);
      std::vector<int> nxt(triangle.size());
      for (size_t i = 0, n = triangle.size(); i < n; ++i) {
          for (size_t j = 0, m = triangle[i].size(); j < m; ++j) {
              if (j == 0 ) nxt[j] = prv[j];
              else if (j == m - 1) nxt[j] = prv[j - 1];
              else nxt[j] = std::min(prv[j-1], prv[j]);
              nxt[j] += triangle[i][j];
          }
          prv.swap(nxt);
      }
      return *(std::min_element(prv.begin(), prv.end()));
  }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  return 0;
}
