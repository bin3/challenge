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
 * @date		2013-3-9
 */

#include <iostream>
#include <map>
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
    ListNode *deleteDuplicates(ListNode *head) {
        std::map<int, int> val2cnt;
        ListNode* prv = NULL;
        ListNode* p = head;
        while (p) {
            ++val2cnt[p->val];
            p = p->next;
        }
        p = head;
        head = NULL;
        while (p) {
            if (val2cnt[p->val] > 1) {
                if (prv) prv->next = p->next;
            }
            else {
                if (!prv) head = p;
                prv = p;
            }
            p = p->next;
        }
        return head;
    }
};

int main(int argc, char **argv) {
	std::cout << "------" << argv[0] << "------" << std::endl;
	
  return 0;
}
