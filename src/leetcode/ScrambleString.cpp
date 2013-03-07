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
 * @date		2013-3-7
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isScramble0(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        for (size_t m = 1; m < s1.size(); ++m) {
            size_t n = s1.size() - m;
            if (isScramble(s1.substr(0, m), s2.substr(0, m)) && isScramble(s1.substr(m, n), s2.substr(m, n)))
                return true;
            if (isScramble(s1.substr(0, m), s2.substr(n, m)) && isScramble(s1.substr(m, n), s2.substr(0, n)))
                return true;
        }
        return false;
    }
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        size_t n = s1.size();
        vector<vector<vector<bool> > > d(n, vector<vector<bool> >(n, vector<bool>(n, false)));
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                d[i][j][0] = (s1[i] == s2[j]);
            }
        }
        for (size_t len = 2; len <= n; ++len) {
            for (size_t i = 0; i + len <= n; ++i) {
                for (size_t j = 0; j + len <= n; ++j) {
                    for (size_t k = 1; k < len; ++k) {
                        size_t m = len - k;
                        if (d[i][j][k-1] && d[i+k][j+k][m-1]) d[i][j][len-1] = true;
                        else if (d[i][j+m][k-1] && d[i+k][j][m-1]) d[i][j][len-1] = true;
                    }
                }
            }
        }
        return d[0][0][n-1];
    }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  return 0;
}
