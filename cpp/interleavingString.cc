#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) return false;  // can't work

    const int n = s1.size();
    const int m = s2.size();
    std::vector<std::vector<bool>> dp(n + 1);
    for (auto& vec : dp) vec.resize(m + 1);

    dp[0][0] = true;

    /* top-most row */
    for (int c{1}; c <= m; ++c) {
      dp[0][c] = (dp[0][c - 1] && (s2[c - 1] == s3[c + 0 - 1]));
    }

    /* left-most col */
    for (int r{1}; r <= n; ++r) {
      dp[r][0] = (dp[r - 1][0] && (s1[r - 1] == s3[r + 0 - 1]));
    }

    /* every slot thereafter */
    for (int r{1}; r <= n; ++r) {
      for (int c{1}; c <= m; ++c) {
        dp[r][c] = (dp[r - 1][c] && (s1[r - 1] == s3[r + c - 1])) ||
                   (dp[r][c - 1] && (s2[c - 1] == s3[r + c - 1]));
      }
    }

    return dp[n][m];
  }
};
// @lc code=end

/*
  keep track of where we are borrowing from with indices
  l and r start at beginning of s1, s2 respectively.
  if we can theoretically borrow from both strings at the same time, we
  need to create a branch and get isInterleave results from each, wherein we
  assume the borrow comes from l or r
*/