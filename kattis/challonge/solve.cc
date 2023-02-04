#include <bits/stdc++.h>
using namespace std;
#define ll long long

using matrix = vector<vector<ll>>;

struct State {
  int idx, cost;
  set<ll> visited;
};

int best = pow(2, 63);

int bfs(const matrix& mat) {
  queue<State*> Q;
  State* initial = new State{}
}


int main() {
  // ...
  int n, s, t, inp;
  cin >> n >> s >> t;
  matrix adj_mat(n);
  for (auto& row : adj_mat) {
    row.resize(n);
  }

  for (int r{}; r < n; ++r) {
    for (int c{}; c < n; ++c) {
      cin >> inp;
      adj_mat[r][c] = inp;
    }
  }



  // for (auto& row : adj_mat) {
  //   for (auto& col : row) { 
  //     cout << col << " ";
  //   }
  //   cout << "\n";
  // }
  return 0;
}
