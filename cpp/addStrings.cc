// link = https://leetcode.com/problems/add-strings/
class Solution {
public:
    int add(const char u, const char v) {
        return u + v - 96; /* 2x48 */
    }
    
    string addStrings(string num1, string num2) {
        /* ensure num1 is larger or equivalent */
        if(num1.size() < num2.size()) return addStrings(num2, num1);
        
        string result = "";
        int carry{0}, n = num1.size();
        
        for(int i = n - 1, j = num2.size() - 1; i >= 0; --i, --j) {
            int sum = add(num1[i], (j>=0?num2[j]:'0'));
            if(carry) {
                sum += carry;
                carry = 0;
            }
            if(sum >= 10) {
                carry = sum / 10;
                sum %= 10;
            }
            result += sum + 48;
        } /* end for */
    
        if(carry) result += carry + 48;
        
        reverse(result.begin(), result.end());
        return result;
    }
};

/*
456
 77
*/