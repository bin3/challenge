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
#include <algorithm>
using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) {
    string res = "0";
    int n = num2.size();
    for (int i = n - 1; i >= 0; --i) {
      string m = multiply(num1, num2[i] - '0');
      m = multpow10(m, n - 1 - i);
      res = add(res, m);
    }
    return res;
  }
private:
  string multiply(const string& num, int x) {
    if (x == 0) return "0";
    if (x == 1) return num;
    string res = "";
    int carry = 0;
    int n = num.size();
    for (int i = n - 1; i >= 0; --i) {
      int m = (num[i] - '0') * x + carry;
      carry = m / 10;
      int d = m % 10;
      res.push_back(d + '0');
    }
    if (carry) {
      res.push_back(carry + '0');
    }
    std::reverse(res.begin(), res.end());
    return res;
  }

  char dadd(char a, char b, int& carry) {
    int sum = (a - '0') + (b - '0') + carry;
    carry = sum / 10;
    return sum % 10 + '0';
  }
  string add(const string& a, const string& b) {
    if (a == "0") return b;
    if (b == "0") return a;
    int an = a.size();
    int bn = b.size();
    string res;
    int carry = 0;
    int ai = an - 1;
    int bi = bn - 1;
    for (; ai >= 0 && bi >= 0; --ai, --bi) {
      res.push_back(dadd(a[ai], b[bi], carry));
    }
    for (; ai >= 0; --ai) {
      res.push_back(dadd(a[ai], '0', carry));
    }
    for (; bi >= 0; --bi) {
      res.push_back(dadd(b[bi], '0', carry));
    }
    if (carry) {
      res.push_back(carry + '0');
    }
    std::reverse(res.begin(), res.end());
    return res;
  }
  string multpow10(const string& num, int n) {
    if (num == "0" || n <= 0) return num;
    string res = num;
    while (--n >= 0) {
      res.push_back('0');
    }
    return res;
  }
};

#include "../util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  return 0;
}
