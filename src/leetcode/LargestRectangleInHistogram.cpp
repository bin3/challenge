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
#include <stack>
using namespace std;

class Solution {
public:
    typedef pair<int, int> HeightBegin;
    int largestRectangleArea(vector<int> &height) {
        if (height.size() == 0) return 0;
        stack<HeightBegin> stk;
        int maxa = 0;
        stk.push(HeightBegin(height[0], 0));
        for (size_t i = 1; i < height.size(); ++i) {
            int begin = i;
            while (!stk.empty() && stk.top().first > height[i]) {
                int newa = stk.top().first * (i - stk.top().second);
                if (maxa < newa) maxa = newa;
                begin = stk.top().second;
                stk.pop();
            }
            if (stk.empty() || height[i] != stk.top().first) {
                stk.push(HeightBegin(height[i], begin));
            }
        }
        while (!stk.empty()) {
            int newa = stk.top().first * (height.size() - stk.top().second);
            if (maxa < newa) maxa = newa;
            stk.pop();
        }
        return maxa;
    }
};

int main(int argc, char **argv) {
	std::cout << "------" << argv[0] << "------" << std::endl;
	
  return 0;
}
