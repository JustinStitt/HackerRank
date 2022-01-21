// link = https://leetcode.com/problems/third-maximum-number/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int k = 3;
        priority_queue<int> max_heap(nums.begin(), nums.end());
        
        set<int> uniq;
        
        while(uniq.size() != k) {
            if(max_heap.size() <= 0)
                return *max_element(uniq.begin(), uniq.end());
            uniq.insert(max_heap.top());
            max_heap.pop();
        }
        
        return *min_element(uniq.begin(), uniq.end());
    }
};

