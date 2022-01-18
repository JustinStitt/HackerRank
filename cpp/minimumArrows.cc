// link = https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
class Solution {
public:
    bool intersect(const vector<int>& a, const vector<int>& b) {
        if(b[0] > a[1] || b[1] < a[0]) return 0;
        return 1;
    }
    
    struct PointCompare{
      bool operator()(const vector<int>& a, const vector<int>& b) {
          return a[0] < b[0];
      }  
    };
    
    int findMinArrowShots(vector<vector<int>>& points) {
        std::priority_queue<vector<int>, vector<vector<int>>, PointCompare> min_heap;
        for(auto& point : points) min_heap.push(point);
        
        int min_arrows{};
        while(!min_heap.empty()) {
            vector<int> u = min_heap.top();
            min_heap.pop();
            while(!min_heap.empty() && intersect(min_heap.top(), u)) min_heap.pop();
            ++min_arrows;
        } // end while
        
        return min_arrows;        
    }
};
