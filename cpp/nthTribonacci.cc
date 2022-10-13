#include <bits/stdc++.h>
/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
class Solution {
 private:
  std::unordered_map<int, int> cache;

 public:
  int tribonacci(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    /* check cache */
    if (cache[n]) return cache[n];
    int result = tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
    cache[n] = result;
    return result;
  }
};
// @lc code=end

/*
 0 1 1 2 4 7 13
 */
