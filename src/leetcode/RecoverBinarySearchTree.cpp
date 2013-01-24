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
 * @date		2013-1-23
 */

#include <iostream>
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
  void recoverTree(TreeNode *root) {
    if (!root) return;
    path_.clear();
    Inorder(root);
    TreeNode* h = FindHigher(path_);
    TreeNode* l = FindLower(path_);
    if (h && l) {
      std::swap(h->val, l->val);
    }
  }
private:
  typedef std::pair<int, TreeNode*> ValNode;
  std::vector<ValNode> path_;
  void Inorder(TreeNode* p) {
    if (p->left) Inorder(p->left);
    path_.push_back(ValNode(p->val, p));
    if (p->right) Inorder(p->right);
  }
  TreeNode* FindHigher(std::vector<ValNode>& path) {
    if (path.size() <= 1) return NULL;
    std::size_t n = path.size();
    for (std::size_t i = 0; i < n - 1; ++i) {
        if (path[i].first > path[i+1].first)
          return path[i].second;
    }
    return NULL;
  }
  TreeNode* FindLower(std::vector<ValNode>& path) {
    if (path.size() <= 1) return NULL;
    std::size_t n = path.size();
    for (int i = n - 1; i > 0; --i) {
        if (path[i].first < path[i-1].first)
          return path[i].second;
    }
    return NULL;
  }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  return 0;
}
