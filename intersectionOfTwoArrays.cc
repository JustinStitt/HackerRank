class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1_lookup; // O(1)
        
        for(int num : nums1) n1_lookup.insert(num); // O(N)
        
        unordered_set<int> common; // O(1)
        
        for(int num : nums2) { // O(N)
            if(n1_lookup.count(num) == 1) { // O(1)
                common.insert(num); // O(1)
            }
        }
        
        // common has all the inserction numbers
        vector<int> ret; // O(1)
        
        for(auto it = common.begin(); it != common.end(); ++it) { // O(N)
            ret.push_back(*it); // O(1)*
        } 

        return ret;
        
    }
};

/*
 hash table
 
 hashmaps : key, value
 hashsets : keys
*/

