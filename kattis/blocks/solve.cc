#include <bits/stdc++.h>
using namespace std;

struct Node {
  long long s1;
  long long s2;
  long long player;
  long long value;
  vector<Node*> neighbors;

  ~Node() {
    for (Node* n : neighbors) delete n;
  }
};

void populateTree(Node* root) {
  queue<Node*> Q;
  Q.push(root);

  while (!Q.empty()) {
    Node* front = Q.front(); Q.pop();
    auto& [s1, s2, player, value, neighbors] = *front;
    if (front->s1 == 0 || front->s2 == 0) {
      front->value = front->player;
      continue;
    }
    long long larger = (s1 > s2) ? s1 : s2;
    long long smaller = (s1 < s2) ? s1 : s2;

    for (long long x = smaller; x <= larger; x += smaller) {
      long long next_player = (player == 0) ? 1 : 0;
      Node* child = new Node{smaller, larger - x, next_player, -1, {}};
      neighbors.push_back(child);
      Q.push(child);
    }
  }
}

long long miniMax(Node* curr, bool is_min) {
  if (curr->neighbors.size() == 0) {
    return curr->value;
  }

  vector<long long> values;
  for (Node* child : curr->neighbors) {
    values.push_back(miniMax(child, !is_min));
  }
  if (is_min) {
    return *min_element(values.begin(), values.end());
  }
  return *max_element(values.begin(), values.end());
}

int main() {
  long long n, m;
  cin >> n >> m;
  Node* root = new Node{n, m, 0, -1, {}};
  populateTree(root);
  long long result = miniMax(root, false);
  cout << ((result == 1) ? "win" : "lose") << "\n";
  delete root;
  return 0;
}
