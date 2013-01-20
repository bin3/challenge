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
 * @date		2013-1-7
 */

#ifndef UTIL_TYPES_H_
#define UTIL_TYPES_H_

#include <iostream>

struct Interval {
  int start;
  int end;
  Interval() :
      start(0), end(0) {
  }
  Interval(int s, int e) :
      start(s), end(e) {
  }
};


// Definition for binary tree with next pointer.
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) :
      val(x), left(NULL), right(NULL), next(NULL) {
  }
};

std::ostream& operator<<(std::ostream& os, const Interval& interval) {
  os << "[" << interval.start << ", " << interval.end << "]";
  return os;
}

#endif /* UTIL_TYPES_H_ */
