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

#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    typedef map<string, vector<size_t> > S2Ids;
    vector<string> anagrams(vector<string> &strs) {
        S2Ids s2ids;
        for (size_t i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            std::sort(s.begin(), s.end());
            s2ids[s].push_back(i);
        }
        vector<string> res;
        for (S2Ids::const_iterator it = s2ids.begin(); it != s2ids.end(); ++it) {
            const vector<size_t>& ids = it->second;
            if (ids.size() < 2) continue;
            for (size_t i = 0; i < ids.size(); ++i) {
                res.push_back(strs[ids[i]]);
            }
        }
        return res;
    }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  string arr[] = {"ant", "tan", "nba", "abn", "tna"};
  int sz = sizeof(arr) / sizeof(arr[0]);
  vector<string> vec(arr, arr + sz);

  std::cout << "Input:\n";
  Output(vec);

  Solution s;
  vector<string > vecs = s.anagrams(vec);

  std::cout << "Output:\n";
  Output(vecs);

  return 0;

  return 0;
}
