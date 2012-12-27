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
 * @date		2012-12-27
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) :
      val(x), next(NULL) {
  }
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode* head = NULL;
    ListNode* tail = NULL;
    bool carry = false;
    while (l1 || l2) {
      int sum = val(l1) + val(l2) + carry;
      carry = sum / 10;
      sum = sum % 10;
      ListNode* cur = new ListNode(sum);
      if (tail == NULL) {
        head = cur;
      } else {
        tail->next = cur;
      }
      tail = cur;
      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
    }
    if (carry) {
      tail->next = new ListNode(1);
    }
    return head;
  }
private:
  int val(ListNode* p) {
    if (p)
      return p->val;
    return 0;
  }
};

#include "util.h"

void Output(ListNode* p, std::ostream& os = std::cout) {
  while (p) {
    os << p->val << "->";
    p = p->next;
  }
  os << "\n";
}

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  ListNode* a = new ListNode(6);
  ListNode* b = new ListNode(9);

  std::cout << "Input:\n";
  Output(a);
  Output(b);

  Solution s;
  ListNode* res = s.addTwoNumbers(a, b);

  std::cout << "Output:\n";
  Output(res);

  return 0;
}
