class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        
        for(int x{1}; x < n; ++x) {
            // better to use dp[x-1]+dp[x] or dp[x]?
            dp[x] = max(dp[x-1]+nums[x], nums[x]);
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};

/*

class Solution {
public:


int maxSubArray(vector<int>& nums) 
{
	int ans = INT_MIN;
    int a = 0;
    for(int x : nums)
    {
        a += x;
        ans = max(ans,a);
        a = max(a,0);
    }
    return ans;
}

};

*/

