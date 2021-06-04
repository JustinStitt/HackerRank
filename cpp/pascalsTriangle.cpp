class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        
        for(int x{}; x < numRows; ++x) {
            res[x].resize(x + 1); // next row is 1 larger than prev
            res[x][0] = res[x][x] = 1; // first & last index is always '1'
            
            // now fill in the middle
            for(int y = 1; y < x; ++y) {
                res[x][y] = res[x-1][y-1] + res[x-1][y];
            }
        }
        return res;
    }
};
