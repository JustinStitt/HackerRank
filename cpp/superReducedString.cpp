// link = https://www.hackerrank.com/challenges/reduced-string/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s) {
    string empty = "Empty String";
    int n = s.size();
    for(int x = 1; x < n; ++x){
        if(s[x-1] == s[x]){ // remove both
            s.erase(s.begin() + x - 1, s.begin() + x + 1);
            // decrease n
            n -= 2;
            x -= 2;
        }
    }
    return (n > 0 ? s : empty);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}


/* REGEX SOLUTION
string superReducedString(string s) {
    std::regex dupe("(.)\\1");
    
    for(int x{}; x < 100; ++x)
        s = std::regex_replace(s, dupe, "");
    return (s.size() <= 0 ? "Empty String" : s);
}
*/
