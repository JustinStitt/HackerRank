// link = https://leetcode.com/problems/sum-of-left-leaves/
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;        
        
        int csum{};
        
        if(root->left && !root->left->left
                      && !root->left->right) {
            csum = root->left->val;
        }
        
        int lsum = sumOfLeftLeaves(root->left);
        int rsum = sumOfLeftLeaves(root->right);
        
        return lsum + rsum + csum;
    }
};
