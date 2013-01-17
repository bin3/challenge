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

//#define DEBUG_MODE

#ifdef DEBUG_MODE
#define DLOG(x) std::cout << x << std::endl;
#else
#define DLOG(x) ;
#endif

const int N = 3;
const char X = 'X';
const char O = 'O';
const char S = '_';

void outputBoard(char player, const vector<string>& board, int r, int c) {
  DLOG("---------------------------");
  DLOG("player=" << player << ", r=" << r << ", c=" << c);
  for (int i = 0; i < N; ++i) {
    DLOG(board[i]);
  }
}

char opponent(char player) {
  return (player == X ? O : X);
}

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
  if (r + c == N - 1) {
    for (i = 0; i < N && (ar[i][N - 1 - i] == player); ++i) {
    }
    if (i == N)
      return true;
  }

  return false;
}

bool play(char player, vector<string>& ar, int r, int c) {
  if (ar[r][c] != S)
    return false;
  char opp = opponent(player);
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
  outputBoard(player, ar, r, c);
  DLOG("win=" << win);
  ar[r][c] = S;
  return win;
}

double winRate(char player, vector<string>& ar, int r, int c) {
  if (ar[r][c] != S)
    return 0;
  char opp = opponent(player);
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
  std::cout << r << " " << c << std::endl;
}

/* Complete the function below to print 2 integers separated by a single space which will be your next move
 */
void nextMove(char player, vector<string> board) {
  outputBoard(player, board, -1, -1);
  // choose the position if it can absolutely win
  for (int r = 0; r < N; ++r) {
    for (int c = 0; c < N; ++c) {
      if (play(player, board, r, c)) {
        DLOG("[win]"); // debug
        output(r, c);
        return;
      }
    }
  }

  // choose the position if the opponent can win directly
  char opp = opponent(player);
  for (int r = 0; r < N; ++r) {
    for (int c = 0; c < N; ++c) {
      if (board[r][c] == S) {
        board[r][c] = opp;
        if (canWin(opp, board, r, c)) {
          DLOG("[hit opponent]"); // debug
          output(r, c);
          return;
        }
        board[r][c] = opp;
      }
    }
  }

  // choose a position with the highest win rate
  double max_wrate = 0;
  int wr = 0;
  int wc = 0;
  for (int r = 0; r < N; ++r) {
    for (int c = 0; c < N; ++c) {
      if (board[r][c] == S) {
        double wrate = winRate(player, board, r, c);
        if (max_wrate < wrate) {
          max_wrate = wrate;
          wr = r;
          wc = c;
        }
        DLOG(r << " " << c << " " << wrate);  // debug
      }
    }
  }
  DLOG("[max_wrate] " << wr << " " << wc << " " << max_wrate);  // debug
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

//  player = 'X';
  player = 'O';
  board.push_back("XXO");
  board.push_back("_O_ ");
  board.push_back("X__");

  nextMove(player, board);

  return 0;
}
