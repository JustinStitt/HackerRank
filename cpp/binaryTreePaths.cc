// link = https://leetcode.com/problems/binary-tree-paths
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
    void dfs(TreeNode* curr, string path, vector<string>& paths) {
        if(!curr) return;
        
        // add curr to path
        path += to_string(curr->val) + "->";
        
        // we are a leaf
        if(!curr->left && !curr->right) {
            string sb = path.substr(0, path.size() - 2); // get rid of trailing "->" 
            paths.push_back(sb);
            return;
        }
        
        dfs(curr->left, path, paths);
        dfs(curr->right, path, paths);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths = {};
        dfs(root, "", paths);
        return paths;
    }
};

