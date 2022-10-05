# link = https://leetcode.com/problems/longest-consecutive-sequence
class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        if not len(nums):
            return 0
        best = 0

        fringe = set(nums)

        for n in fringe:
            # start at smallest and count up
            if (n - 1) in fringe:
                continue  # we aren't the smallest of the sequence
            # otherwise we are... so how long is the sequence?
            cn = n + 1
            length = 1
            while cn in fringe:
                length += 1
                cn += 1
            best = max(best, length)

        return best
