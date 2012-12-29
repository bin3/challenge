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
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
  vector<int> grayCode(int n) {
    vector<int> seq;
    const size_t BN = 32;
    unsigned int pow[BN];
    for (size_t i = 0; i < BN; ++i) {
      pow[i] = 1U << i;
    }
    unsigned int x = 0;
    set<unsigned int> st;

    st.insert(0);
    seq.push_back(0);
    bool run = true;
    while (run) {
      run = false;
      for (int i = 0; i < n; ++i) {
        x = x ^ pow[i];
        if (st.count(x) == 0) {
          st.insert(x);
          seq.push_back(x);
          run = true;
          break;
        }
        x = x ^ pow[i];
      }
    }
    return seq;
  }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  int n = 4;

  std::cout << "Input:\n";
  Output(n);

  Solution sol;
  vector<int> vec = sol.grayCode(n);

  std::cout << "Output:\n";
  Output(vec);

  return 0;
}
