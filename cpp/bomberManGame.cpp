#include <bits/stdc++.h>
#include <regex>

using namespace std;

vector<string> split_string(string);

void placeBombs(vector<string>& grid){
    for(auto& r : grid){
        for(auto& c : r){
            if(c == '.') c = '0'; // place new bomb
        }
    }
}

void progressFuseTimer(int& n, vector<string>& grid){
    --n;
    vector<string> res = grid;
    const int ROWS = grid.size(), COLS = grid[0].size();
    for(int r{}; r < ROWS; ++r){
        for(int c{}; c < COLS; ++c){
            if(grid[r][c] == '2'){ // detonate bombs
                res[r][c] = '.'; // detonate self
                // detonate neighbours
                if(r - 1 >= 0)   res[r-1][c] = '.';
                if(r + 1 < ROWS) res[r+1][c] = '.';
                if(c - 1 >= 0)   res[r][c-1] = '.';
                if(c + 1 < COLS) res[r][c+1] = '.';
            }else if(res[r][c] != '.'){
                if(res[r][c] == 'O') res[r][c] = '0';
                res[r][c] += 1;
            }
        }
    }
    grid = res;
}

vector<string> cleanOutput(vector<string> grid){
    for(auto& r : grid){
        for(auto& c : r){
            if(c == '0' || c == '1' || c == '2') c = 'O';
        }
    }
    return grid;
}

vector<string> bomberMan(int n, vector<string> grid) {
    
    // steps of Bomberman
    if(n <= 1) return grid;    
    progressFuseTimer(n, grid); // do nothing
    n = (n%4) + 4;
    while(n > 0){
        progressFuseTimer(n, grid);   
        placeBombs(grid); // placing new bombs 
        if(n <= 0) return grid;
        progressFuseTimer(n, grid); // detonate bombs
    }
    
    return grid;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string rcn_temp;
    getline(cin, rcn_temp);

    vector<string> rcn = split_string(rcn_temp);

    int r = stoi(rcn[0]);

    int c = stoi(rcn[1]);

    int n = stoi(rcn[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = cleanOutput(bomberMan(n, grid));

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
