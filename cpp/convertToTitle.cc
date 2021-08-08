// link = https://leetcode.com/problems/excel-sheet-column-title/submissions/
class Solution {
public:
    // 65 = 'A'
    string convertToTitle(int columnNumber) {
        if(columnNumber == 0) return ""; // base case
        
        return convertToTitle((columnNumber - 1) / 26) + 
                        char('A' + (columnNumber - 1)%26);
    }
};