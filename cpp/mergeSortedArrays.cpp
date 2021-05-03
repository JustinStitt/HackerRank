// link = https://leetcode.com/problems/merge-sorted-array
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i{}, j{};
        nums1.resize(m);
        while(i < m && j < n){
            if(nums1[i] >= nums2[j]){
                nums1.insert(nums1.begin() + i, nums2[j++]); 
                ++m;
                continue;
            }
            ++i;
        } // end while
        while(j < n){
            nums1.push_back(nums2[j++]);
        }
    }
};
