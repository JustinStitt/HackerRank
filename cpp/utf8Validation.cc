#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=393 lang=cpp
 *
 * [393] UTF-8 Validation
 */

// @lc code=start
class Solution {
 public:
  bool validUtf8(vector<int> data) {
    int to_follow{0};
    for (int raw : data) {
      uint8_t num = raw & 255;
      /* if there are leading 1's, some stuff to follow */
      if (!to_follow) {  // we aren't currently checking for follows
        int num_bytes{};
        /* go check until we find the first 0 */
        uint8_t mask = 128;
        while (num & mask) {
          ++num_bytes;
          mask = mask >> 1;
        }
        if (num_bytes > 4) return false;   // invalid following byte count
        if (num_bytes == 1) return false;  // invalid following byte count
        if (num_bytes) to_follow = num_bytes - 1;
        continue;
      }  // we are expecting following

      if ((num & 128) && !(num & 64)) {  // starts with '10'
        --to_follow;
        continue;
      }

      return false;
    }
    if (to_follow != 0) return false;
    return true;
  }
};
// @lc code=end
