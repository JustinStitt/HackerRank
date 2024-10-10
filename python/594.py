# https://leetcode.com/problems/longest-harmonious-subsequence
from collections import Counter

class Solution:
    def findLHS(self, nums: list[int]) -> int:
        assert(len(nums))

        counter = Counter(nums)
        # [1,2,2,2,3,3,5,7]
        best = 0
        for num in nums:
            ccount = counter[num]
            if (inc := counter[num+1]) > 0:
                best = max(best, ccount + inc)

        return best

