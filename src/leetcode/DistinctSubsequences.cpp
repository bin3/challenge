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
#include <map>
using namespace std;

class Solution {
public:
    typedef map<char, vector<int> > Ch2Ids;
    int numDistinct(string S, string T) {
        if (S.size() < T.size()) return 0;
        if (S.size() == T.size() && S == T) return 1;
        Ch2Ids c2i;
        for (int i = (int)T.size() - 1; i >= 0; --i) {
            c2i[T[i]].push_back(i);
        }
        int n = T.size();
        vector<int> d(n + 1, 0);
        d[0] = 1;
        for (int i = 0; i < S.size(); ++i) {
            Ch2Ids::const_iterator it = c2i.find(S[i]);
            if (it != c2i.end()) {
                const vector<int>& v = it->second;
                for (int j = 0; j < v.size(); ++j) {
                    d[v[j] + 1] += d[v[j]];
                }
            }
        }
        return d[n];
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
  Output(sol.numDistinct(s, t));

  return 0;
}
