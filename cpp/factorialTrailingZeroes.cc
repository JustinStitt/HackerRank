// link = https://leetcode.com/problems/factorial-trailing-zeroes/
class Solution {
public:
    int trailingZeroes(int n) {
        int start = 5;
        int a = 1;
        int result = 0;
        
        while(1) {
            int count = n/start;
            result += count;
            start = pow(5,++a);
            if(count <= 0) break;
        }
        return result;
    }
};

/*
    to get trailing zeros
    we need to multiply to 10
    
    (5^a)*b where a is > 0 and b%2=0
*/
