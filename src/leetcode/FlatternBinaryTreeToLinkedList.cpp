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

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "tree_node.h"

class Solution {
public:
    void flatten(TreeNode *root) {
        dfs(root);
    }
private:
    TreeNode* dfs(TreeNode *p) {
        if (!p) return NULL;
        TreeNode* left = p->left;
        TreeNode* right = p->right;
        TreeNode* tail = NULL;
        p->left = NULL;
        if (left) {
            tail = dfs(left);
            p->right = left;
        } else {
            tail = p;
        }
        if (right) {
            tail->right = right;
            return dfs(right);
        } else {
            return tail;
        }
    }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(3);

  std::cout << "Input:\n";
  OutputTree(root);

  Solution sol;
  sol.flatten(root);

  std::cout << "Output:\n";
  OutputTree(root);

  return 0;
}
