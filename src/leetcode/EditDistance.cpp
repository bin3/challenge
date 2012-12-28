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
 * @date		2012-12-29
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int> > d(n1 + 1, vector<int>(n2 + 1));
        for (int i = 0; i <= n1; ++i) d[i][0] = i;
        for (int i = 0; i <= n2; ++i) d[0][i] = i;
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                int mind = d[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]);
                mind = std::min(mind, d[i][j - 1] + 1);
                mind = std::min(mind, d[i - 1][j] + 1);
                d[i][j] = mind;
            }
        }
        return d[n1][n2];
    }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  string s = "abaabcbcd";
  string t = "abc";
  std::cout << "Input:\n";
  Output(s);
  Output(t);

  Solution sol;

  std::cout << "Output:\n";
  Output(sol.minDistance(s, t));

  return 0;
}
