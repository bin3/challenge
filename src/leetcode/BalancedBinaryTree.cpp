/*
 Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 @author	Binson Zhang <bin183cs@gmail.com>
 @date		2012-12-14
 */

#include <cstdlib>
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
  struct BalanceResult {
    bool balanced;
    int height;
    BalanceResult(bool b, int h = 0): balanced(b), height(h) {}
  };

  bool isBalanced(TreeNode *root) {
    BalanceResult res = checkBalanced(root);
    return res.balanced;
  }
  BalanceResult checkBalanced(TreeNode *node) {
    if (!node) return BalanceResult(true, 0);
    BalanceResult lres = checkBalanced(node->left);
    if (!lres.balanced) return BalanceResult(false);
    BalanceResult rres = checkBalanced(node->right);
    if (!rres.balanced) return BalanceResult(false);
    if (abs(lres.height - rres.height) > 1) return BalanceResult(false);
    int height = std::max(lres.height, rres.height) + 1;
    return BalanceResult(true, height);
  }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution s;

  TreeNode* root = NULL;
  std::cout << "Output:" << s.isBalanced(root) << std::endl;

  return 0;
}
