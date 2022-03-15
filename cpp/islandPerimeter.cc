class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int perimeter{};
        int adj{};
        
        for(int r{}; r < n; ++r) {
            for(int c{}; c < m; ++c) {
                if(grid[r][c]) perimeter += 4;
                else continue;
                // remove adj
                if(r && grid[r-1][c]) ++adj;
                if(c && grid[r][c-1]) ++adj;
            }
        }
        return perimeter - adj*2;
    }
};

/*
int getValue(int x2, int y2, const vector<vector<int>>& g, int n, int m) {
        if(x2 < 0 or x2 > n - 1) return 1;
        if(y2 < 0 or y2 > m - 1) return 1;
        return !g[x2][y2];
    }
    
    int getValueOfNeighbours(int r, int c, const vector<vector<int>>& g, int n, int m) {
        int total{};
        vector<pair<int,int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(auto& [rd, cd] : dirs) {
            total += getValue(r+rd, c+cd, g, n, m);
        }
        return total;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int perimeter{};
        
        for(int r{}; r < n; ++r) {
            for(int c{}; c < m; ++c) {
                if(grid[r][c] == 0) continue;
                perimeter += getValueOfNeighbours(r, c, grid, n, m);
            }
        }
        return perimeter;
    }
*/

