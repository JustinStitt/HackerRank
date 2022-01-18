// link = https://leetcode.com/problems/is-subsequence/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto it = t.begin();
        for(int x{}; x < s.size(); ++x) {
            it = find(it, t.end(), s[x]);
            if(it == t.end()) return false;
            advance(it, 1);
        } // end for
        return true;
    }
};

