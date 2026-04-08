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

    bool sameTree(TreeNode* node,TreeNode* subRoot){
        if(node==NULL && subRoot==NULL)
        return true;

        if(node==NULL || subRoot==NULL)
        return false;

        if(node->val!=subRoot->val)
        return false;

        bool leftPart = sameTree(node->left,subRoot->left);
        bool rightPart = sameTree(node->right,subRoot->right);

        if(leftPart && rightPart)
        return true;

        return false;



    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==NULL)
        return true;

        if(root==NULL)
        return false;

        if(sameTree(root,subRoot))
        return true;

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
