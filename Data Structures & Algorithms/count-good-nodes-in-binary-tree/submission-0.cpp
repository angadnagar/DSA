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

        int count = 0;
        int maxi = root->val;

        countNodes(root,maxi,count);

        return count;


    }

    void countNodes(TreeNode* root,int& maxi,int& count){
         if(root==NULL)
         return;

         if(root->val >= maxi){
            count=count+1;
            countNodes(root->left,root->val,count);
            countNodes(root->right,root->val,count);
         }
         else{
         countNodes(root->left,maxi,count);
         countNodes(root->right,maxi,count);
         }
    }
};
