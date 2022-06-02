class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int bestmax = nums[0];
        int running = 0;
        for(const auto num : nums) {
            if(num == 0) {
                bestmax = max(bestmax, running);
                running = 0;
                continue;
            }
            ++running;
        }
        return max(bestmax, running);
    }
};
