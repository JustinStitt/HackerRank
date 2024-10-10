# https://leetcode.com/problems/distribute-candies
class Solution:
    def distributeCandies(self, candyType: list[int]) -> int:
        n = len(candyType)
        assert(n % 2 == 0)

        most = n // 2
        return min(most, len(set(candyType)))
