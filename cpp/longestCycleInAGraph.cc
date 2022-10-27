#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=2360 lang=cpp
 *
 * [2360] Longest Cycle in a Graph
 */

// @lc code=start
class Solution {
 public:
  void dfs(int curr, vector<int>& edges, vector<int>& visited, int& best,
           vector<int>& store) {
    if (visited[curr]) {
      int first_apperance = -1;
      for (int i{}; i < store.size(); ++i) {
        if (store[i] == curr) {
          first_apperance = i;
          break;
        }
      }
      if (first_apperance == -1) return;  // didn't find
      int length = store.size() - first_apperance;
      best = max(best, length);
      return;
    }
    visited[curr] = true;
    store.push_back(curr);

    /* either one or zero neighbors */
    int neighbor = edges[curr];
    if (neighbor == -1) return;
    dfs(neighbor, edges, visited, best, store);
  }

  int longestCycle(vector<int>& edges) {
    int best = -1;
    vector<int> visited(edges.size(), false);

    for (int i{}; i < edges.size(); ++i) {
      if (edges[i] == -1 || visited[i]) continue;
      vector<int> store;
      dfs(i, edges, visited, best, store);  // starting at vertex 0
    }
    return best;
  }
};
// @lc code=end

/*
    idea-01:
    start a dfs at each vertex
    detect cycles from that start point back to itself
    ... maximize... profit?!

 */