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
#include <queue>
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
    typedef std::pair<TreeLinkNode*, int> Qnode;

    void connect(TreeLinkNode *root) {
      static const int ROOT_DEPTH = 0;
      if (!root) return;
      Qnode prv = Qnode(root, ROOT_DEPTH);
      std::queue<Qnode> q;
      q.push(prv);
      while (!q.empty()) {
        Qnode cur = q.front();
        q.pop();
        if (cur.second != prv.second) {
          prv.first->next = NULL;
        } else {
          prv.first->next = cur.first;
        }
        if (cur.first->left) q.push(Qnode(cur.first->left, cur.second + 1));
        if (cur.first->right) q.push(Qnode(cur.first->right, cur.second + 1));
        prv = cur;
      }
      prv.first->next = NULL;
    }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  return 0;
}
