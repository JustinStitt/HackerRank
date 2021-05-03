/**
 * link = https://leetcode.com/problems/symmetric-tree
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
    TreeNode* invertBinaryTree(TreeNode* root){
        if(!root) return root;
        TreeNode* left_subtree = invertBinaryTree(root->left);
        TreeNode* right_subtree = invertBinaryTree(root->right);
        root->left = right_subtree;
        root->right = left_subtree;
        return root;
    }
    
    bool sameTree(TreeNode* A, TreeNode* B){
        if(!A && !B) return true;
        if(!A || !B) return false;
        
        if(A->val != B->val) return false;
        bool left_eq = sameTree(A->left, B->left);
        bool right_eq = sameTree(A->right, B->right);
        return (left_eq && right_eq);
    }
    
    bool isSymmetric(TreeNode* root){
        if(!root) return true;
        if(!root->left && !root->right) return true;
        if(!root->left || !root->right) return false;
        // invert right half
        root->right = invertBinaryTree(root->right);
        // now check if left half and right half are equivalent
        if(sameTree(root->left, root->right)) return true;
        return false;
    }
};
