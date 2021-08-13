// link = https://leetcode.com/problems/number-of-1-bits/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        for(int x{}; x < 32; ++x) {
            count += (n & (1 << x)) ? 1 : 0;
        }
        return count;
    }
};
