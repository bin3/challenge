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

#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
using namespace std;

template<typename Value>
class Trie {
public:
  static const int kCN = 26;
  struct Node {
    char c;
    Node* child[kCN];
    bool final;
    Value val;
    Node(char c) :
        c(c), final(false), val() {
      memset(child, 0, sizeof(child));
    }
  };

  Trie() {
    Clear();
  }
  void Insert(const std::string& s, Value val) {
    Node* p = root_;
    for (std::size_t i = 0; i < s.size(); ++i) {
      if (!Child(p, s[i])) {
        AddChild(p, s[i]);
      }
      p = Child(p, s[i]);
    }
    p->final = true;
    p->val = val;
  }
  bool Find(const char* s, std::size_t n, Value* val) const {
    Node* p = root_;
    for (std::size_t i = 0; i < n; ++i) {
      p = Child(p, s[i]);
      if (!p) return false;
    }
    if (p->final) *val = p->val;
    return p->final;
  }
  bool Find(const std::string& s, int* val) const {
    return Find(s.data(), s.size(), val);
  }
  void Clear() {
    nodes_.clear();
    root_ = NewNode(0);
  }
private:
  std::deque<Node> nodes_;
  Node* root_;

  Node* NewNode(char c) {
    nodes_.push_back(Node(c));
    return &nodes_.back();
  }
  Node* Child(Node* p, char c) const {
    return p->child[c - 'a'];
  }
  Node* AddChild(Node* p, char c) {
    Node* cp = NewNode(c);
    p->child[c - 'a'] = cp;
    return cp;
  }
};

class Solution {
public:
  vector<int> findSubstring(string S, vector<string> &L) {
    if (L.size() == 0 || L[0].size() == 0) return vector<int>();
    Trie<string> trie;
    map<string, int> w2c;
    for (size_t i = 0; i < L.size(); ++i) {
      trie.Insert(L[i], L[i]);
      ++w2c[L[i]];
    }
    size_t n = L[0].size();
    size_t len = n * L.size();

    vector<int> v;
    for (size_t i = 0; i + len <= S.size(); ++i) {
      map<string, int> cw2c;
      string word;
      size_t j = 0;
      for (size_t b = i; j < L.size(); ++j, b += n) {
        if (!trie.Find(S.data() + b, n, &word)) break;
        if (++cw2c[word] > w2c[word]) break;
      }
      if (j == L.size()) v.push_back(i);
    }
    return v;
  }
};

#include "../util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  Solution sol;

  string s = "barfoothefoobarman";
  vector<string> words;
  words.push_back("foo");
  words.push_back("bar");
  Output(s);
  Output(words);
  Output(sol.findSubstring(s, words));

  return 0;
}
