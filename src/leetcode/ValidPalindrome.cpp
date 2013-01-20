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
  bool isPalindrome(string s) {
      for (int i = 0; i < s.size(); ++i) {
          if (std::isupper(s[i])) s[i] = std::tolower(s[i]);
      }

      for (int b = 0, e = (int)s.size() - 1; b <= e; ++b, --e) {
          while (b <= e && !std::isalnum(s[b])) ++b;
          while (b <= e && !std::isalnum(s[e])) --e;
          if (b <= e) {
              if (s[b] != s[e]) return false;
          }
      }
      return true;
  }
  vector<vector<int> > run(vector<int> &vec) {
    vector<vector<int> > vecs;
    vecs.push_back(vec);
    vecs.push_back(vec);
    return vecs;
  }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  std::string s = "A man, a plan, a canal: Panama";

  std::cout << "Input:\n";
  Output(s);

  std::cout << "Output:\n";
  Output(sol.isPalindrome(s));

  return 0;
}
