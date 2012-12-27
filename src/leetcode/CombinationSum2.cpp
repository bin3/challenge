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
 * @date		2012-12-28
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    typedef vector<int> Vec;
    typedef vector<Vec> Vecs;
    typedef vector<Vecs> VecsArr;
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        VecsArr d(target + 1);
        d[0].push_back(Vec());
        int top = 0;
        for (size_t j = 0; j < candidates.size(); ++j) {
            for (int i = top; i >= 0; --i) {
                if (d[i].size() > 0) {
                    size_t k = i + candidates[j];
                    if (k > target) continue;
                    for (size_t p = 0; p < d[i].size(); ++p) {
                        d[k].push_back(d[i][p]);
                        d[k].back().push_back(candidates[j]);
                    }
                    top = std::max(top, (int)k);
                }
            }
        }

        Vecs res = d[target];
        Vecs uqres;
        set<Vec> st;
        for (size_t i = 0; i < res.size(); ++i) {
            std::sort(res[i].begin(), res[i].end());
            if (st.count(res[i]) == 0) {
                st.insert(res[i]);
                uqres.push_back(res[i]);
            }
        }
        return uqres;
    }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  int target = 10;
  int arr[] = {2, 3, 5, 7};
  int sz = sizeof(arr) / sizeof(arr[0]);
  vector<int> vec(arr, arr + sz);

  std::cout << "Input:\n";
  Output(vec);

  Solution s;
  vector<vector<int> > vecs = s.combinationSum2(vec, target);

  std::cout << "Output:\n";
  Output(vecs);

  return 0;
}
