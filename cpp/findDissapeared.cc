class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        ret.reserve(nums.size());
        
        for(const auto& n : nums) {
            nums[abs(n)-1] = -abs(nums[abs(n)-1]);
        }

        for(int x{}; x < nums.size(); ++x) {
            if(nums[x] > 0) {
                ret.push_back(x+1);
            }
        }
        return ret;
    }
};

/*
vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> all(n+1);
        std::iota(all.begin(), all.end(), 0);
        for(const auto& n : nums) {
            all[n] = 0;
        }
        
        vector<int> ret;
        std::copy_if(all.begin()+1, all.end(), std::back_inserter(ret),
                                [](auto a){return a != 0;});
        return ret;
    }
*/
