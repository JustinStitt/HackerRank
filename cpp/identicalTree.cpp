/**
 * link = https://leetcode.com/problems/same-tree
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        
        if(p->val != q->val) return false;
        
        bool left_eq = isSameTree(p->left, q->left);
        bool right_eq = isSameTree(p->right, q->right);
        
        return (left_eq && right_eq);
    }
};
