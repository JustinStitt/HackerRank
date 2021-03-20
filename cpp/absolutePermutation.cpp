// link = https://www.hackerrank.com/challenges/absolute-permutation/problem
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int place(vector<int>& res, int x, int k){
    if(x > res.size() - 1) return 0;
    int bad_options{};
    if( (x-k >= 0 && res[x-k] != 0) || x-k < 0) bad_options++;
    if( (x+k < res.size() && res[x+k] != 0) || x+k > res.size() - 1) bad_options++;
    // base case... 2 bad options
    if(bad_options == 2) return -1;
    // two good options
    if( (x-k >= 0 && res[x-k] == 0) && 
        (x+k < res.size() && res[x+k] == 0)){
        place(res, x + 1, k);
    }
    // left is good option, right is not
    if( (x-k >= 0 && res[x-k] == 0) && 
        (x+k > res.size() - 1 || ( x + k < res.size() && res[x+k] != 0))){

        res[x-k] = x + 1;
        place(res, x + 1, k);
    }
    // right is good option, left is not
    if( (x-k < 0 || ( x - k >= 0 && res[x-k] != 0)) && 
        (x+k < res.size() && res[x+k] == 0)){
        res[x+k] = x + 1;
        place(res, x + 1, k);
    }
    return 0;
}

vector<int> absolutePermutation(int n, int k) {
    vector<int> res(n, 0), no{-1};
    if(k == 0){
        for(int x{}; x < n; ++x)
            res[x] = x + 1;
    }else
        place(res, 0, k);
    // check for a 0
    if(find(res.begin(), res.end(), 0) != res.end()) return no;
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nk_temp;
        getline(cin, nk_temp);

        vector<string> nk = split_string(nk_temp);

        int n = stoi(nk[0]);

        int k = stoi(nk[1]);

        vector<int> result = absolutePermutation(n, k);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

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
