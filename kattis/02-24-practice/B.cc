#include <bits/stdc++.h>
using namespace std;

void solve(string &oline) {
  // remove all spaces
  string line = "";
  for (char c : oline) {
    if (c != ' ') {
      line.push_back(c);
    }
  }
  for (int l = 1; l < line.size(); ++l) {
    unordered_map<string, int> freq;
    int local_max = -1;
    for (int x{}; x < line.size(); ++x) {
      string substr = line.substr(x, l);
      ++freq[substr];
      local_max = max(local_max, freq[substr]);
    }
    if (local_max <= 1)
      return;
    cout << local_max << "\n";
  }
}

int main() {
  vector<string> lines;
  string in;
  while (getline(cin, in)) {
    lines.emplace_back(in);
  }

  for (string &line : lines) {
    solve(line);
    cout << "\n";
  }

  return 0;
}
