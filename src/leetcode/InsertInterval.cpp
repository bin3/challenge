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

#include "util_types.h"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> res;
    bool added = false;
    for (size_t i = 0; i < intervals.size(); ++i) {
      int ret = merge(intervals[i], newInterval);
      if (ret < 0) {
        res.push_back(intervals[i]);
        if (i == intervals.size() - 1)
          res.push_back(newInterval);
      } else if (ret == 0) {
        if (i == intervals.size() - 1)
          res.push_back(newInterval);
      } else {
        if (!added) {
          added = true;
          res.push_back(newInterval);
        }
        res.push_back(intervals[i]);
      }
    }
    if (intervals.size() == 0)
      res.push_back(newInterval);
    return res;
  }
private:
  int merge(Interval interval, Interval& newInterval) {
    if (interval.end < newInterval.start)
      return -1;
    if (newInterval.end < interval.start)
      return 1;
    newInterval.start = std::min(interval.start, newInterval.start);
    newInterval.end = std::max(interval.end, newInterval.end);
    return 0;
  }
};




#include "util.h"

int main(int argc, char **argv) {
  std::cout << "------" << argv[0] << "------" << std::endl;
  vector<Interval> intervals;
  intervals.push_back(Interval(1, 2));
  intervals.push_back(Interval(3, 5));
  intervals.push_back(Interval(6, 7));
  intervals.push_back(Interval(8, 10));
  intervals.push_back(Interval(12, 16));
  Interval newInterval(4, 9);

  std::cout << "Input:\n";
  Output(intervals);
  Output(newInterval);

  Solution sol;
  vector<Interval> newIntervals = sol.insert(intervals, newInterval);

  std::cout << "Output:\n";
  Output(newIntervals);

  return 0;
}
