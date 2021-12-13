// link = https://leetcode.com/problems/nim-game/
class Solution {
public:
    bool canWinNim(int n) {
        return (n % 4);
    }
};

/*
bottom-up DP?
n = 1 -> M
n = 2 -> M
n = 3 -> M
M's goal is to have 1,2,3 to pick on their turn
n = 4 -> F
n = 5 -> M{4, 3, 2}
n = 6 -> M
n = 7 -> M
n = 8 -> 


-=-=-=-=-=-=
n = 7
M: 3
n = 4
F: 1
n = 3
M: 3 I WIN

*/

