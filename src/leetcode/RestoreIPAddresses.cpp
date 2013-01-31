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
 * @date		2013-1-31
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        s_ = s;
        ips_.clear();
        search("", 0, 1, 0);
        return ips_;
    }
private:
    string s_;
    vector<string> ips_;

    void search(const std::string& ip, std::size_t i, std::size_t segs, int val) {
        if (i == s_.size()) {
            if (segs == 4) ips_.push_back(ip);
            return;
        }

        int newval = val * 10 + (s_[i] - '0');
        if (newval <= 255 && !(i > 0 && val == 0)) {
            std::string newip = ip;
            newip.push_back(s_[i]);
            search(newip, i + 1, segs, newval);
        }

        if (i > 0 && segs < 4) {
            int newval = s_[i] - '0';
            std::string newip = ip;
            newip.push_back('.');
            newip.push_back(s_[i]);
            search(newip, i + 1, segs + 1, newval);
        }
    }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  std::string s = "010010";

  std::cout << "Input:\n";
  Output(s);

  std::cout << "Output:\n";
  Output(sol.restoreIpAddresses(s));

  return 0;
}
