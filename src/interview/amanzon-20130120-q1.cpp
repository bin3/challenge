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
 * @date		2013-1-20
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

bool Input(std::vector<int>& vec) {
  std::string line;
  std::getline(std::cin, line);
  line.push_back(',');
  std::stringstream ss(line);

  int x;
  char sep;
  while (ss >> x >> sep) {
    vec.push_back(x);
    if (sep != ',')
      break;
  }
  return true;
}

int Solve(const std::vector<int>& vec) {
  int steps = 0;
  for (std::size_t n = vec.size(), b = 0, e = 0; e < n - 1; ) {
    std::size_t nxte = e;
    for ( ; b <= e; ++b) {
      nxte = std::max(nxte, b + vec[b]);
    }
    ++steps;
    if (nxte <= e) return -1;
    b = e + 1;
    e = nxte;
  }
  return steps;
}

int main(int argc, char **argv) {

  std::vector<int> vec;
  Input(vec);
  std::cout << Solve(vec) << std::endl;

  return 0;
}
