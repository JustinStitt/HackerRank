#include <bits/stdc++.h>

using namespace std;

/*
    8x8 chessboard
    knight can move 2 in one direction and 3 in a perpindicular direction
    knight has starting position and some end goal
    return min number of moves to reach goal
*/

struct posHash { /* create hash function for pairs */
    size_t operator()(const pair<int,int>& pair) const {
        size_t h1 = hash<int>()(pair.first);
        size_t h2 = hash<int>()(pair.second);
        return h1 ^ h2;
    }
};

bool isValidMove(pair<int,int> move) {
    return move.first < 8 && move.first >= 0 &&
           move.second < 8 && move.second >= 0;
}

vector<pair<int,int>> getMoves(pair<int,int> spos, 
                const vector<pair<int,int>>& move_set) {
    vector<pair<int,int>> moves;
    for(auto& move : move_set) {
        pair<int,int> m = {spos.first + move.first, spos.second + move.second};
        moves.push_back(m);
    }                
    return moves;
}

int countMoves(int sx, int sy, int ex, int ey) {
    vector<pair<int,int>> available_moves = {{2,3}, {-2,3}, {-2,-3},{2,-3},
                                             {3,2}, {-3,2}, {-3,-2},{3,-2}};
    queue<pair<int,int>> moves;
    unordered_set<pair<int,int>, posHash> visited;
    moves.push({sx, sy});

    while(!moves.empty()) {
        pair<int,int> cpos = moves.front();
        moves.pop();
        visited.insert(cpos);
        if(cpos.first == ex && cpos.second == ey) return visited.size();

        vector<pair<int,int>> new_moves = getMoves(cpos, available_moves);
        for(auto& nm : new_moves) {
            if(visited.count(nm) || !isValidMove(nm)) continue;
            moves.push(nm);
        }
    }
    return -1;
}

int main() {
    int sx = 0, sy = 0;
    int ex = 4, ey = 6;
    cout << "moves: " << countMoves(sx, sy, ex ,ey) << "\n";
    return 0;
}
