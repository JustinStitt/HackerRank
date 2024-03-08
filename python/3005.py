# https://leetcode.com/problems/count-elements-with-maximum-frequency/submissions/1197299589/?envType=daily-question&envId=2024-03-08
from collections import Counter


class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        counter = Counter(nums)

        most_common = counter.most_common()
        total = 0
        for elem, freq in most_common:
            if freq != most_common[0][1]:
                break
            total += freq

        return total
