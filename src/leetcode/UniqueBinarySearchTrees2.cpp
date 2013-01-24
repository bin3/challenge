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

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        std::vector<int> ids(n);
        for (int i = 0; i < n; ++i) ids[i] = i + 1;
        return gen(ids);
    }
private:
    std::vector<TreeNode*> gen(const std::vector<int>& ids) {
        std::vector<TreeNode*> roots;
        for (std::size_t i = 0; i < ids.size(); ++i) {
            std::vector<int> lids(ids.begin(), ids.begin() + i);
            std::vector<int> rids(ids.begin() + i + 1, ids.end());
            std::vector<TreeNode*> lroots = gen(lids);
            std::vector<TreeNode*> rroots = gen(rids);
            for (std::size_t l = 0; l < lroots.size(); ++l) {
                for (std::size_t r = 0; r < rroots.size(); ++r) {
                    TreeNode* root = new TreeNode(ids[i]);
                    root->left = lroots[l];
                    root->right = rroots[r];
                    roots.push_back(root);
                }
            }
        }
        if (roots.empty()) roots.push_back(NULL);
        return roots;
    }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  return 0;
}
