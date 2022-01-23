
// link = https://leetcode.com/problems/arranging-coins/
class Solution {
public:
    int arrangeCoins(int n) {
        double two_n = n * 2.0;
        
        /* quadratic eq. */
        double res = (1.0 + 
                      sqrt(1.0+two_n*4.0)) 
                        / 2.0;
        
        double epsilon = 0.00001;
        if(abs(res - round(res)) <= epsilon) {
            return static_cast<int>(round(res)) - 1;
        }
        return static_cast<int>(res) - 1;
    }
};

