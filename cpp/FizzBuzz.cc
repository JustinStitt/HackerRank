// link = https://leetcode.com/problems/fizz-buzz/
class Solution {
public:
    string fizzBuzzHelper(int n) {
        if(n % 3 == 0 && n % 5 == 0) return "FizzBuzz";
        else if(n % 3 == 0) return "Fizz";
        else if(n % 5 == 0) return "Buzz";
        return to_string(n);
    }
    
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for(int x{}; x < n; ++x) {
            res[x] = fizzBuzzHelper(x+1);
        }
        return res;
    }
};

