// link = https://leetcode.com/problems/first-bad-version/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int midpoint(int u, int v) {
        return (u + (v - u) / 2);
    }
    
    int firstBadVersion(int n) {
        int l = 0, r = n, mp;
        
        for(; l <= r; mp = midpoint(l, r)) {
            if(isBadVersion(mp)) {
                if(l == mp && r == mp) return mp;
                r = mp;
            } else {
                l = mp + 1;
            }
        }
        
        return -1;
    }
};

/*
[1, 2, 3, [4], 5]
*/

