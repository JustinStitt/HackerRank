// link = https://leetcode.com/problems/rabbits-in-forest/
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;
        for(auto& ans : answers){++freq[ans];}
        
        int count{};
        
        // 3 3 3 3
        // freq / val + 1
        // 1 1 1
        // 0 0 0
        for(auto it = freq.begin(); it != freq.end(); ++it){
            count += (it->first+1) * 
                            ceil(float(it->second)/float(it->first+1));
        }
        return count;
    }
};
