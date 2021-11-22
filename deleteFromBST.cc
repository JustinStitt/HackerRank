// link = https://leetcode.com/problems/delete-node-in-a-bst/
class Solution {
public:
    int findminfromright(TreeNode* root){
        while(root->left!=nullptr)
            root=root->left;
        return root->val;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return root;
        else if(root->val>key) root->left=deleteNode(root->left,key);
        else if(root->val<key) root->right=deleteNode(root->right,key);
        else{
            if(root->right==nullptr){
                TreeNode* tmp = root->left;
                delete root;
                return tmp;
            }else if(root->left==nullptr){
                TreeNode* tmp = root->right;
                delete root;
                return tmp;
            }else{
			    //replace the root value by find the minimum val from right side 
                root->val=findminfromright(root->right);
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }
   
};

