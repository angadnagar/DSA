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
    int kthSmallest(TreeNode* root, int k) {

      if(root==NULL || k<=0)
      return -1;

      int cnt = 0;

      TreeNode* kthSmallestNode = NULL;
      dfs(root,k,cnt,kthSmallestNode);

      if(!kthSmallestNode){
        return -1;
      }

      return kthSmallestNode->val;
    }

    void dfs(TreeNode* root,int k,int& cnt,TreeNode*& kthSmallestNode){
      if(root==NULL || kthSmallestNode){
        return;
      }

      dfs(root->left,k,cnt,kthSmallestNode);
      cnt++;

      if(cnt==k){
        kthSmallestNode = root;
        return;
      }

      dfs(root->right,k,cnt,kthSmallestNode);

      return;


    }
};
