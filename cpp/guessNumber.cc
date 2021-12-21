// link = https://leetcode.com/problems/guess-number-higher-or-lower
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        
        int resp{}, mp{};
        
        for(;;) {
            mp = low + (high - low) / 2;
            resp = guess(mp);
            if(resp == 0) return mp;
            else if(resp == -1) {
                high = mp - 1;
            }
            else {
                low = mp + 1;
            }
        }
        
        return -1; // not found
    }
};

