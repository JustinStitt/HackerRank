/**
 * link = https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree
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
    TreeNode* helper(vector<int>& nums, int l, int r){
        if(l > r) return nullptr;
        int mp = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[mp]);
        root->left = helper(nums, l, mp - 1);
        root->right = helper(nums, mp + 1, r);
        return root;
    }
    // -10, -3, 0, 5, 9
    // 0, 4
    // left = 0, 1
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};
