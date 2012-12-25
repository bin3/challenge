/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-12-13
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
      if (strs.size() == 0) return "";

      string cp = strs[0];
      for (size_t i = 1; i < strs.size(); ++i) {
        cp = longestCommonPrefix(cp, strs[i]);
      }
      return cp;
    }
private:
    static string longestCommonPrefix(const string& a, const string& b) {
      string cp;
      for (size_t i = 0; i < a.size() && i < b.size() && a[i] == b[i]; ++i) {
        cp.push_back(a[i]);
      }
      return cp;
    }
};

#include "util.h"

int main(int argc, char **argv) {
	std::cout << "------" << argv[0] << "------" << std::endl;
	
  string arr[] = { "abc", "abcd", "ab"};
  int sz = sizeof(arr) / sizeof(arr[0]);
  vector<string> vec(arr, arr + sz);
  int target = 0;

  std::cout << "Input:\n";
  Output(vec);

  Solution s;

  std::cout << "Output:\n";
  std::cout << s.longestCommonPrefix(vec) << std::endl;

  return 0;
}
