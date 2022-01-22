// link = https://leetcode.com/problems/number-of-segments-in-a-string/
class Solution {
public:
    int countSegments(string s) {
        char delim = ' ';
        /* remove trailing spaces */
        while(s.size() && *s.rbegin() == ' ') 
            s.erase(s.begin() + s.size() - 1);
        /* remove leading spaces */
        while(s.size() && *s.begin() == ' ') 
            s.erase(s.begin());
        /* remove bulky spaces */
        for(auto it = s.begin(); s.size() && it != s.end();) {
            if(*it != delim) {++it; continue;}
            if(*next(it) == delim) s.erase(it+1);
            else ++it;
        }
        
        if(!s.size()) return 0;
        
        return count(s.begin(), s.end(), delim) + 1;
    }
};

/*
this is a test string!

word

*/

