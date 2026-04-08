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

    pair<int,bool> heightOfTree(TreeNode* root){
        if(root==NULL){
            return {0,true};
        }


        pair<int,bool> leftHeight = heightOfTree(root->left);
        pair<int,bool> rightHeight = heightOfTree(root->right);

        if(leftHeight.second==false || rightHeight.second==false)
        return {-1,false};


        if(abs(leftHeight.first-rightHeight.first)>1){
            return {max(leftHeight.first,rightHeight.first)+1,false};
        }

        return {max(leftHeight.first,rightHeight.first)+1,true};

    }
    bool isBalanced(TreeNode* root) {
        pair<int,bool> ans = heightOfTree(root);

        return ans.second;
    }
};
