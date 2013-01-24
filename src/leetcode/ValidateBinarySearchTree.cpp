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
 * @date		2013-1-25
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include "util_types.h"

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  bool isValidBST(TreeNode *root) {
    if (!root) return true;
    TreeNode* rmost = NULL;
    return InorderCheck(root, NULL, rmost);
  }
private:
  bool InorderCheck(TreeNode* p, TreeNode* prv, TreeNode*& rmost) {
    if (p->left) {
      if (!InorderCheck(p->left, prv, prv)) return false;
    }
    if (prv && prv->val >= p->val) {
      return false;
    }
    if (p->right) {
      if (!InorderCheck(p->right, p, rmost)) return false;
    } else {
      rmost = p;
    }
    return true;
  }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  return 0;
}
