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
#include <bitset>
#include <set>
using namespace std;

class Solution {
public:
  vector<int> grayCode(int n) {
    vector<int> seq;
    bitset<32> x(0);
    set<int> st;

    st.insert(0);
    seq.push_back(0);
    while (true) {
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        x[i] = !x[i];
        int num = x.to_ulong();
        if (st.count(num) == 0) {
          st.insert(num);
          seq.push_back(num);
          ++cnt;
        } else {
          x[i] = !x[i];
        }
      }
      if (cnt == 0)
        break;
    }
    return seq;
  }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  int n = 2;

  std::cout << "Input:\n";
  Output(n);

  Solution sol;
  vector<int> vec = sol.grayCode(n);

  std::cout << "Output:\n";
  Output(vec);

  return 0;
}
