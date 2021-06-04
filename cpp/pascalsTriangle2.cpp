class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1);
        
        for(int x{}; x <= rowIndex; ++x) {
            row[0] = row[x] = 1;
            vector<int> cpy = row;
            for(int y = 1; y < x; ++y) {
                row[y] = cpy[y-1] + cpy[y];
            }
        }
        return row;
    }
};
