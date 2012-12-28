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

#ifndef TREE_NODE_H_
#define TREE_NODE_H_

#include <iostream>
#include <string>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class TreePrinter {
public:
  void Print(const TreeNode* root, std::ostream& os = std::cout) {
    if (!root) return;
    std::queue<QNode> q;
    q.push(QNode(root, 0));
    while (!q.empty()) {
      QNode c = q.front();
      q.pop();
      if (c.p->left) q.push(QNode(c.p->left, c.lev + 1));
      if (c.p->right) q.push(QNode(c.p->right, c.lev + 1));
      os << "[" << c.lev << "] " << c.p << "-" << c.p->val << ": " << c.p->left << ", " << c.p->right << "\n";
    }
  }
private:
  struct QNode {
    QNode(const TreeNode* p, int lev): p(p), lev(lev) {}
    const TreeNode* p;
    int lev;
  };
};

inline void OutputTree(const TreeNode* root,  std::ostream& os = std::cout) {
  TreePrinter printer;
  printer.Print(root, os);
}

#endif /* TREE_NODE_H_ */
