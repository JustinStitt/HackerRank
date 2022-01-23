// link = https://leetcode.com/problems/zigzag-conversion/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> rows(numRows, "");
        
        bool increasing = true;
        for(int x{}, crow{}; x < s.size(); ++x) {
            rows[crow] += s[x];
            if(crow == numRows-1) increasing = false;
            else if(crow == 0) increasing = true;
            crow = (increasing ? crow+1 : crow-1);
        }
        
        string ret = "";
        for(auto& row : rows) {
            ret += row;
        }
        return ret;
    }
};

