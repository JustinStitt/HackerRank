#include <bits/stdc++.h>

class Solution {
 public:
  int longestConsecutive(std::vector<int>& nums) {
    std::unordered_set<int> fringe(nums.begin(), nums.end());
    int best{0};

    for (auto&& n : nums) {
      // make sure it exists in our fringe
      auto f = fringe.find(n);
      if (f == fringe.end()) continue;
      fringe.erase(f);  // remove ourselves

      // if it exists, count sequence below and sequence above
      int len{1};  // include ourselves to begin with
      int dec{1}, inc{1};

      while (fringe.find(n - dec) != fringe.end()) {
        // remove from our fringe and increase length
        fringe.erase(n - dec);
        ++len;
        ++dec;
      }

      while (fringe.find(n + inc) != fringe.end()) {
        fringe.erase(n + inc);
        ++len;
        ++inc;
      }

      best = std::max(best, len);
    }

    return best;
  }
};
