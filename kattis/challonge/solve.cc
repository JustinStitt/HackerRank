#include <bits/stdc++.h>
using namespace std;
#define ll long long

using matrix = vector<vector<ll>>;

struct State {
  ll idx, cost;
  set<ll> visited;
};

ll best = pow(2, 58);

void bfs(const matrix& mat, State* st, ll t) {
  queue<State*> Q;
  Q.push(st);

  while (!Q.empty()) {
    State* ptr = Q.front(); Q.pop();
    State front = *ptr;
    delete ptr;
    if (front.cost >= best) {
      continue;
    }

    front.visited.insert(front.idx);

    if (front.idx == t) {
      best = min(best, front.cost);
    }

    for (int i{}; i < mat.size(); ++i) {
      if (i == front.idx) continue;
      ll cost = mat[front.idx][i];
      if (cost + front.cost >= best) continue;
      set<ll> new_vis;
      for (ll item : front.visited) new_vis.insert(item);
      State* other = new State{i, cost + front.cost, new_vis};
      Q.push(other);
    }
  }
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

  State* initial = new State{s, 0, {}};
  bfs(adj_mat, initial, t);
  cout << best << "\n";


  // for (auto& row : adj_mat) {
  //   for (auto& col : row) { 
  //     cout << col << " ";
  //   }
  //   cout << "\n";
  // }
  return 0;
}
