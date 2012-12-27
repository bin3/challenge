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
 * @date		2012-12-27
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    if (a.size() > b.size())
      return addBinary(b, a);
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    bool carry = false;
    char ch;
    string res;
    for (size_t i = 0; i < a.size(); ++i) {
      add(a[i], b[i], carry, ch);
      res.push_back(ch);
      cout << "i=" << i << ", a[i]=" << a[i] << ", b[i]=" << b[i] << ", carry=" << carry << ", ch=" << ch << endl;
    }
    for (size_t i = a.size(); i < b.size(); ++i) {
      add('0', b[i], carry, ch);
      res.push_back(ch);
      cout << "i=" << i << ", b[i]=" << b[i] << ", carry=" << carry << ", ch=" << ch << endl;
    }
    if (carry)
      res.push_back('1');
    std::reverse(res.begin(), res.end());
    return res;
  }
private:
  void add(char a, char b, bool& carry, char& res) {
    int x = (a - '0') + (b - '0') + carry;
    carry = (x >> 1);
    res = '0' + (x & 1);
  }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  string a = "11";
  string b = "1";

  std::cout << "Input:\n";
  std::cout << "a=" << a << ", b=" << b << std::endl;

  Solution s;

  std::cout << "Output:\n";
  Output(s.addBinary(a, b));

  return 0;
}
