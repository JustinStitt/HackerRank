// link = https://leetcode.com/problems/summary-ranges
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        std::vector<string> ret;
        if(nums.size() < 1) return ret;
        if(nums.size() == 1) return {std::to_string(nums[0])};
        std::string arrow = "->";
        int start = nums[0];
        long long next_logical = start + 1;
        
        for(int x{}; x < nums.size(); ++x) {
            if(x+1 > nums.size() - 1 || nums[x+1] != next_logical) {
                std::string _start = std::to_string(start);
                std::string _end = std::to_string(next_logical - 1);
                if(_start == _end) ret.push_back(_start);
                else ret.push_back(_start + arrow + _end);
                if(x+1 < nums.size()) start = nums[x+1];
                next_logical = (long long) start + 1;
            } else {
                ++next_logical;
            }
        }
        
        return ret;
    }
};
