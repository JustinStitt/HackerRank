class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist{};
        int n = x ^ y;
        
        while(n) {
            ++dist;
            n &= n-1;
        }
        return dist;
    }
};

/*
int hammingDistance(int x, int y) {
        int dist{};

        unsigned int bm = 1;
        
        while(bm <= max(x, y)) {
            int count = ((bm & x) ? 1 : 0) + ((bm & y) ? 1 : 0);
            if(count == 1) dist++;
            bm *= 2;
        }
        
        return dist;
    }
*/
