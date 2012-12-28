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

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "list_node.h"
#include "tree_node.h"

class Solution {
public:
  TreeNode *sortedListToBST(ListNode* head){
    int n = 0;
    for (ListNode* p = head; p; p = p->next, ++n) {}
    p_ = head;
    return build(0, n - 1);
  }
private:
  TreeNode *build(int b, int e) {
    if (b > e) return NULL;
    if (b == e) return new TreeNode(GetValAndForward());
    int m = b + (e - b + 1) / 2;
    TreeNode* p = new TreeNode(-1);
    p->left = build(b, m - 1);
    p->val = GetValAndForward();
    p->right = build(m + 1, e);
    return p;
  }
  int GetValAndForward() {
    int val = p_->val;
    p_ = p_->next;
    return val;
  }
  ListNode* p_;
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  int n = 13;
  ListNode* head = NULL;
  ListNode* tail = NULL;
  for (int i = 0; i < n; ++i) {
    ListNode* cur = new ListNode(i);
    if (!head) head = cur;
    if (tail) tail->next = cur;
    tail = cur;
  }

  std::cout << "Input:\n";
  Output(head);

  Solution s;
  TreeNode* root = s.sortedListToBST(head);

  std::cout << "Output:\n";
  OutputTree(root);

  return 0;
}
