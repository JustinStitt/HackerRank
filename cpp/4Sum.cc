#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
  using vec = vector<int>;

 public:
  vector<vec> twoSum(vec& nums, long target, long start) {
    vector<vec> ret;
    std::unordered_map<long, long> lookup;

    for (long x{start}; x < nums.size(); ++x) {
      auto num = nums[x];
      if (ret.empty() || ret.back()[1] != num) {
        auto f = lookup.find(num);
        if (f != lookup.end())
          ret.push_back({static_cast<int>(f->second), num});
      }
      long complement = target - num;
      lookup[complement] = num;
    }
    return ret;
  }

  vector<vec> kSum(vec& nums, long target, long k, long start) {
    vector<vec> ret;
    if (start == nums.size()) return ret;
    if (k == 2) {
      return twoSum(nums, target, start);
    }

    long average = target / k;
    if (nums.back() < average) return ret;
    if (nums[start] > average) return ret;

    for (long x{start}; x < nums.size(); ++x) {
      if (x == start || nums[x - 1] != nums[x]) {
        vector<vec> results = kSum(nums, target - nums[x], k - 1, x + 1);
        for (vec& result : results) {
          ret.push_back({nums[x]});
          ret.back().insert(end(ret.back()), begin(result), end(result));
        }
      }
    }

    return ret;
  }

  vector<vec> fourSum(vec& nums, long target) {
    if (nums.size() < 4) return {};
    std::sort(nums.begin(), nums.end());
    return kSum(nums, target, 4, 0);
  }
};
// @lc code=end
