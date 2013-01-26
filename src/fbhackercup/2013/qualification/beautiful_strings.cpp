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

int BeautifulStrings(const std::string& s) {
  std::map<int, int> ch2cnt;
  for (std::size_t i = 0; i < s.length(); ++i) {
    if (std::isalpha(s[i])) {
      int c = s[i];
      if (std::isupper(s[i])) c = std::tolower(s[i]);
      ch2cnt[c]++;
    }
  }
  std::vector<std::size_t> cnts;
  for (std::map<int, int>::const_iterator i = ch2cnt.begin();
      i != ch2cnt.end(); ++i) {
    cnts.push_back(i->second);
  }
  std::sort(cnts.begin(), cnts.end(), std::greater<int>());
  int score = 0;
  for (std::size_t i = 0; i < cnts.size(); ++i) {
    score += cnts[i] * (26 - i);
  }
  return score;
}

int main(int argc, char **argv) {
  int cases = 0;
  std::string s;
  std::cin >> cases;
  std::getline(std::cin, s);
  for (int i = 1; i <= cases; ++i) {
    std::getline(std::cin, s);
    std::cout << "Case #" << i << ": " << BeautifulStrings(s) << std::endl;
  }
	
  return 0;
}
