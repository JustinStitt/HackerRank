// link = https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;
        if(n < 3) return max(prices[1]-prices[0], 0);
        vector<int> dp(n);
        
        int best{};
        dp[0] = prices[0];
        for(int x{1}; x < n; ++x) {
            dp[x] = min(dp[x-1], prices[x]);
            best = max(prices[x]-dp[x], best);
        } // min prefix memo 
        
        return best;
    }
};

