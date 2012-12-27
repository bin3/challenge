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

#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int CN = 26;

class Trie {
public:
    struct Node {
        Node(char lab = 0): label(lab), final(false) {
            memset(child, 0, sizeof(child));
        }
        char label;
        bool final;
        Node* child[CN];
    };
    Trie(): root_(new Node()) {}
    ~Trie() {
        // TODO: delete
    }
    void Insert(const string& s) {
        if (s.size() == 0) return;
        Node* cur = root_;
        for (size_t i = 0; i < s.size(); ++i) {
            cur = FindOrAdd(cur, s[i]);
        }
        cur->final = true;
    }
    bool Match(const string& s) {
        Node* cur = root_;
        for (size_t i = 0; i < s.size(); ++i) {
            cur = Find(cur, s[i]);
            if (!cur) return false;
        }
        return cur->final;
    }
private:
    Node* root_;

    Node* FindOrAdd(Node* parent, char label) {
        if (!parent->child[label - 'a']) {
            parent->child[label - 'a'] = new Node(label);
        }
        return parent->child[label - 'a'];
    }
    Node* Find(Node* parent, char label) {
        return parent->child[label - 'a'];
    }
};

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        Trie trie;
        for (size_t i = 0; i < strs.size(); ++i) {
            trie.Insert(strs[i]);
        }
        vector<string> res;
        for (size_t i = 0; i < strs.size(); ++i) {
            string rs = strs[i];
            std::reverse(rs.begin(), rs.end());
            if (trie.Match(rs)) res.push_back(strs[i]);
        }
        return res;
    }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  string arr[] = {"ant", "tan", "nba", "abn", "tna"};
  int sz = sizeof(arr) / sizeof(arr[0]);
  vector<string> vec(arr, arr + sz);

  std::cout << "Input:\n";
  Output(vec);

  Solution s;
  vector<string > vecs = s.anagrams(vec);

  std::cout << "Output:\n";
  Output(vecs);

  return 0;
}
