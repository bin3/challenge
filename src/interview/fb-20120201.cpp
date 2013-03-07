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
 * @date		2013-2-1
 */

#include <iostream>
/*
Question: Print out a binary tree level-by-level, each level on a separate line. Choose an appropriate representation for the tree. Use the language of your choice.

Example:

Input Tree:
    A
   / \
  B   C
 /   / \
D   E   F

Output:
A
B C
D E F
*/

#include <iostream>
#include <queue>

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char v): val(v), left(NULL), right(NULL) {}
};

struct QNode {
    const TreeNode* tree;
    int level;
    QNode(const TreeNode* t, int l): tree(t), level(l) {}
};

void Print(const TreeNode* tree, std::ostream& os = std::cout) {
    std::queue<QNode> q;
    q.push(QNode(tree, 0));
    int prvlevel = -1;
    while (!q.empty()) {
        QNode cur = q.front();
        q.pop();
        if (prvlevel == cur.tree.level) os << " ";
        else if (prvlevel != -1) os << "\n";
        os << cur.tree.val;
        prvlevel = cur.tree.level;

        int level = cur.level + 1;
        if (cur.tree.left) q.push(QNode(cur.tree.left, level);
        if (cur.tree.right) q.push(QNode(cur.tree.right, level));
    }
    os << "\n";
}

void Print2(TreeNode* tree, std::ostream& os = std::cout) {
    std::queue<TreeNode*> q;
    q.push(tree);
    int i = 0;
    int e = 0;
    int nxte = 1;
    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        os << cur.val;
        if (i++ == e) {
            os << "\n";
            e = nxte;
        }
        else os << " ";

        if (cur.left) {
            q.push(cur.left);
            ++nxte;
        }
        if (cur.right) {
            q.push(cur.right);
            ++nxte;
        }
    }
    os << "\n";
}

int main(int argc, char **argv) {
	std::cout << "------" << argv[0] << "------" << std::endl;
	
  return 0;
}
