// link = https://leetcode.com/problems/valid-perfect-square/
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return 1;
        int start = log2(num);
        for(long long i = start; i <= num / 2; ++i) {
            if(i * i == num) return 1;
        }
        return 0;
    }
};
/*
x^2 = y
logx(y) = 2
|
|
| \             /
|  \           /
|   \         /
|    \       /-
|    -\     /
      -\___/-
------------------------

1 + 3 + 5 + 7 + 9 ...
*/

