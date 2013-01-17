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
 * @date		2013-1-17
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
      string ep = evenPalindrome(s);
      string op = oddPalindrome(s);
      return (ep.size() > op.size()) ? ep : op;
  }

  string evenPalindrome(const string& s) {
      int mlen = 0;
      int mid = 0;
      for (int i = 0, len = s.length(); i < len; ++i) {
          int k = 1;
          for ( ; i + 1 - k >= 0 && i + k < len && s[i + 1 - k] == s[i + k]; ++k) {}
          --k;
          if (mlen < k) {
              mlen = k;
              mid = i;
          }
      }
      return s.substr(mid + 1 - mlen, mlen * 2);
  }

  string oddPalindrome(const string& s) {
      int mlen = 0;
      int mid = 0;
      for (int i = 1, len = s.length(); i < len; ++i) {
          int k = 1;
          for ( ; i - k >= 0 && i + k < len && s[i - k] == s[i + k]; ++k) {}
          --k;
          if (mlen < k) {
              mlen = k;
              mid = i;
          }
      }
      return s.substr(mid - mlen, mlen * 2 + 1);
  }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  std::string s = "bb";
  std::cout << "Input:\n";
  Output(s);
  std::cout << "Output:\n";
  Output(sol.longestPalindrome(s));

  return 0;
}
