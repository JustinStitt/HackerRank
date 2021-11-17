// link = https://leetcode.com/problems/missing-number
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> hs;
        
        for(int n : nums) hs.insert(n);
        
        int mx = *max_element(nums.begin(), nums.end());
        
        for(int n = 0; n <= mx; ++n) {
            if(!hs.count(n)) return n;
        }
        
        return mx + 1;
    }
};

