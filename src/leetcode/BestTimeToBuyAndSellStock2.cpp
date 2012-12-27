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
    int profit = 0;
    if (prices.size() > 0) {
      int minp = prices[0];
      for (std::size_t i = 0; i < prices.size(); ++i) {
        if (i + 1 == prices.size()) {
          profit += prices[i] - minp;
        } else if (prices[i] > prices[i + 1]) {
          profit += prices[i] - minp;
          minp = prices[i + 1];
        }
      }
    }
    return profit;
  }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

//  int arr[] = {2, 3, 1, 1, 4};
//  int arr[] = {5, 3, 4, 6, 2, 1, 3, 5, 1};
  int arr[] = {6, 1, 3, 2, 4, 7};
  int sz = sizeof(arr) / sizeof(arr[0]);
  vector<int> vec(arr, arr + sz);

  std::cout << "Input:\n";
  Output(vec);

  Solution s;

  std::cout << "Output:\n";
  Output(s.maxProfit(vec));

  return 0;
}
