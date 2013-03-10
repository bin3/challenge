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
    string minWindow(string S, string T) {
        if (T.size() == 0 || S.size() < T.size()) return "";
        const size_t kN = 128;
        vector<int> thresholds(128, 0); // for every char
        int threshold = 0;  // for number of different chars
        for (size_t i = 0; i < T.size(); ++i) {
            if (++thresholds[T[i]] == 1) ++threshold;
        }
        vector<int> cnts(128, 0);
        int cnt = 0;
        size_t minlen = S.size() + 1;
        size_t minpos = 0;
        for (size_t i = 0, b = 0; i < S.size(); ) {
            while (cnt < threshold && i < S.size()) {
                if (thresholds[S[i]] > 0 && ++cnts[S[i]] == thresholds[S[i]]) ++cnt;
                ++i;
            }
            while (cnt == threshold) {
                if (minlen > i - b) {
                    minlen = i - b;
                    minpos = b;
                }
                if (thresholds[S[b]] > 0 && cnts[S[b]]-- == thresholds[S[b]]) --cnt;
                ++b;
            }
        }
        if (minlen > S.size()) return "";
        else return S.substr(minpos, minlen);
    }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  return 0;
}
