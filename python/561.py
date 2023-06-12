class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums = sorted(nums)

        best_sum = 0

        for a, b in zip(nums[::2], nums[1::2]):
            best_sum += min(a, b)

        return best_sum
