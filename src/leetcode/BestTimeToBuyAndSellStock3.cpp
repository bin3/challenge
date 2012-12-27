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

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    if (n < 2)
      return 0;
    vector<int> lmax(n, 0);
    vector<int> rmax(n, 0);
    for (int i = 1, minp = prices[0]; i < n; ++i) {
      if (minp > prices[i])
        minp = prices[i];
      else
        lmax[i] = prices[i] - minp;
    }
    for (int i = n - 2, maxp = prices[n - 1], maxpt = 0; i >= 0; --i) {
      maxpt = std::max(maxpt, maxp - prices[i]);
      rmax[i] = maxpt;
      if (maxp < prices[i])
        maxp = prices[i];
    }
    int maxpt = 0;
    for (int i = 0; i < n; ++i) {
      maxpt = std::max(maxpt, lmax[i] + rmax[i]);
    }
    return maxpt;
  }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

//  int arr[] = {2, 3, 1, 1, 4};
//  int arr[] = {5, 3, 4, 6, 2, 1, 3, 5, 1};
//  int arr[] = {6, 1, 3, 2, 4, 7};
  int arr[] = {7, 10, 1, 3, 2, 6, 1, 5, 1, 3};
  int sz = sizeof(arr) / sizeof(arr[0]);
  vector<int> vec(arr, arr + sz);

  std::cout << "Input:\n";
  Output(vec);

  Solution s;

  std::cout << "Output:\n";
  Output(s.maxProfit(vec));

  return 0;
}
