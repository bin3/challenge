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
 * @date		2013-1-27
 */

#include <stdint.h>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

int FindMin(int n, int k, int a, int b, int c, int r) {
  std::map<int, int> cnt;
  std::deque<int> q;
  q.push_back(a);
  ++cnt[a];
  for (int i = 1; i < k; ++i) {
    int x = ((int64_t)b * q[i - 1] + c) % r;
    q.push_back(x);
    ++cnt[x];
  }
  std::vector<int> v(q.begin(), q.end());
  v.push_back(k + 1);
  std::sort(v.begin(), v.end());

  std::set<int> st;
  for (std::size_t i = 0, x = 0; i < v.size() && v[i] <= k + 1; ++i) {
    while (x < v[i]) {
      st.insert(x);
      ++x;
    }
    if (x == v[i]) ++x;
  }

  if (n > 2 * k) n = n % k + 2 * k;
  int min = 0;
  for (int i = k; i < n; ++i) {
    min = *(st.begin());
    st.erase(st.begin());
    int x = q.front();
    q.pop_front();
    if (x <= k) {
      if (--cnt[x] == 0) {
        st.insert(x);
      }
    }
    q.push_back(min);
    ++cnt[min];
  }

  return min;
}

int main(int argc, char **argv) {
  int cases = 0;
  int n, k;
  int a, b, c, r;
  std::cin >> cases;
  for (int i = 1; i <= cases; ++i) {
    std::cin >> n >> k;
    std::cin >> a >> b >> c >> r;
    std::cout << "Case #" << i << ": " << FindMin(n, k, a, b, c, r) << std::endl;
  }
  return 0;
}
