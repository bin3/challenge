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

#include <algorithm>

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        size_t nr = grid.size();
        size_t nc = grid[0].size();
        vector<int> prv(nc);
        vector<int> cur(nc);
        prv[0] = grid[0][0];
        for (size_t c = 1; c < nc; ++c) prv[c] = prv[c-1] + grid[0][c];
        for (size_t r = 1; r < nr; ++r) {
            cur[0] = prv[0] + grid[r][0];
            for (size_t c = 1; c < nc; ++c) {
                cur[c] = std::min(cur[c-1], prv[c]) + grid[r][c];
            }
            prv.swap(cur);
        }
        return prv[nc-1];
    }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  return 0;
}
