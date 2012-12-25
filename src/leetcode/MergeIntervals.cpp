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
 * @date		2012-12-24
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

ostream& operator<<(ostream& os, const Interval& interval) {
  os << "[" << interval.start << ", " << interval.end << "]";
  return os;
}

struct IntervalCmp {
  bool operator()(const Interval& rhs, const Interval& lhs) const {
    if (rhs.start != lhs.start)
      return rhs.start < lhs.start;
    return rhs.end < lhs.end;
  }
};

class Solution {
public:
  vector<Interval> merge(vector<Interval> &intervals) {
    if (intervals.size() == 0) return vector<Interval>();

    IntervalCmp cmp;
    std::sort(intervals.begin(), intervals.end(), cmp);

    vector<Interval> sintervals;
    for (size_t i = 0; i < intervals.size(); ) {
      int start = intervals[i].start;
      int end = intervals[i].end;
      ++i;
      while (i < intervals.size() && intervals[i].start <= end) {
        end = std::max(end, intervals[i].end);
        ++i;
      }
      sintervals.push_back(Interval(start, end));
    }
    return sintervals;
  }
};

#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;

  vector<Interval> intervals;
  intervals.push_back(Interval(1, 3));
  intervals.push_back(Interval(2, 6));
  intervals.push_back(Interval(8, 10));
  intervals.push_back(Interval(15, 18));

  std::cout << "Input:\n";
  Output(intervals);

  Solution s;
  vector<Interval> sintervals = s.merge(intervals);

  std::cout << "Output:\n";
  Output(sintervals);

  return 0;
}
