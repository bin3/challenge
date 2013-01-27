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

#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

const char LP = '(';
const char RP = ')';
const char COLON = ':';

std::string Clean(const std::string& s) {
  std::string cs;
  for (std::size_t i = 0; i < s.size(); ++i) {
    switch (s[i]) {
    case LP:
    case RP:
    case COLON:
      cs.push_back(s[i]);
      break;
    }
  }
  return cs;
}

bool BalancedSmileys(const std::string& s) {
  // TODO: check other chars?
  std::string cs = Clean(s);
  int n = cs.size();
  std::vector<std::vector<bool> > d(n + 1, std::vector<bool>(n + 1, false));
  d[0][0] = true;
  for (int i = 0; i < n; ++i) {
    if (cs[i] == COLON) {
      d[i + 1] = d[i];
    } else if (cs[i] == LP) {
      for (int j = i + 1; j >= 0; --j) {
        if (d[i][j]) {
          d[i + 1][j + 1] = true;
          if (i > 0 && cs[i - 1] == COLON) {
            d[i + 1][j] = true;
          }
        }
      }
    } else if (cs[i] == RP) {
      bool ok = false;
      for (int j = i + 1; j >= 0; --j) {
        if (d[i][j]) {
          if (j > 0) {
            ok = true;
            d[i + 1][j - 1] = true;
          }
          if (i > 0 && cs[i - 1] == COLON) {
            ok = true;
            d[i + 1][j] = true;
          }
        }
      }
      if (!ok) return false;
    }
  }
  return d[n][0];
}

int main(int argc, char **argv) {
  const char* OUTPUT[] = {"NO", "YES"};
  int cases = 0;
  std::string s;
  std::cin >> cases;
  std::getline(std::cin, s);
  for (int i = 1; i <= cases; ++i) {
    std::getline(std::cin, s);
    std::cout << "Case #" << i << ": " << OUTPUT[BalancedSmileys(s)] << std::endl;
  }
  return 0;
}
