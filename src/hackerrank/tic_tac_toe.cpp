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
 * @date		2013-1-9
 */

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <bitset>
#include <numeric>
#include <algorithm>
using namespace std;

const int N = 3;
const char X = 'X';
const char O = 'O';
const char S = '_';

bool canWin(char player, const vector<string>& ar, int r, int c) {
  int i = 0;

  for (i = 0; i < N && (ar[r][i] == player); ++i) {
  }
  if (i == N)
    return true;
  for (i = 0; i < N && (ar[i][c] == player); ++i) {
  }
  if (i == N)
    return true;

  if (r == c) {
    for (i = 0; i < N && (ar[i][i] == player); ++i) {
    }
    if (i == N)
      return true;
  }
  if (r + c == N) {
    for (i = 0; i < N && (ar[i][N - i] == player); ++i) {
    }
    if (i == N)
      return true;
  }

  return false;
}

bool play(char player, vector<string>& ar, int r, int c) {
  if (ar[r][c] != S)
    return false;
  char opp = (player == X ? O : X);
  ar[r][c] = player;
  bool win = true;
  if (!canWin(player, ar, r, c)) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (ar[i][j] == S) {
          if (play(opp, ar, i, j)) {
            win = false;
            i = N;
            break;
          }
        }
      }
    }
  }
  ar[r][c] = S;
  return win;
}

double winRate(char player, vector<string>& ar, int r, int c) {
  if (ar[r][c] != S)
    return 0;
  char opp = (player == X ? O : X);
  ar[r][c] = player;
  int total = 0;
  int cnt = 0;
  double win_rate = 1.0;
  if (!canWin(player, ar, r, c)) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (ar[i][j] == S) {
          ++total;
          if (!play(opp, ar, i, j))
            ++cnt;
        }
      }
    }
  }
  if (total > 0) {
    win_rate = (double) cnt / total;
  } else {
    win_rate = 0.5;
  }
  ar[r][c] = S;
  return win_rate;
}

void output(int r, int c) {
  printf("%d %d\n", r, c);
}

/* Complete the function below to print 2 integers separated by a single space which will be your next move
 */
void nextMove(char player, vector<string> board) {
  // choose the position if it can absolutely win
  for (int r = 0; r < N; ++r) {
    for (int c = 0; c < N; ++c) {
      if (play(player, board, r, c)) {
        output(r, c);
        return;
      }
    }
  }

  // choose a position with the highest win rate
  double max_wrate = 0;
  int wr = 0;
  int wc = 0;
  for (int r = 0; r < N; ++r) {
    for (int c = 0; c < N; ++c) {
      double wrate = winRate(player, board, r, c);
      if (max_wrate < wrate) {
        max_wrate = wrate;
        wr = r;
        wc = c;
      }
    }
  }
  output(wr, wc);
}

int main() {

  char player;
  vector<string> board;

  //If player is X, I'm the first player.
  //If player is O, I'm the second player.
//  cin >> player;

  //Read the board now. The board is a 3x3 array filled with X, O or _.
//  for (int i = 0; i < 3; i++) {
//    string s;
//    cin >> s;
//    board.push_back(s);
//  }

  player = 'X';
  board.push_back("O_O");
  board.push_back("X__");
  board.push_back("X__");

  nextMove(player, board);

  return 0;
}
