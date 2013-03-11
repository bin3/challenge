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
 * @date		2013-3-11
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include <sstream>
#include <algorithm>

class Solution {
public:
    string getPermutation(int n, int k) {
        std::vector<int> p(n + 1);
        std::vector<int> d(n);
        p[1] = 1;
        for (int i = 2; i <= n; ++i) p[i] = p[i-1] * i;
        for (int i = 0; i < n; ++i) d[i] = i + 1;

        std::vector<int> v;
        for (int i = n - 1; i >= 1; --i) {
            int idx = (k - 1) / p[i];
            v.push_back(d[idx]);
            d.erase(d.begin() + idx);
            k -= idx * p[i];
        }
        v.push_back(d[0]);

        std::stringstream ss;
        for (int i = 0; i < n; ++i) ss << v[i];
        return ss.str();
    }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  return 0;
}
