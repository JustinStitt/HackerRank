// link = https://leetcode.com/problems/ransom-note/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, size_t> available;
        for(auto&& letter : magazine) available[letter]++; //O(N)
        
        for(auto&& letter : ransomNote) { //O(N)
            if(available[letter] < 1) return false;
            available[letter]--;
        }
        
        return true;
    }
};
