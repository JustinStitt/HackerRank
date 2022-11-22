#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2305 lang=cpp
 *
 * [2305] Fair Distribution of Cookies
 */

// @lc code=start
class Solution {
 public:
  void solve(int idx, int& ans, vector<int>& sums, const vector<int>& cookies,
             int k) {
    int n = cookies.size();
    // base case
    if (idx >= n) {  // no more cookies to give to kids
      // find kid with most cookies
      int most = *max_element(begin(sums), end(sums));
      ans = min(ans, most);
      return;
    }

    // otherwise simulate giving cookie to kid
    for (int i{}; i < k; ++i) {
      sums[i] += cookies[idx];
      solve(idx + 1, ans, sums, cookies, k);
      sums[i] -= cookies[idx];  // backtracking dfs
    }
  }

  int distributeCookies(vector<int>& cookies, int k) {
    int ans = INT_MAX;
    vector<int> sums(k, 0);
    solve(0, ans, sums, cookies, k);
    return ans;
  }
};
// @lc code=end
