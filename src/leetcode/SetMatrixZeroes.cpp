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
 * @date		2013-3-10
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        size_t nr = matrix.size();
        size_t nc = matrix[0].size();
        int r0 = matrix[0][0];
        int c0 = matrix[0][0];
        for (size_t c = 0; c < nc; ++c) {
            if (matrix[0][c] == 0) {
                r0 = 0;
                break;
            }
        }
        for (size_t r = 0; r < nr; ++r) {
            if (matrix[r][0] == 0) {
                c0 = 0;
                break;
            }
        }

        for (size_t r = 1; r < nr; ++r) {
            for (size_t c = 1; c < nc; ++c) {
                if (matrix[r][c] == 0) {
                    matrix[0][c] = 0;
                    matrix[r][0] = 0;
                }
            }
        }

        for (size_t r = 1; r < nr; ++r) {
            if (matrix[r][0]) continue;
            for (size_t c = 1; c < nc; ++c) matrix[r][c] = 0;
        }
        for (size_t c = 1; c < nc; ++c) {
            if (matrix[0][c]) continue;
            for (size_t r = 1; r < nr; ++r) matrix[r][c] = 0;
        }
        if (c0 == 0) {
            for (size_t r = 1; r < nr; ++r) matrix[r][0] = 0;
        }
        if (r0 == 0) {
            for (size_t c = 1; c < nc; ++c) matrix[0][c] = 0;
        }
        matrix[0][0] = (c0 != 0 && r0 != 0) ? c0 : 0;
    }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  return 0;
}
