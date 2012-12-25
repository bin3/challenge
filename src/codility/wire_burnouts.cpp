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
 * @date		2012-12-25
 */

#include <cstring>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class DisjointSet {
public:
  DisjointSet(std::size_t n) {
    Init(n);
  }
  void Init(std::size_t n) {
    father_.resize(n);
    for (std::size_t i = 0; i < n; ++i) {
      father_[i] = i;
    }
  }
  bool Union(int a, int b) {
//    std::cout << "a=" << a << ", b=" << b << std::endl;
    int fa = FindFather(a);
    int fb = FindFather(b);
//    std::cout << "fa=" << fa << ", fb=" << fb << std::endl;
    father_[fb] = fa;
    return fa != fb;
  }
  bool Same(int a, int b) {
    return FindFather(a) == FindFather(b);
  }
  std::string ToString() const {
    std::stringstream ss;
    for (std::size_t i = 0; i < father_.size(); ++i) {
      ss << father_[i] << " ";
    }
    ss << "\n";
    return ss.str();
  }
private:
  std::vector<int> father_;
  int FindFather(int x) {
    if (father_[x] != x)
      father_[x] = FindFather(father_[x]);
//    std::cout << "x=" << x << ", father[x]=" << father_[x] << std::endl;
    return father_[x];
  }
};

const int ND = 4;
int xstep[ND] = {0, 1, 0, -1};
int ystep[ND] = {1, 0, -1, 0};

class Graph {
public:
  struct Node {
    Node(): id(-1) {
      memset(e, 1, sizeof(e));
    }
    int id;
    bool e[ND];
  };
  Graph(std::size_t n) {
    Init(n);
  }
  void Init(std::size_t n) {
    n_ = n;
    std::vector<std::vector<Node> >(n, std::vector<Node>(n)).swap(g_);
  }
  void Remove(int x, int y, int c) {
    g_[y][x].e[c] = false;
    int nx = x + (c == 1);
    int ny = y + (c == 0);
    if (nx < n_ && ny < n_) {
      g_[ny][nx].e[c + 2] = false;
    }
  }
  int Id(int x, int y) const {
    return g_[y][x].id;
  }
  void SetId(int x, int y, int id) {
    g_[y][x].id = id;
  }
  bool Linked(int x, int y, int i) {
    return g_[y][x].e[i];
  }
  std::string ToString() const {
    std::stringstream ss;
    for (std::size_t i = 0; i < g_.size(); ++i) {
      for (std::size_t j = 0; j < g_[i].size(); ++j) {
        if (g_[i][j].id == -1) ss << "*";
        else ss << g_[i][j].id;
        ss << (j < g_[i].size() - 1 && (g_[i][j].e[1]) ? "-" : " ");
      }
      ss << "\n";
      for (std::size_t j = 0; j < g_[i].size() && i != g_.size() - 1; ++j) {
        ss << ((g_[i][j].e[0]) ? "|" : " ") << " ";
      }
      ss << "\n";
    }
    return ss.str();
  }

  std::vector<std::vector<Node> > g_;
  int n_;
};

struct QNode {
  QNode(int x, int y): x(x), y(y) {}
  int x;
  int y;
};

int wire_burnouts ( int N,const vector<int> &A,const vector<int> &B,const vector<int> &C ) {
  int M = A.size();

  Graph g(N);

  for (int i = 0; i < M; ++i) {
    g.Remove(A[i], B[i], C[i]);
//    std::cout << "i=" << i + 1  << ", x=" << A[i] << ", y=" << B[i] << ", c=" << C[i] << "\nGraph:\n" << g.ToString() << std::endl;
  }

  // blood flow
  int cnt = 0;
//  std::cout << "cnt=" << cnt << "\nGraph:\n" << g.ToString() << std::endl;
  int id = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (g.Id(i, j) == -1) {
        std::queue<QNode> q;
        id = i * N + j;
        g.SetId(i, j, id);
        q.push(QNode(i, j));
        while (!q.empty()) {
          QNode c = q.front();
          q.pop();
          for (int i = 0; i < ND; ++i) {
            if (!g.Linked(c.x, c.y, i)) continue;
            int nx = c.x + xstep[i];
            int ny = c.y + ystep[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && g.Id(nx, ny) == -1) {
              g.SetId(nx, ny, id);
              q.push(QNode(nx, ny));
            }
          }
        }
        ++cnt;
//        std::cout << "cnt=" << cnt << "\nGraph:\n" << g.ToString() << std::endl;
      }
    }
  }

//  std::cout << "cnt=" << cnt << "\nGraph:\n" << g.ToString() << std::endl;

  // check from last burnout
  DisjointSet st(N * N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      st.Union(g.Id(i, j), i * N + j);
    }
  }
//  std::cout << "st: " << st.ToString() << std::endl;
  int start = 0;
  int end = N * N - 1;
  if (st.Same(start, end)) return -1;

  int i = 0;
  for (i = M - 1; i >= 0; --i) {
    int x = A[i] + (C[i] == 1);
    int y = B[i] + (C[i] == 0);
    int a = A[i] * N + B[i];
    int b = x * N + y;
    if (st.Union(a, b)) {
//      std::cout << "a=" << a << ", b=" << b << ", st: " << st.ToString() << std::endl;
      if (st.Same(start, end)) break;
    }
  }

  return i + 1;
}

#include "../util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

//  int N = 4;
//  int aarr[] = {0, 1, 1, 2, 3, 2, 1, 0, 0};
//  int barr[] = {0, 1, 1, 1, 2, 2, 3, 1, 0};
//  int carr[] = {0, 1, 0, 0, 0, 1, 1, 0, 1};
//  int aarr[] = {0, 1, 2, 3};
//  int barr[] = {1, 1, 1, 1};
//  int carr[] = {1, 1, 1, 0};
  int N = 3;
  int aarr[] = {0, 1, 1, 1, 0, 2, 0, 2, 1, 0, 1, 0};
  int barr[] = {1, 0, 1, 2, 2, 1, 0, 0, 1, 0, 0, 1};
  int carr[] = {1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0};
  vector<int> A;
  vector<int> B;
  vector<int> C;

  int sz = sizeof(aarr) / sizeof(aarr[0]);
  ToVector(aarr, sz, &A);
  ToVector(barr, sz, &B);
  ToVector(carr, sz, &C);

  std::cout << "Input:\n";
  Output(A);
  Output(B);
  Output(C);

  int ans = wire_burnouts(N, A, B, C);

  std::cout << "Output:\n";
  Output(ans);

  return 0;
}
