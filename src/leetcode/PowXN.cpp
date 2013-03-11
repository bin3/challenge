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
 * @date		2013-3-11
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include <stdint.h>

class Solution {
public:
    double pow(double x, int n) {
        if (n < 0) return 1 / unneg_pow(x, -(int64_t)n);
        return unneg_pow(x, n);
    }
private:
    double unneg_pow(double x, int64_t n) {
        double p = 1;
        for ( ; n; n = n >> 1) {
            if (n & 1) p *= x;
            x = x * x;
        }
        return p;
    }
};

#include "../util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  return 0;
}
