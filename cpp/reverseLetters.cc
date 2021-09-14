// link = https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/637/week-2-september-8th-september-14th/3974/
class Solution {
public:
    string reverseOnlyLetters(string s) {
        string letters = "";
        
        for(auto letter : s) {
            char lower = tolower(letter);
            if(lower >= 'a' && lower <= 'z') {
                letters += letter;
            }
        }
        
        reverse(letters.begin(), letters.end());
        
        for(int x{}, i{}; x < s.size(); ++x) {
            char lower = tolower(s[x]);
            if(lower >= 'a' && lower <= 'z') {
                s[x] = letters[i++];
            }
        }
        return s;
    }
};
