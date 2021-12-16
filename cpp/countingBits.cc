// link = https://leetcode.com/problems/counting-bits
class Solution {
public:
    
    vector<int> countBits(int n) {
        vector<int> ret(n + 1);
        
        ret[0] = 0;
        int j = 0;
        
        for(int i = 1; i < n + 1; ++i) {
            if( ((i-1)&i) == 0) { // is power of two
                ret[i] = 1;
                j = i;
                continue;
            }
            
            ret[i] = ret[j] + ret[i-j];
        }
        
        return ret;
    }
};

