// link = https://leetcode.com/problems/find-the-difference/
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, size_t> _exists;
        
        for(auto&& letter : s) _exists[letter]++;
        
        for(auto&& letter : t) {
            if(_exists[letter] < 1) return letter;
            _exists[letter]--;
        }
        
        return char{' '};
    }
};

