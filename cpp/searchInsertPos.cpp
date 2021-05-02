// link = https://leetcode.com/problems/search-insert-position
class Solution {
public:
    /*
        5 6 8 9 10    
    */
    int binarySearch(const vector<int>& nums, int target, 
                                        int l, int r){
        if(l > r) return l;
        int mp = (l + r) / 2;
        if(nums[mp] == target) return mp;
        
        if(target < nums[mp]) return binarySearch(nums, target, 
                                                    l, mp - 1);
        return binarySearch(nums, target, mp + 1, r);
    }
    
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
    
};
