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
    unordered_map<int,int> m;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for(int i=0;i<inorder.size();i++){
          m[inorder[i]]=i;
        }

        TreeNode* root = dfs(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);

        return root;
    }

    TreeNode* dfs(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd){
      if(preStart>preEnd || inStart>inEnd)
      return NULL;

      TreeNode* root = new TreeNode(preorder[preStart]);
      int inOrderIndex = m[preorder[preStart]];
      int numsLeft = inOrderIndex - inStart;

      root->left = dfs(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inOrderIndex - 1);
      root->right = dfs(preorder,preStart+numsLeft+1,preEnd,inorder,inOrderIndex+1,inEnd);

      return root;
    }
};
