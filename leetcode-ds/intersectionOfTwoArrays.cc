// link = https://leetcode.com/problems/intersection-of-two-arrays-ii/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_multiset<int> lookup;
        vector<int> intersection;
        
        for(const auto& n : nums1 )
            lookup.insert(n);
        
        for(const auto& n : nums2) {
            auto f = lookup.find(n);
            if(f == lookup.end()) continue;
            intersection.push_back(*f);
            lookup.erase(f);            
        }
        
        return intersection;
    }
};

