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
 * @date		2013-3-10
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../leetcode/util_types.h"
using namespace std;

ListNode* ReverseList(ListNode* head) {
  ListNode* prv = NULL;
  ListNode* cur = head;
  while (cur) {
    ListNode* nxt = cur->next;
    cur->next = prv;
    prv = cur;
    cur = nxt;
  }
  return prv;
}

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  for (int n = 0; n <= 5; ++n) {
    ListNode* head = NULL;
    ListNode* p = head;
    for (int i = 0; i < n; ++i) {
      if (p) {
        p->next = new ListNode(i);
        p = p->next;
      } else {
        p = new ListNode(i);
        head = p;
      }
    }

    std::cout << "Input:\n";
    Output(head);

    std::cout << "Output:\n";
    Output(ReverseList(head));
    std::cout << "\n";
  }

  return 0;
}
