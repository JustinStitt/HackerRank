#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=2100 lang=cpp
 *
 * [2100] Find Good Days to Rob the Bank
 */

// @lc code=start
class Solution {
 public:
  vector<int> goodDaysToRobBank(vector<int>& security, int time) {
    vector<int> ret;
    const size_t N = security.size();
    if (N <= time * 2) return ret;
    vector<int> prefix_sum(N, 0);
    vector<int> postfix_sum(N, 0);

    /* keeps track of how many nums below it are non-increasing */
    for (int i{1}; i < N; ++i) {
      if (security[i] <= security[i - 1]) {
        prefix_sum[i] = prefix_sum[i - 1] + 1;
      }
    }

    /* keeps track of how many nums above it are non-decreasing */
    for (int i = N - 2; i >= 0; --i) {
      if (security[i] <= security[i + 1]) {
        postfix_sum[i] = postfix_sum[i + 1] + 1;
      }
    }

    for (int i = time; i < N - time; ++i) {
      /* does prefix sum have at least _time_ count? */
      bool pre = prefix_sum[i] >= time;
      bool post = postfix_sum[i] >= time;
      if (pre && post) ret.emplace_back(i);
    }

    return ret;
  }
};
// @lc code=end
