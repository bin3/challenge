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
 * @date		2013-3-12
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses_dp(string s) {
        static const char kL = '(';
        static const char kR = ')';

        int maxlen = 0;
        int n = s.size();
        vector<vector<int> > d(n, vector<int>(n, 0));
        for (int i = 1; i < n; ++i) {
            if (s[i-1] == kL && s[i] == kR) {
                d[i-1][i] = 2;
                maxlen = 2;
            }
        }
        for (int len = 4; len <= n; len += 2) {
            for (int i = 0; i + len <= n; ++i) {
                int e = i + len - 1;
                for (int j = i + 2; j < e; j += 2) {
                    if (d[i][j-1] && d[j][e]) {
                        d[i][e] = std::max(d[i][e], d[i][j-1] + d[j][e]);
                    }
                }
                if (s[i] == kL && s[e] == kR && d[i+1][e-1]) {
                    d[i][e] = std::max(d[i][e], d[i+1][e-1] + 2);
                }
                maxlen = std::max(maxlen, d[i][e]);
            }
        }
        return maxlen;
    }
    int longestValidParentheses(string s) {
        static const char kL = '(';
        static const char kR = ')';

        int maxlen = 0;
        vector<int> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == kL) {
                stk.push_back(0);
            }
            else {
                if (!stk.empty()) {
                    if (stk.back() == 0) {
                        stk.pop_back();
                        if (!stk.empty() && stk.back() != 0) ++stk.back();
                        else stk.push_back(1);
                        maxlen = std::max(maxlen, stk.back());
                    } else {
                        int len = stk.back();
                        stk.pop_back();
                        if (!stk.empty()) {
                            stk.pop_back();
                            if (!stk.empty() && stk.back() != 0) stk.back() += len + 1;
                            else stk.push_back(len + 1);
                            maxlen = std::max(maxlen, stk.back());
                        } else stk.clear();
                    }
                }
            }
        }
        return maxlen * 2;
    }
};

#include "../util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;
  string s = "(()())";
  Output(s);
  Output(sol.longestValidParentheses(s));

  return 0;
}
