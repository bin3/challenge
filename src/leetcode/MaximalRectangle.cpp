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
 * @date		2013-3-9
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        size_t nr = matrix.size();
        size_t nc = matrix[0].size();
        vector<vector<size_t> > d(nr, vector<size_t>(nc, 0));
        for (size_t i = 0; i < nr; ++i) {
            d[i][0] = (matrix[i][0] == '1');
            for (size_t j = 1; j < nc; ++j) {
                if (matrix[i][j] == '1') {
                    d[i][j] = d[i][j-1] + 1;
                }
            }
        }
        int maxa = 0;
        for (int i = nr - 1; i >= 0; --i) {
            for (int j = nc - 1; j >= 0; --j) {
                int len = d[i][j];
                int minlen = maxa / (i + 1) + 1;
                for (int k = i; k >= 0; --k) {
                    if (len > d[k][j]) len = d[k][j];
                    if (len < minlen) break;
                    int newa = len * (i - k + 1);
                    if (maxa < newa) maxa = newa;
                }
            }
        }
        return maxa;
    }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  return 0;
}
