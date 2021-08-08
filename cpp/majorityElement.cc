// link = https://leetcode.com/problems/majority-element/submissions/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() < 1) return -1;
        /* Boyer-Moore Voting algorithm */
        int candidate = nums[0];
        int count = 0;
        for(auto& num : nums) {
            if(!count) {
                candidate = num;
            }
            count += (candidate == num ? 1 : -1);
        }
        return candidate;
    }
};
