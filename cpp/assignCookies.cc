class Solution {
public:
    int findContentChildren(vector<int>& kids, vector<int>& cookies) {
        std::sort(cookies.begin(), cookies.end());
        std::sort(kids.begin(), kids.end(), std::greater<int>());
        if(cookies.size() == 0) return 0;
        int count{};
        for(auto& kid : kids) {
            if(cookies.size() == 0) break;
            int last = cookies.back();
            if(last < kid) continue;
            ++count;
            cookies.pop_back();
        }
        return count;
    }
};
