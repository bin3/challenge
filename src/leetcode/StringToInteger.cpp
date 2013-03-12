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

#include <stdint.h>
#include <limits>

class Solution {
public:
    int atoi(const char *str) {
        int n = strlen(str);
        bool positive = true;
        int b = 0;
        while (str[b] == ' ') ++b;
        if (str[b] == '-') positive = false;
        if (str[b] == '-' || str[b] == '+') ++b;
        int64_t x = 0;
        for ( ; b < n; ++b) {
            if (!isdigit(str[b])) break;
            x = x * 10 + str[b] - '0';
        }
        x = positive ? x : -x;
        if (x < std::numeric_limits<int>::min()) x = std::numeric_limits<int>::min();
        else if (x > std::numeric_limits<int>::max()) x = std::numeric_limits<int>::max();
        return x;
    }
};

#include "../util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  return 0;
}
