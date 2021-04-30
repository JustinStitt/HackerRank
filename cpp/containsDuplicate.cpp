// link = https://leetcode.com/problems/contains-duplicate/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        using T = std::decay<decltype(*nums.begin())>::type;
        //typedef std::decay<decltype(*nums.begin())>::type T;
        
        set<T> distinct;
        for(auto& num : nums)
            distinct.insert(num);
        return distinct.size() != nums.size();
    }
};