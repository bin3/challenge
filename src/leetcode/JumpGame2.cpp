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
  // [begin, end)
  struct Reach {
    Reach(int b, int e): begin(b), end(e) {}
    int begin;
    int end;
  };
  int jump(int A[], int n) {
    if (n <= 1) return 0;
    Reach cur(0, 1);
    for (int step = 0; step < n; ++step) {
      if (cur.begin == cur.end) break;
      Reach nxt(cur.end, cur.end);
      for (int i = cur.begin; i < cur.end; ++i) {
        nxt.end = std::max(nxt.end, i + A[i] + 1);
      }
      if (nxt.end >= n) return step + 1;
      cur = nxt;
    }
    return -1;
  }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

//  int arr[] = {2, 3, 1, 1, 4};
//  int arr[] = {3, 2, 1, 0, 4};
//  int arr[] = {0};
//  int arr[] = {};
  int arr[] = {1, 1, 1, 1, 1};
  int sz = sizeof(arr) / sizeof(arr[0]);
  vector<int> vec(arr, arr + sz);

  std::cout << "Input:\n";
  Output(vec);

  Solution s;

  std::cout << "Output:\n";
  Output(s.jump(arr, sz));

  return 0;
}
