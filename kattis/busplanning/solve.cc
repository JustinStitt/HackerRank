#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  // ...
  ll n, k, c;
  map<string, set<string>> hates;

  string name;
  for (int x{}; x < n; ++x) {
    cin >> name;
  }

  string u, v;
  for (int x{}; x < k; ++x) {
    cin >> u >> v;
    hates[u].insert(v);
    hates[v].insert(u);
  }

  return 0;
}
