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
 * @date		2012-12-28
 */

#include <string>
#include <sstream>
using namespace std;


class Solution {
public:
    string countAndSay(int n) {
        string cur = "1";
        string nxt;
        for (int i = 1; i < n; ++i) {
            nxt.clear();
            for (size_t j = 0; j < cur.size(); ) {
                size_t k = 1;
                for ( ; j + k < cur.size() && cur[j + k] == cur[j]; ++k) {}
                nxt += toString(k, cur[j]);
                j += k;
            }
            cur.swap(nxt);
        }
        return cur;
    }
private:
    static string toString(int n, char c) {
        std::stringstream ss;
        ss << n << c;
        return ss.str();
    }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  int n = 5;

  std::cout << "Input:\n";
  Output(n);

  Solution s;

  std::cout << "Output:\n";
  Output(s.countAndSay(n));

  return 0;
}
