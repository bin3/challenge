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
    int search(int A[], int n, int target) {
        if (A[0] <= A[n-1]) return binary_search(A, n, target);
        int low = 0;
        int high = n;
        while (low < high) {
            int mid = (high - low) / 2 + low;
            if (A[mid] >= A[0]) low = mid + 1;
            else high = mid;
        }
        if (target >= A[0]) return binary_search(A, low, target);
        else {
            int ret = binary_search(A + low, n - low, target);
            if (ret >= 0) ret += low;
            return ret;
        }
    }
    int binary_search(int A[], int n, int target) {
        int low = 0;
        int high = n;
        while (low < high) {
            int mid = (high - low) / 2 + low;
            if (A[mid] == target) return mid;
            if (A[mid] < target) low = mid + 1;
            else high = mid;
        }
        return -1;
    }
};

int main(int argc, char **argv) {
	std::cout << "------" << argv[0] << "------" << std::endl;
	
  return 0;
}
