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
  bool recur(const string& s1, int i, const string& s2, int j, const string& s3,
             int k, std::vector<std::vector<bool>>& invalid) {
    if (invalid[i][j]) return false;
    if (k == s3.size()) return true;
    bool valid = (i < s1.size() && s1[i] == s3[k] &&
                  recur(s1, i + 1, s2, j, s3, k + 1, invalid)) ||
                 (j < s2.size() && s2[j] == s3[k] &&
                  recur(s1, i, s2, j + 1, s3, k + 1, invalid));
    if (!valid) invalid[i][j] = true;
    return valid;
  }

  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) return false;     // can't work
    if (!s1.size() && !s2.size() && !s3.size()) return true;  // edge case
    std::vector<std::vector<bool>> invalid(s1.size() + 1);
    for (auto& vec : invalid) vec.resize(s2.size() + 1);
    return recur(s1, 0, s2, 0, s3, 0, invalid);
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