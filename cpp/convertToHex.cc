// link = https://leetcode.com/problems/convert-a-number-to-hexadecimal/
class Solution {
public:
    map<int, char> lookup = {{10, 'a'}, {11, 'b'}, {12, 'c'},
                                 {13, 'd'}, {14, 'e'}, {15, 'f'}};
    string toHex(int64_t num) {
        if(num < 0) return toHex(pow(2, 32) + num);
        if(num == 0) return "0";
        if(num < 10) return to_string(num);
        if(num <= 15) return string(1, lookup[num]);
        // > 15
        return toHex(num/16) + toHex(num%16);
    }
};


/*
54 = 0x36

54 / 16 = 3
54 - (16 * 3) = 54 - 48 = 6

257 = 0x101

257/16 = 16
257 - (16*16) = 257 - 256 = 1
*/

