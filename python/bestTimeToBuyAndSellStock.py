class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = prices[0]
        max_profit = 0
        for x in range(1, len(prices)):
            min_price = min(min_price, prices[x])
            max_profit = max(max_profit, prices[x] - min_price)
        return max_profit
