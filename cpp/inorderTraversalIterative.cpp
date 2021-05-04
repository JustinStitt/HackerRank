/**
 * link = https://leetcode.com/problems/binary-tree-inorder-traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> inorder;
        stack<TreeNode*> S;
        S.push(root);
        unordered_set<TreeNode*> visited;
        visited.insert(root);
        
        while(!S.empty()){
            TreeNode* curr = S.top();
            visited.insert(curr);
            // go left as much as we can
            while(curr->left && visited.find(curr->left) == visited.end()){
                S.push(curr->left);
                visited.insert(curr->left);
                curr = curr->left;
            }
            // action
            inorder.push_back(curr->val);
            S.pop();
            // go right once
            if(curr->right && visited.find(curr->right) == visited.end())
                S.push(curr->right);
        }
        return inorder;
    }
};
