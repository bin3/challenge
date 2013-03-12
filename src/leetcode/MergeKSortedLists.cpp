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
 * @date		2013-3-12
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    struct ListNodeCmp {
        bool operator()(const ListNode* lhs, const ListNode* rhs) const {
            return lhs->val > rhs->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        std::priority_queue<ListNode*, vector<ListNode*>, ListNodeCmp> q;
        for (size_t i = 0; i < lists.size(); ++i) {
            if (lists[i]) {
                q.push(lists[i]);
            }
        }
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while (!q.empty()) {
            ListNode* top = q.top();
            q.pop();
            if (tail) tail->next = top;
            else head = top;
            tail = top;
            if (top->next) q.push(top->next);
        }
        return head;
    }
};

#include "../util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  return 0;
}
