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
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (word.size() == 0) return true;
        if (board.size() == 0 || board[0].size() == 0) return false;
        board_ = &board;
        nr_ = board.size();
        nc_ = board[0].size();
        visited_ = vector<vector<bool> >(nr_, vector<bool>(nc_, false));
        word_ = word;
        return dfs();
    }
private:
    vector<vector<char> >* board_;
    vector<vector<bool> > visited_;
    int nr_;
    int nc_;
    string word_;
    bool dfs() {
        for (int r = 0; r < nr_; ++r) {
            for (int c = 0; c < nc_; ++c) {
                if (dfs(r, c, 0)) return true;
            }
        }
        return false;
    }
    bool dfs(int r, int c, int k) {
        static int kRex[] = {-1, 0, 1, 0};
        static int kCex[] = {0, 1, 0, -1};

        if (r < 0 || r >= nr_ || c < 0 || c >= nc_) return false;
        if (visited_[r][c]) return false;
        if ((*board_)[r][c] != word_[k]) return false;
        if (++k == word_.size()) return true;
        visited_[r][c] = true;
        for (int i = 0; i < 4; ++i) {
            if (dfs(r + kRex[i], c + kCex[i], k)) return true;
        }
        visited_[r][c] = false;
        return false;
    }
};

int main(int argc, char **argv) {
	std::cout << "------" << argv[0] << "------" << std::endl;
	
  return 0;
}
