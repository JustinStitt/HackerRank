/**
 * link = https://leetcode.com/problems/binary-tree-level-order-traversal
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // BFS
        vector<vector<int>> ret;
        if(!root) return ret;
        queue<pair<TreeNode*, int>> Q;
        Q.push({root, 0});
        ret.push_back({root->val});
        
        while(!Q.empty()){
            auto p = Q.front();
            TreeNode* v = p.first;
            int level = p.second + 1;
            if(level > ret.size() - 1)
                ret.push_back({}); // add new empty vector
            
            if(v->left){ 
                Q.push({v->left, level}); 
                ret[level].push_back(v->left->val); 
            }
            if(v->right){
                Q.push({v->right, level});
                ret[level].push_back(v->right->val);
            }
            Q.pop();
        }
        ret.erase(ret.end());
        return ret;
    }
};
