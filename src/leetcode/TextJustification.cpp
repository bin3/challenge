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
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> texts;
        vector<size_t> firsts;
        for (size_t i = 0, len = 0, cnt = 0; i < words.size(); ) {
            if (len == 0) firsts.push_back(i);
            if (len + words[i].size() + cnt > L) {
                len = 0;
                cnt = 0;
            } else {
                len += words[i].size();
                ++cnt;
                ++i;
            }
        }

        for (size_t i = 0; i < firsts.size(); ++i) {
            size_t begin = firsts[i];
            size_t end = (i == firsts.size() - 1) ? words.size() : firsts[i+1];
            size_t cnt = end - begin;
            size_t len = 0;
            for (size_t j = begin; j < end; ++j) {
                len += words[j].size();
            }
            string text(L, ' ');
            size_t spaces = L -len;
            if (cnt > 1) {
                size_t perspaces = spaces / (cnt - 1);
                size_t plusend = spaces % (cnt - 1);
                if (i == firsts.size() - 1) {
                    perspaces = 1;
                    plusend = 0;
                }
                for (size_t j = begin, p = 0; j < end; ++j) {
                    text.replace(p, words[j].size(), words[j]);
                    p += words[j].size() + perspaces;
                    if (j - begin < plusend) ++p;
                }
            } else {
                text.replace(0, words[begin].size(), words[begin]);
            }
            texts.push_back(text);
        }

        return texts;
    }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  return 0;
}
