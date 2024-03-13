# https://leetcode.com/problems/find-the-pivot-integer/?envType=daily-question&envId=2024-03-13
class Solution:
    def pivotInteger(self, n: int) -> int:
        if n == 1:
            return 1

        for i in range(n):
            left_sum = sum(range(1, i + 1))
            right_sum = sum(range(i, n + 1))
            if left_sum == right_sum:
                return i
        return -1
