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
    vector<int> plusOne(vector<int> &digits) {
        if (digits.size() == 0) return digits;
        bool carry = 0;
        ++digits.back();
        for (int i = digits.size() - 1; i >= 0; --i) {
            justify(digits[i], carry);
            if (!carry) break;
        }
        if (carry) digits.insert(digits.begin(), 1);
        return digits;
    }
private:
    void justify(int& digit, bool& carry) {
        int sum = digit + carry;
        digit = sum % 10;
        carry = sum / 10;
    }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  return 0;
}
