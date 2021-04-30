// link = https://leetcode.com/problems/contains-duplicate-ii
class Solution {
public:
    /*
        two indices in the array where their values are the same
        and their absolute value is <= k
        
        idea:
        map values to a pair of indices.
        first pass we assign p.first, second pass we assign p.second
        if abs(p.first - p.second) <= k
        then we have found i, j ... return true
    */
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lookup;
        
        /* iterate through array */
        for(int x{}; x < nums.size(); ++x){
            if(lookup.find(nums[x]) == lookup.end()){// first time at this value
                lookup[nums[x]] = x;
                continue;
            }
            // otherwise we've encountered this value before,
            // check abs(x_new - x_old) to see if <= k...
            // if greater than k, move x_old to x_new and set x_new to -1
            if(abs(lookup[nums[x]] - x) <= k) return true;
            lookup[nums[x]] = x;
        }
        return false;
    }// end containsNearbyDuplicate
};