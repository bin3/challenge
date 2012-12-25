/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-12-14
 */

#include <iostream>
#include <vector>
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
  TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
    preorder_ = preorder;
    inorder_ = inorder;
    return buildTree(0, 0, preorder.size());
  }
  vector<int> inorderTraversal(TreeNode *root) {
    path_.clear();
    recursiveInorderTraversal(root);
    return path_;
  }
private:
  vector<int> preorder_;
  vector<int> inorder_;
  vector<int> path_;

  TreeNode* buildTree(size_t pb, size_t ib, size_t n) {
    if (n == 0) return NULL;
    int rootv = preorder_[pb];
    TreeNode* node = new TreeNode(rootv);
    size_t i = 0;
    for (i = ib; inorder_[i] != rootv; ++i) {}
    size_t ln = i - ib;
    size_t rn = n - ln - 1;
    node->left = buildTree(pb + 1, ib, ln);
    node->right = buildTree(pb + ln + 1, i + 1, rn);
    return node;
  }
  void recursiveInorderTraversal(TreeNode *node) {
    if (!node) return;
    recursiveInorderTraversal(node->left);
    path_.push_back(node->val);
    recursiveInorderTraversal(node->right);
  }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  int prearr[] = {1, 2, 4, 3, 5, 6, 7};
  int presz = sizeof(prearr) / sizeof(prearr[0]);
  vector<int> preorder(prearr, prearr + presz);
  int inarr[] = {4, 2, 1, 5, 3, 7, 6};
  int insz = sizeof(inarr) / sizeof(inarr[0]);
  vector<int> inorder(inarr, inarr + insz);

  std::cout << "Input:\n";
  Output(preorder);
  Output(inorder);

  Solution s;
  TreeNode* root = s.buildTree(preorder, inorder);
  vector<int> path = s.inorderTraversal(root);

  std::cout << "Output:\n";
  Output(path);

  return 0;
}
