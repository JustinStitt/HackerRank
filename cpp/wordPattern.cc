// link = https://leetcode.com/problems/word-pattern/
class Solution {
public:
    vector<string> tokenize(string s) {
        if(!s.size()) return {};
        s.push_back(' ');
        vector<string> tokens;
        // convert space-separated string into token vector
        for(int x{}, i{}; x < s.size(); ++x) {
            if(s[x] != ' ') continue;
            string sub = s.substr(i, x - i);
            i = x + 1;
            tokens.push_back(sub);
        }
        return tokens;
    }
    
    bool wordPattern(string pattern, string s) {
        /* pattern or given string empty */
        if(!pattern.size() || !s.size()) return false;
        
        vector<string> tokens = tokenize(s);
        if(pattern.size() != tokens.size()) return false; // size mismatch
        
        /* create mappings of pattern symbol to token */
        unordered_map<char, string> symbol_to_token;
        unordered_map<string, char> token_to_symbol;
        for(int x{}; x < pattern.size(); ++x) {
            // already exists a mapping from this symbol
            if(symbol_to_token.count(pattern[x])) {
                if(symbol_to_token[pattern[x]] != tokens[x]) return false;
            } else { // not mapping exists yet from symbol to token
                if(token_to_symbol.count(tokens[x])) return false;
                symbol_to_token[pattern[x]] = tokens[x];
                token_to_symbol[tokens[x]] = pattern[x];
            }
            
        } // end for
        return true;
    }
};

