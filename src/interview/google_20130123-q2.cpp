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
 * @date		2013-1-23
 */

#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int> Ivec;

void Remove(Ivec& sarr, int x) {
  Ivec::iterator it = std::binary_search(sarr.begin(), sarr.end(), x);
  if (it != sarr.end()) {
    sarr.erase(it);
  }
}

void Insert(Ivec& sarr, int x) {
  Ivec::iterator it = std::lower_bound(sarr.begin(), sarr.end(), x, std::greater<int>());
//  sarr.erase(it, sarr.end());
//  sarr.push_back(x);
  sarr.insert(it, x);
}

void Mid(int arr[], int mid[], int m, int n) {
  if (n <= 0 || m <= 0 || m < n) return;  // do nothing

  Ivec sarr;  // sorted array, started with the maximum element
  for (int i = 0; i < n; ++i) {
    Insert(sarr, arr[i]);
  }
  int sc = 0;
  for (int i = 0; i + n <= m; ++i) {
//    max[i] = sarr[0];
    mid[i] = sarr[n / 2];
    if (i + n < m) {
      Remove(sarr, arr[i]);
      Insert(sarr, arr[i + n]);
    }
  }
}


int main(int argc, char **argv) {
	std::cout << "------" << argv[0] << "------" << std::endl;
	
  return 0;
}
