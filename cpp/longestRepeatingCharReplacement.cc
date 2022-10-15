#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution {
 public:
  int characterReplacement(string s, int k) {
    if (!s.size()) return 0;
    int l{}, r{}, best{}, mostf{};
    std::unordered_map<char, int> window_freq;

    for (; r < s.size(); ++r) {
      // add right-most character to window
      int cfreq = ++window_freq[s.at(r)];
      // count of most frequent character in window
      mostf = std::max(mostf, cfreq);
      int total = (r - l + 1);
      int replacements_needed = (total - mostf);
      if (replacements_needed <= k) {
        best = std::max(best, total);
      } else {
        // window no longer valid, increase left ptr
        window_freq[s.at(l)]--;  // remove from window
        ++l;                     // increase window boundary
      }
    }
    return best;
  }
};
// @lc code=end

/*




 */