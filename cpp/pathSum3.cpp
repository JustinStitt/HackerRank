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
    void pathPrefixSum(TreeNode* root, int targetSum, int curr, int& total,
                          unordered_map<int, int>& tbl) {
        if(!root) return;
        
        curr += root->val;
        if(tbl.find(curr - targetSum) != tbl.end()) { // we found range that sums to target
            total += tbl[curr-targetSum];
        }
        ++tbl[curr];
        pathPrefixSum(root->left, targetSum, curr, total, tbl);
        pathPrefixSum(root->right, targetSum, curr, total, tbl);
        --tbl[curr];
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int, int> freq;
        int total{};
        ++freq[0]; // 1 way to get sum of 0 (do nothing)
        pathPrefixSum(root, targetSum, 0, total, freq);
        return total;
    }
};
