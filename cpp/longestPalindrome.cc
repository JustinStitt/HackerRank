// link = https://leetcode.com/problems/longest-palindrome/
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, size_t> count;
        for(auto&& c : s) count[c]++;
        
        
        int res{0};
        bool one_exists{0};
        
        for(auto it = count.begin();
                    it != count.end(); ++it) {
            if(it->second % 2 == 0) {
                res += it->second;
            }
            else if(it->second % 2 && it->second > 1) {
                res += it->second - 1;
                it->second = 1;
                one_exists = true;
            }
            if(it->second == 1) one_exists = true;
        } // end for
        
        if(res % 2 == 0 && one_exists) res++;
        
        return res;
    }
};
