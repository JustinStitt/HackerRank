class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        table = {v: i for i, v in enumerate(nums2)}
        ans = []
        for num in nums1:
            idx = table[num]
            if idx >= len(nums2) - 1:
                ans.append(-1)
                continue
            next_largest = None
            for _idx in range(idx + 1, len(nums2)):
                if nums2[_idx] > num:
                    next_largest = nums2[_idx]
                    break

            ans.append(next_largest if next_largest else -1)
        return ans
