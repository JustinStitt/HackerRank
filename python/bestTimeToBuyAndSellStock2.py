class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        lmin = prices[0]
        best = 0
        for x in range(1, len(prices)):
            lmin = min(lmin, prices[x])
            best = max(best, prices[x] - lmin)
            if prices[x] < prices[x-1]:
                profit += best
                best = 0
                lmin = prices[x]
        return profit + best
