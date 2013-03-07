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
 * @date		2013-3-7
 */

#include <iostream>
#include <string>
#include <vector>
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
    struct List {
        ListNode* head;
        ListNode* tail;
        List(): head(NULL), tail(NULL) {}
        void add(ListNode* node) {
            if (!head) head = node;
            if (tail) tail->next = node;
            tail = node;
            tail->next = NULL;
        }
        void cat(List& lis) {
            if (head) {
                if (lis.head) {
                    tail->next = lis.head;
                    tail = lis.tail;
                }
            } else {
                *this = lis;
            }
        }
    };
    ListNode *partition(ListNode *head, int x) {
        List small;
        List big;
        ListNode* p = head;
        while (p) {
            ListNode* next = p->next;
            if (p->val < x) small.add(p);
            else big.add(p);
            p = next;
        }
        small.cat(big);
        return small.head;
    }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  return 0;
}
