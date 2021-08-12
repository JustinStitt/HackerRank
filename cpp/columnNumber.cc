// link = https://leetcode.com/problems/excel-sheet-column-number/
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        const int n = columnTitle.size();
        
        for(int x{}; x < n; ++x) {
            char dist = columnTitle[x] - 'A';
            // 26^(n-x-1) * dist
            res += pow(26, n-x-1) * (dist + 1);
        }
        return res;
    }
};
