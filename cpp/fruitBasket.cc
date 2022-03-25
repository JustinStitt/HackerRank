// link = https://leetcode.com/problems/fruit-into-baskets/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if(fruits.size() < 1) return 0;
        int cmax = 0, local = 0;
        set<int> uniq;
        int start_of_second = 0;
        bool can_change = true;
        for(int x{}; x < fruits.size(); ++x) {
            uniq.insert(fruits[x]);
            if(uniq.size() == 2 && can_change) {
                start_of_second = x;
                can_change = false;
            }
            else if(uniq.size() > 2) {
                //return to start_of_second
                x = start_of_second - 1;
                uniq.clear();
                can_change = true;
                local = 0;
                continue;
            }
            ++local;
            cmax = max(cmax, local);
        }
        return max(cmax, local);
    }
};

