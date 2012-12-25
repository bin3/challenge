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
  int maxPathSum(TreeNode *root) {
    if (!root) return 0;
    max_ = root->val;
    maxBranch(root);
    return max_;
  }
private:
  int max_;
  int maxBranch(TreeNode* node) {
    if (!node) return 0;
    int lmax = maxBranch(node->left);
    int rmax = maxBranch(node->right);
    int max = std::max(lmax, rmax) + node->val;
    max_ = std::max(max_, lmax + rmax + node->val);
    max_ = std::max(max_, lmax + node->val);
    max_ = std::max(max_, rmax + node->val);
    max_ = std::max(max_, node->val);
    return std::max(max, node->val);
  }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

//  TreeNode* root = new TreeNode(1);
//  root->right = new TreeNode(2);
//  root->right->left = new TreeNode(3);
//  TreeNode* node = root->right->left;
//  node->left = new TreeNode(4);
//  node->right = new TreeNode(5);
//  node = root->right;
//  node->right = new TreeNode(6);
//  node->right->left = new TreeNode(7);

  TreeNode* root = new TreeNode(-2);
  root->left = new TreeNode(-1);

  Solution s;

  std::cout << "Output:\n" << s.maxPathSum(root) << std::endl;

  return 0;
}
