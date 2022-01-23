// link = https://leetcode.com/problems/contains-duplicate/
class Solution {
public:
    bool containsDuplicate(vector<int> nums) {
        using T = std::decay<decltype(*nums.begin())>::type;
        set<T> seen(nums.begin(), nums.end());
        return seen.size() != nums.size();
    }
};

