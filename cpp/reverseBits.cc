// link = https://leetcode.com/problems/reverse-bits/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t largest = 2147483648;
        uint32_t smallest = 1;
        
        uint32_t ret = 0;
        while(largest > smallest) {
            if(largest & n) {
                ret += smallest;
            }
            if(smallest & n) {
                ret += largest;
            }
            largest /= 2;
            smallest *= 2;
        }
        
        return ret;
    }
};

/*
    [1]001[0]

    10010 = 18
    10000 lb = 1
    00001 rb = 0
    01001 = 9
    
    1110 = 14
    0111 = 7
    
    1010 = 10
    0101 = 5
    
    1011 = 11
    1000 lb = 1 add 1
    0001 rb = 1 add 8
    so far 9
    0100 lb = 0 add 0
    0010 rb = 1 add add 4
    1101 = 13
*/

