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
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<vector<int> > mat(n, vector<int>(n));
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                cin >> mat[r][c];
            }
        }
        vector<vector<vector<int> > > sum(n, vector<vector<int> >(n, vector<int>(n, 0)));
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                sum[r][c][0] = mat[r][c];
                for (int k = 1; k <= c; ++k) {
                    sum[r][c][k] = sum[r][c-1][k-1] + mat[r][c];
                }
            }
        }
        int maxsum = mat[0][0];
        for (int c = 0; c < n; ++c) {
            for (int k = c; k >= 0; --k) {
                int cursum = 0;
                for (int r = 0; r < n; ++r) {
                    cursum += sum[r][c][k];
                    if (maxsum < cursum) maxsum = cursum;
                    if (cursum < 0) cursum = 0;
                }
            }
        }
        cout << maxsum << endl;
    }
    return 0;
}
