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
 * @date		2013-1-21
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        sum_ = sum;
        path_.clear();
        paths_.clear();
        if (root) dfs(root, 0);
        return paths_;
    }
private:
    int sum_;
    std::vector<int> path_;
    std::vector<vector<int> > paths_;

    void dfs(TreeNode* p, int sum) {
        sum += p->val;
        path_.push_back(p->val);
        if (!p->left && !p->right && sum == sum_) paths_.push_back(path_);
        if (p->left) dfs(p->left, sum);
        if (p->right) dfs(p->right, sum);
        path_.pop_back();
    }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  return 0;
}
