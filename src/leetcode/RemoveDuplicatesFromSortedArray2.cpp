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

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) return n;
        int k = 1;
        for (int i = 1, cnt = 1; i < n; ++i) {
            if (A[i] == A[k-1]) {
                ++cnt;
                if (cnt <= 2) {
                    A[k++] = A[i];
                }
            } else {
                A[k++] = A[i];
                cnt = 1;
            }
        }
        return k;
    }
};

int main(int argc, char **argv) {
	std::cout << "------" << argv[0] << "------" << std::endl;
	
  return 0;
}
