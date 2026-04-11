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
    int goodNodes(TreeNode* root) {
        if(root==NULL)
        return 0;

       return countNodes(root,root->val);

    }

    int countNodes(TreeNode* root,int maxValue){
         if(root==NULL)
         return 0;

         int res = (root->val >= maxValue) ? 1 : 0;
         maxValue=max(maxValue,root->val);
         
         res+=countNodes(root->left,maxValue);
         res+=countNodes(root->right,maxValue);

         return res;

    }
};
