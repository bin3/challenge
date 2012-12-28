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
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        std::vector<int> d(n + 1, 0);
        d[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] != '0') d[i] = d[i - 1];
            if (i - 2 >= 0 && isAChar(s[i - 2], s[i - 1])) d[i] += d[i - 2];
        }
        return d[n];
    }
private:
    bool isAChar(char first, char second) {
        return first == '1' || (first == '2' && second <= '6');
    }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  std::string str = "11023";

  std::cout << "Input:\n";
  Output(str);

  Solution s;

  std::cout << "Output:\n";
  Output(s.numDecodings(str));

  return 0;
}
