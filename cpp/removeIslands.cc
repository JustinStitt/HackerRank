#include <bits/stdc++.h>

using namespace std;

using matrix = vector<vector<int>>;

const int kWHITE = 0;
const int kBLACK = 1;

bool isEdge(const matrix& mat, int r, int c) {
    int rows = mat.size(), cols = mat[0].size();
    
    if(r == rows - 1 || r == 0) return 1;
    if(c == cols - 1 || c == 0) return 1;
    return 0;
}

bool inBounds(const matrix& mat, int r, int c) {
    int rows = mat.size(), cols = mat[0].size();
    if(r > rows - 1 || r < 0) return 0;
    if(c > cols - 1 || c < 0) return 0;
    return 1;
}

vector<pair<int,int>> getNeighbours(const matrix& mat, int r, int c) {
    vector<pair<int,int>> neighbours = {};
    
    vector<pair<int,int>> deltas = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for(auto [dr, dc] : deltas) {
        int nr = r + dr, nc = c + dc;
        if(inBounds(mat, nr, nc) && mat[nr][nc] == kBLACK) {
            neighbours.push_back({nr, nc});
        }
    }

    return neighbours;
}

void dfs(const matrix& mat, matrix& work, set<int*>& vis, set<int*>& edg, int r, int c) {
    if(!inBounds(mat, r, c)) return; // we are out of bounds
    int* us = const_cast<int*>(&mat[r][c]);
    if(vis.count(us)) return; // we have been visited already
    // add ourselves to visited
    vis.insert(us);
    // are we an edge?
    if(isEdge(mat, r, c)) edg.insert(us);

    // check neighbours to see if any of them are in edge, if so we are in edge too
    vector<pair<int,int>> neighbours = getNeighbours(mat, r, c);

    for(auto [nr, nc] : neighbours) {
        if(isEdge(mat, nr, nc)) {
            edg.insert(us);
        }
    }


    // now dfs to neighbours
    for(auto [nr, nc] : neighbours) {
        dfs(mat, work, vis, edg, nr, nc);
    }
 
    if(!edg.count(us))
        work[r][c] = 0; // sink island

}

void removeIslands(matrix& mat) {
    if(mat.size() < 3) return; // all edges if size <= 2

    // prep DFS with visited set and edges set
    set<int*> visited, edges;

    matrix work = mat;

    // loop through matrix and start dfs from each potential island
    for(int r{}; r < mat.size(); ++r) {
        for(int c{}; c < mat[r].size(); ++c) {
            dfs(mat, work, visited, edges, r, c);
        } // end col loop
    } // end row loop

    mat = work;
} // end removeIslands

void printMatrix(const matrix& mat) {
    for(int r{}; r < mat.size(); ++r) {
        for(int c{}; c < mat[r].size(); ++c) {
           std::cout << " " << mat[r][c];
        } std::cout << "\n";
    }
}

int main() {
    matrix m = 
    {
        {0, 1, 0, 0, 1, 0},
        {0, 1, 0, 1, 0, 0},
        {1, 0, 1, 1, 0, 1},
        {0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 1, 1, 0, 1, 1}
    };
    std::cout << "Before:\n";
    printMatrix(m);
    std::cout << string(50, '=') << "\n";

    std::cout << "After:\n";
    removeIslands(m);
    printMatrix(m);
    std::cout << string(50, '=') << "\n";

    return 0;
}

