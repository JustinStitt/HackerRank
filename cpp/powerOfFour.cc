// link = https://leetcode.com/problems/power-of-four
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 1) return false;
        double epsilon = 0.001;
        double out = log(n)/log(4);
        double i = int(out);
        if(out - i <= epsilon) return true;
        return false;
    }
};

