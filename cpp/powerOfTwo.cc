// link = https://leetcode.com/problems/power-of-two/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        
        int c = 0;
        for(int x{}; x < 31; ++x) {
            if(n & (1 << x)) ++c;
        }
        return c==1;
    }
    /*
        if bitstring has either 0 or 1 '1's then it's a power of 2
    */
};
