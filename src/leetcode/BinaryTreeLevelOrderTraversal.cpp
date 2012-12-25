/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-12-14
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int> > vecs;
    if (!root) return vecs;
    std::queue<QNode> q;
    q.push(QNode(root, 0));
    while (!q.empty()) {
      QNode n = q.front();
      q.pop();
      if (n.level >= vecs.size()) {
        vecs.push_back(vector<int>(1, n.node->val));
      } else {
        vecs[n.level].push_back(n.node->val);
      }
      if (n.node->left) q.push(QNode(n.node->left, n.level + 1));
      if (n.node->right) q.push(QNode(n.node->right, n.level + 1));
    }
    return vecs;
  }
private:
  struct QNode {
    TreeNode* node;
    int level;
    QNode(TreeNode* n, int l): node(n), level(l) {}
  };
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);
  TreeNode* node = root->right->left;
  node->left = new TreeNode(4);
  node->right = new TreeNode(5);
  node = root->right;
  node->right = new TreeNode(6);
  node->right->left = new TreeNode(7);

  Solution s;
  vector<vector<int> > vecs = s.levelOrder(root);

  std::cout << "Output:\n";
  Output(vecs);

  return 0;
}
