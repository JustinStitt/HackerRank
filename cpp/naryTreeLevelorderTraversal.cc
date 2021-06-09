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
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<Node*> Q{root};
        vector<vector<int>> ret{};
        
        while(!Q.empty()) {
            // add all elements in Q to ret
            vector<int> tmp{};
            for(auto& e : Q) 
                tmp.push_back(e->val);
            ret.push_back(tmp);
            
            // update Q
            vector<Node*> tmp_Q{};
            for(auto& e : Q) { // each element in the Q
                for(auto& child : e->children) { // each child
                    tmp_Q.push_back(child);
                }
            }
            Q = tmp_Q;
        }
        return ret;
    }
};
