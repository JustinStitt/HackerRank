// link = https://leetcode.com/problems/binary-watch/
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ret;
        
        for(int h{}; h < 12; ++h) {
            for(int m{}; m < 60; ++m) {
                if(bitset<10>((h << 6) | m).count() == turnedOn) {
                    ret.push_back(
                        to_string(h) + ":" +
                        (m < 10 ? "0"+to_string(m) :
                                to_string(m))
                    );
                }
            }
        }
        return ret;
    }
};
/*
    when faced with a problem like this (permutations with bitstrings)
    just consider the domain and iterate through.
*/

