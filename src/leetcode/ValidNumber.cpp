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
    bool isNumber(const char *s) {
        int e = strlen(s);
        int b = 0;
        for ( ; b < e && s[b] == ' '; ++b) {}
        for ( ; e > b && s[e-1] == ' '; --e) {}
        if (b == e) return false;
        const char* pe = strchr(s, 'e');
        if (pe) return isReal(s + b, pe - (s + b)) && isInteger(pe + 1, s + e - (pe + 1));
        else return isReal(s + b, e - b);
    }
    bool isReal(const char* s, int n) {
        if (n == 0) return false;
        int b = (s[0] == '+' || s[0] == '-');
        if (b == n) return false;
        bool has_dot = false;
        for (int i = b; i < n; ++i) {
            if (isdigit(s[i])) continue;
            if (s[i] == '.') {
                if (has_dot) return false;
                has_dot = true;
            } else return false;
        }
        if (has_dot && b + 1 == n) return false;
        return true;
    }
    bool isInteger(const char* s, int n) {
        if (n == 0) return false;
        int b = (s[0] == '+' || s[0] == '-');
        if (b == n) return false;
        for (int i = b; i < n; ++i) {
            if (!isdigit(s[i])) return false;
        }
        return true;
    }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  return 0;
}
