// link = https://leetcode.com/problems/add-digits
class Solution {
public:
    int addDigits(int num) {
        if(num < 10) return num;
        
        // split into digits
        string digits = to_string(num);
        
        int new_num = 0;
        for(char d : digits) {
            new_num += (d - '0');
        }
        
        return addDigits(new_num);
    }
};

