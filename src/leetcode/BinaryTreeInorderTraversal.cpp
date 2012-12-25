/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-12-14
 */

#include <iostream>
#include <vector>
#include <stack>
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
  vector<int> inorderTraversal(TreeNode *root) {
    path_.clear();
//    recursiveInorderTraversal(root);
    nonrecursiveInorderTraversal(root);
    return path_;
  }
private:
  vector<int> path_;

  void recursiveInorderTraversal(TreeNode *node) {
    if (!node) return;
    recursiveInorderTraversal(node->left);
    path_.push_back(node->val);
    recursiveInorderTraversal(node->right);
  }
  enum State {
    INIT, TRAV
  };
  struct StackNode {
    TreeNode* node;
    State state;
    StackNode(TreeNode* n, State s): node(n), state(s) {}
  };
  void nonrecursiveInorderTraversal(TreeNode* root) {
    if (!root) return;
    std::stack<StackNode> stk;
    stk.push(StackNode(root, INIT));
    while (!stk.empty()) {
      StackNode n = stk.top();
      stk.pop();
      if (n.state == INIT) {
        stk.push(StackNode(n.node, TRAV));
        if (n.node->left) stk.push(StackNode(n.node->left, INIT));
      } else if (n.state == TRAV) {
        path_.push_back(n.node->val);
        if (n.node->right) stk.push(StackNode(n.node->right, INIT));
      }
    }
  }
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
  vector<int> path = s.inorderTraversal(root);

  std::cout << "Output:\n";
  Output(path);

  return 0;
}
