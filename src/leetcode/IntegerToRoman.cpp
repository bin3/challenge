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
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        const int kN = 7;
        int v[kN] = {1, 5, 10, 50, 100, 500, 1000};
        char c[kN] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

        string s;
        for (int i = kN - 1; i >= 0; i -= 2) {
            int n = num / v[i];
            if (n >= 1 && n <=3) {
                for (int j = 0; j < n; ++j) s.push_back(c[i]);
            } else if (n >= 4 && n <= 8) {
                for (int j = 0; j < 5 - n; ++j) s.push_back(c[i]);
                s.push_back(c[i+1]);
                for (int j = 0; j < n - 5; ++j) s.push_back(c[i]);
            }
            else if (n == 9) {
                s.push_back(c[i]);
                s.push_back(c[i+2]);
            }
            num = num % v[i];
        }
        return s;
    }
};

#include "../util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  return 0;
}
