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
  TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
    inorder_ = inorder;
    postorder_ = postorder;
    return buildTree(0, 0, inorder.size());
  }
  vector<int> inorderTraversal(TreeNode *root) {
    path_.clear();
    recursiveInorderTraversal(root);
    return path_;
  }
private:
  vector<int> inorder_;
  vector<int> postorder_;
  vector<int> path_;

  TreeNode* buildTree(size_t ib, size_t pb, size_t n) {
    if (n == 0) return NULL;
    int rootv = postorder_[pb + n - 1];
    TreeNode* node = new TreeNode(rootv);
    size_t i = 0;
    for (i = ib; inorder_[i] != rootv; ++i) {}
    size_t ln = i - ib;
    size_t rn = n - ln - 1;
    node->left = buildTree(ib, pb, ln);
    node->right = buildTree(i + 1, pb + ln, rn);
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

  int inarr[] = {4, 2, 1, 5, 3, 7, 6};
  int insz = sizeof(inarr) / sizeof(inarr[0]);
  vector<int> inorder(inarr, inarr + insz);
  int postarr[] = {4, 2, 5, 7, 6, 3, 1};
  int postsz = sizeof(postarr) / sizeof(postarr[0]);
  vector<int> postorder(postarr, postarr + postsz);

  std::cout << "Input:\n";
  Output(inorder);
  Output(postorder);

  Solution s;
  TreeNode* root = s.buildTree(inorder, postorder);
  vector<int> path = s.inorderTraversal(root);

  std::cout << "Output:\n";
  Output(path);

  return 0;
}
