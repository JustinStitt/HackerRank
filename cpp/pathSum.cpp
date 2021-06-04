/**
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        
        int new_sum = targetSum - root->val;
        if(!root->left && !root->right){ // we are a leaf
            return (new_sum == 0);
        }
        
        // recursively call both sides
        return (hasPathSum(root->left, new_sum) || 
                        hasPathSum(root->right, new_sum));
    }
};