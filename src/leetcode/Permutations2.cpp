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

#include <algorithm>

namespace toystl {

template<class BidirectionalIterator>
inline bool next_permutation(BidirectionalIterator first,
    BidirectionalIterator last) {
  if (first == last) return false;
  BidirectionalIterator i = first;
  if (++i == last) return false;

  BidirectionalIterator ii = last;
  --ii;
  i = ii;
  --i;
  for ( ; !(*i < *ii); --i, --ii) {
    if (i == first) {
      std::reverse(first, last);
      return false;
    }
  }
  BidirectionalIterator j = last;
  --j;
  for ( ; !(*i < *j); --j) {}
  std::iter_swap(i, j);
  std::reverse(ii, last);
  return true;
}

}

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > perms;
        std::sort(num.begin(), num.end());
        do {
            perms.push_back(num);
        } while (toystl::next_permutation(num.begin(), num.end()));
        return perms;
    }
};

#include "../util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  return 0;
}
