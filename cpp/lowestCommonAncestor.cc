// link = https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((p->val >= root->val && q->val <= root->val) || 
           (p->val <= root->val && q->val >= root->val)) {
            return root;
        }
        
        if(p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        
        if(p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        
        return nullptr; // superfluous
    }
};


/*
// old soln.
 std::vector<TreeNode*> path(TreeNode* curr, const TreeNode* target, 
                                std::vector<TreeNode*> p) {
        if(!curr) return p;
        
        p.push_back(curr);
        
        if(curr == target) return p;
        
        std::vector<TreeNode*> p_left = path(curr->left, target, p);
        std::vector<TreeNode*> p_right = path(curr->right, target, p);
        
        if(!p_left.empty() && p_left[p_left.size() - 1] == target) return p_left;
        if(!p_right.empty() && p_right[p_right.size() - 1] == target) return p_right;
        
        return p;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode*> path_p, path_q;
        path_p = path(root, p, {});
        path_q = path(root, q, {});
        
        int bi = min(path_p.size(), path_q.size()) - 1;
        
        for(; bi >= 0; --bi) {
            if(path_p[bi] == path_q[bi]) return path_p[bi];
        }
        
        return nullptr;
    }
*/

