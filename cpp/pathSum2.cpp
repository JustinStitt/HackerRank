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
    
    // helper
    void getPaths(TreeNode* root, int targetSum, 
                                 vector<vector<int>>& paths, vector<int> path) {
        // base case
        if(!root) return; // not a valid path, do not add
        // add to path        
        path.push_back(root->val);
        // update sum
        targetSum -= root->val;
        if(!root->left && !root->right && !targetSum) { // we are a leaf and target is met
            // add path to paths
            paths.push_back(path);
            return;
        }
        // recursively check left and right
        getPaths(root->left, targetSum, paths, path);
        getPaths(root->right, targetSum, paths, path);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        getPaths(root, targetSum, paths, {});
        return paths;
    }
};