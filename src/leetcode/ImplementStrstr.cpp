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
 * @date		2012-12-29
 */

#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
  char *strStr0(char *haystack, char *needle) {
    if (*needle == '\0')
      return haystack;
    char* ph0 = haystack;
    const char* ph = NULL;
    const char* pn = NULL;
    while (*ph0) {
      for (ph = ph0, pn = needle; *ph && *pn && (*ph == *pn); ++ph, ++pn) {
      }
      if (*pn == '\0')
        return ph0;
      ++ph0;
    }
    return NULL;
  }
  char *strStr(char *haystack, char *needle) {
    static const int NOPOS = -1;
    int nlen = std::strlen(needle);
    if (nlen == 0)
      return haystack;

    jump_.resize(nlen, 0);
    for (int i = 2; i < nlen; ++i) {
      int j = jump_[i - 1];
      while (needle[j] != needle[i - 1] && j != 0) {
        j = jump_[j];
      }
      if (needle[j] == needle[i - 1]) jump_[i] = j + 1;
      else jump_[i] = 0;
    }
    int i = 0;
    for (; *haystack; ++haystack) {
      if (i == nlen) return haystack - nlen;
      while (needle[i] != *haystack && i != 0) {
        i = jump_[i];
      }
      if (!(i == 0 && needle[i] != *haystack)) ++i;
    }
    if (i == nlen)
      return haystack - nlen;
    return NULL;
  }
private:
  std::vector<int> jump_;
};

#include "util.h"

#include "util.h"
#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  char haystack[] = "mississippi";
  char needle[] = "issip";

  std::cout << "Input:\n";
  Output(haystack);
  Output(needle);

  Solution sol;

  std::cout << "Output:\n";
  Output(sol.strStr(haystack, needle));

  return 0;
}
