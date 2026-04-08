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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }

        TreeNode* leftNode=invertTree(root->left);
        TreeNode* rightNode=invertTree(root->right);

        if(left==NULL && right==NULL)
        return root;

        if(left==NULL){
            root->left=root->right;
            root->right=NULL;
        }

        else if(right==NULL){
            root->right=root->left;
            root->left=NULL;
        }

        else{
            TreeNode* node = root->right;
            root->right=root->left;
            root->left=node;
        }
        return root;
    }
};
