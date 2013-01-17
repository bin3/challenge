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
 * @date		2013-1-8
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
      int n1 = s1.size();
      int n2 = s2.size();
      int n3 = s3.size();
      if (n1 + n2 != n3) return false;
      vector<vector<bool> > d(n1 + 1, vector<bool>(n2 + 1, false));
      d[0][0] = true;
      for (int i = 0; i < n3; ++i) {
          for (int j = std::max(0, i - n2); j <= i && j <= n1; ++j) {
            if (d[j][i - j]) {
              if (j < n1 && s1[j] == s3[i]) {
                d[j + 1][i - j] = true;
              }
              if (i - j < n2 && s2[i - j] == s3[i]) {
                d[j][i - j + 1] = true;
              }
            }
          }
      }
      return d[n1][n2];
  }
};

#include "util.h"

void Solve(const std::string& s1, const std::string& s2, const std::string& s3) {
  Solution sol;

  Output("Input:");
  Output(s1);
  Output(s2);
  Output(s3);

  Output("Output:");
  Output(sol.isInterleave(s1, s2, s3));

}

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;


//  std::string s1 = "aabcc";
//  std::string s2 = "dbbca";
//  std::string s3 = "aadbbcbcac";
//  std::string s3 = "aadbbbaccc";

//  std::string s1 = "";
//  std::string s2 = "b";
//  std::string s3 = "b";

  std::string s1 = "aabd";
  std::string s2 = "abdc";
  std::string s3 = "aabdbadc";

  Solve("", "", "");
  Solve("cbcccbabbccbbcccbbbcabbbabcababbbbbbaccaccbabbaacbaabbbc",
      "abcbbcaababccacbaaaccbabaabbaaabcbababbcccbbabbbcbbb",
      "abcbcccbacbbbbccbcbcacacbbbbacabbbabbcacbcaabcbaaacbcbbbabbbaacacbbaaaabccbcbaabbbaaabbcccbcbabababbbcbbbcbb");

  return 0;
}
