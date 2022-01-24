// link = https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> lookup;
        for(int x{}; x < nums.size(); ++x) lookup[nums[x]] = x;
        
        for(int x{}; x < nums.size(); ++x) {
            auto f = lookup.find(target-nums[x]);
            if(f != lookup.end() && f->second != x) return {f->second, x};
        }
        return {-1, -1};
    }
};

