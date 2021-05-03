/**
 * link = https://leetcode.com/problems/balanced-binary-tree
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
    int getHeight(TreeNode* root){
        if(!root) return 0;
        return 1 + max(getHeight(root->left),
                        getHeight(root->right));
    }
    
    bool isBalanced(TreeNode* root){
        if(!root) return true;
        
        int left_height = getHeight(root->left);
        int right_height = getHeight(root->right);
        
        if(abs(left_height - right_height) > 1) return false;
        
        bool left_balance = isBalanced(root->left);
        bool right_balance = isBalanced(root->right);
        return left_balance && right_balance;
    }
};
