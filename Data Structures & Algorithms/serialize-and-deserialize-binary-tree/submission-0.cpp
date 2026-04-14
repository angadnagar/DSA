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

class Codec {
public:

    // Encodes a tree to a single string.

    void dfs(TreeNode* root,vector<string>& res){
        if(!root){
            res.push_back("N");
            return;
        }
        
        res.push_back(to_string(root->val));
        dfs(root->left,res);
        dfs(root->right,res);
    }

    TreeNode* dfsDeserialize(vector<string>& elems,int& i){
        if(elems[i]=="N"){
            i++;
            return NULL;
        }


        TreeNode* root = new TreeNode(stoi(elems[i]));
        i++;
        root->left=dfsDeserialize(elems,i);
        root->right=dfsDeserialize(elems,i);

        return root;
    }

    string join(vector<string>& res,char ch){
        string str = "";
        int i;

        for(i=0;i<res.size()-1;i++){
            str+=res[i];
            str+=",";
        }

        str+=res[i];

        return str;
    }

    vector<string> split(string data,char ch){
        vector<string> elems;
        
        stringstream ss(data);
        string item;

        while(getline(ss,item,ch)){
            elems.push_back(item);
        }

        return elems;


    }

    string serialize(TreeNode* root) {
          vector<string> res;

          dfs(root,res);

          return join(res,',');
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
         vector<string> elems = split(data,',');

         int i = 0;

         TreeNode* root = dfsDeserialize(elems,i);

         return root;
    }
};
