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
#include <set>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n <= 0) return res;
        res.push_back("()");
        set<string> st;
        for (int i = 1; i < n; ++i) {
            st.clear();
            for (size_t j = 0; j < res.size(); ++j) {
                for (size_t k = 0; k < res[j].size(); ++k) {
                    string s = res[j];
                    s.insert(k, "()");
                    st.insert(s);
                }
            }
            res.clear();
            for (set<string>::const_iterator it = st.begin(); it != st.end(); ++it) {
                res.push_back(*it);
            }
        }
        return res;
    }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  int n = 4;

  std::cout << "Input:\n";
  Output(4);

  Solution sol;
  vector<string> vecs = sol.generateParenthesis(n);

  std::cout << "Output:\n";
  Output(vecs);

  return 0;
}
