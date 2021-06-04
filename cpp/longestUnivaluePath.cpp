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
private:
    int dfs(TreeNode* root, int& best) {
        if(!root) return 0;
        int l = dfs(root->left, best);
        int r = dfs(root->right, best);
        
        if(root->left && root->left->val == root->val) ++l;
        else l = 0;
        if(root->right && root->right->val == root->val) ++r;
        else r = 0;
        
        best = max(best, l + r);
        return max(l, r);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int best{};
        dfs(root, best);
        return best;
    }
};