/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
  int maxDepth(Node *root) {
    if (!root)
      return 0;
    int biggest = 1;

    std::queue<std::pair<Node *, int>> Q;
    Q.push({root, 1});

    while (!Q.empty()) {
      std::pair<Node *, int> curr = Q.front();
      Q.pop();
      Node *node = curr.first;
      if (!node)
        return 0;
      int depth = curr.second;
      biggest = std::max(biggest, depth);

      for (Node *child : node->children) {
        Q.push({child, depth + 1});
      }
    }

    return biggest;
  }
};
