# https://leetcode.com/problems/intersection-of-two-arrays/?envType=daily-question&envId=2024-03-10
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return set(nums1) & set(nums2)
