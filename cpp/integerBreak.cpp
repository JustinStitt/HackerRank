// link = https://leetcode.com/problems/integer-break/
class Solution {
public:
    int integerBreak(int n) {
        if(n < 3) return 1;
        if(n == 3) return 2;
        int num_threes = n / 3;
        int leftover = n - num_threes * 3;
        if(leftover <= 1 && leftover > 0) --num_threes;
        int num_twos = (n - num_threes * 3) / 2;
        
        return pow(2, num_twos) * pow(3, num_threes);
    }
};