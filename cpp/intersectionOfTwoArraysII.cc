// link = https://leetcode.com/problems/intersection-of-two-arrays-ii/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> u, v;
        
        for(auto&& n : nums1) u.insert(n);
        for(auto&& n : nums2) v.insert(n);
        
        /* optimization to linearly traverse smallest set */
        multiset<int>& largest = (u.size() > v.size() ? u : v);
        multiset<int>& smallest = (u.size() > v.size() ? v : u);

        vector<int> result = {};
        
        for(auto it = smallest.begin(); it != smallest.end(); ++it) {
            auto in_largest = largest.find(*it);
            if(in_largest == largest.end()) continue; // not found
            result.push_back(*it);
            largest.erase(in_largest);
        }
        
        return result;
    }
};

