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
#include <vector>
#include <algorithm>
using namespace std;

#include "util_types.h"

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        vector<TreeLinkNode*> l;
        vector<TreeLinkNode*> r;
        conn(root, l, r);
        for (size_t i = 0; i < r.size(); ++i) {
            r[i]->next = NULL;
        }
    }
private:
    void conn(TreeLinkNode* p, vector<TreeLinkNode*>& l, vector<TreeLinkNode*>& r) {
        if (!p) return;
        if (p->left && p->right) {
            vector<TreeLinkNode*> mr;
            vector<TreeLinkNode*> ml;
            conn(p->left, l, mr);
            conn(p->right, ml, r);
            for (size_t i = 0; i < mr.size() && i < ml.size(); ++i) {
                mr[i]->next = ml[i];
            }

        }
        l.push_back(p);
        r.push_back(p);
    }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  return 0;
}
