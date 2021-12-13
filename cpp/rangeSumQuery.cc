// link = https://leetcode.com/problems/range-sum-query-immutable/
class NumArray {
private:
    vector<int> prefix_sums;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        if(!n) return;
        prefix_sums.resize(n);
        prefix_sums[0] = nums[0];
        for(int x = 1; x < n; ++x) {
            prefix_sums[x] += prefix_sums[x-1] + nums[x];
        }
    }
    
    int sumRange(int left, int right) {
        int ret = prefix_sums[right];
        if(!left) return ret;
        return prefix_sums[right] - prefix_sums[left-1];
    }
};

/*
    nums  = [-2, 0, 3, -5, 2, -1]
    p_sum = [-2, -2, 1, -4, -2, -3]
*/

