// link = https://leetcode.com/problems/ugly-number
class Solution {
private:
    vector<int> primes = {2, 3, 5};
public:
    bool isUgly(int n) {
        if(n == 0) return 0;
        
        for(auto p : primes) {
            if(n % p != 0) continue;
            return isUgly(n/p);
        }
        
        if(n != 1) return 0;
        return 1;
        
    }
};
/*

15 = 5 * 3
20 = 5 * 2 * 2

20 / 5 = 5 * 2 * 2

100 = 5 * 5 * 2 * 2

*/

