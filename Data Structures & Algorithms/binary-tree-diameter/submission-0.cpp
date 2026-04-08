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

    int diameterOfBinaryTree(TreeNode* root) {
        
        int res = 0;
        dfs(root,res);
        return res;
    }

    int dfs(TreeNode* root,int& res){
        if(root==NULL){
            return 0;
        }

        int leftHeight = dfs(root->left,res);
        int rightHeight = dfs(root->right,res);

        res=max(res,leftHeight+rightHeight);
        return max(leftHeight,rightHeight)+1;
    }
};
