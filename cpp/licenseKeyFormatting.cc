class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        // remove dashes
        int current = 0;
        for(int x{}; x < s.size(); ++x) {
            if(s[x] == '-') continue;
            if(s[x] >= 'a' && s[x] <= 'z') s[x] -= 32; // toupper
            s[current++] = s[x];
        }
        s = s.substr(0, current);
        int n = s.size();
        if(!n) return "";
        
        for(int x = n - k; x > 0; x -= k) {
            s.insert(x, "-");
        }
        return s;
    }
};
