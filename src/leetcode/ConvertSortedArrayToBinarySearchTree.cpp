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
#include <algorithm>
using namespace std;

#include "tree_node.h"

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return build(num, 0, (int)num.size() - 1);
    }
private:
    TreeNode *build(const vector<int>& num, int b, int e) {
        if (b > e) return NULL;
        if (b == e) return new TreeNode(num[b]);
        int m = b + (e - b + 1) / 2;
        TreeNode* p = new TreeNode(num[m]);
        p->left = build(num, b, m - 1);
        p->right = build(num, m + 1, e);
        return p;
    }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  int n = 13;
  vector<int> vec;
  for (int i = 0; i < n; ++i) {
    vec.push_back(i);
  }

  std::cout << "Input:\n";
  Output(vec);

  Solution s;
  TreeNode* root = s.sortedArrayToBST(vec);

  std::cout << "Output:\n";
  OutputTree(root);

  return 0;
}
