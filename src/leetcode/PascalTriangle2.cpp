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
 * @date		2013-1-20
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int > cur;
        if (rowIndex < 0) return cur;
        int n = rowIndex + 1;
        cur.resize(n);
        cur[0] = 1;
        vector<int > nxt(n);
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (j == 0) nxt[j] = cur[j];
                else if (j == i - 1) nxt[j] = cur[j-1];
                else nxt[j] = cur[j-1] + cur[j];
            }
            cur.swap(nxt);
        }
        return cur;
    }
};


#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  return 0;
}
