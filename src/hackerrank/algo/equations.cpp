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
 * @date		2013-1-20
 */

#include <stdint.h>
#include <cmath>
#include <iostream>
#include <vector>

class Solver {
public:
  static const uint64_t MOD = 1000007;

  uint64_t solve(uint64_t n) {
    calcPrimes(n);
    std::vector<uint64_t> ev;
    calcExponents(n, ev);
    uint64_t ans = 1;
    for (std::size_t i = 0; i < ev.size(); ++i) {
      ans = ans * (2 * ev[i] + 1) % MOD;
    }
    return ans;
  }
private:
  std::vector<uint64_t> primes_;

  void calcPrimes(uint64_t n) {
    primes_.clear();
    primes_.push_back(2);
    for (uint64_t x = 3; x <= n; ++x) {
      bool is_prime = true;
      uint64_t sq = std::sqrt(x) + 1;
      for (std::size_t i = 0; i < primes_.size() && primes_[i] <= sq; ++i) {
        if (x % primes_[i] == 0) {
          is_prime = false;
          break;
        }
      }
      if (is_prime) {
        primes_.push_back(x);
      }
    }
  }
  void calcExponents(uint64_t n, std::vector<uint64_t>& ev) {
    ev.clear();
    for (std::size_t i = 0; i < primes_.size() && primes_[i] <= n; ++i) {
      uint64_t p = primes_[i];
      int e = 0;
      while (p <= n) {
        e += n / p;
        p *= primes_[i];
      }
      ev.push_back(e);
    }
  }
};

int main(int argc, char **argv) {
	Solver sol;
	
	uint64_t n;
	while (std::cin >> n) {
	  std::cout << sol.solve(n) << std::endl;
	}

  return 0;
}
