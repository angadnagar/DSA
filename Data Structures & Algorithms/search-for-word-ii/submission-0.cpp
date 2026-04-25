class TrieNode{
  public:
  unordered_map<char,TrieNode*> children;
  bool isword;

  TrieNode(){
    isword = false;
  }

  void addWord(const string& word){
    TrieNode* curr = this;

    for(char ch: word){
      if(!curr->children.count(ch)){
        curr->children[ch]=new TrieNode();
      }

      curr=curr->children[ch];
    }

    curr->isword = true;
  }

};

class Solution {
public:

    void dfs(TrieNode* node,vector<vector<char>>& board,int i, int j,unordered_set<string>& ans,string word,vector<vector<bool>>& vis){
      if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || vis[i][j] || !node->children.count(board[i][j])){
        return;
      }

      vis[i][j]=true;
      node = node->children[board[i][j]];

      word+=board[i][j];

      if(node->isword){
        ans.insert(word);
      }

      dfs(node,board,i+1,j,ans,word,vis);
      dfs(node,board,i,j+1,ans,word,vis);
      dfs(node,board,i-1,j,ans,word,vis);
      dfs(node,board,i,j-1,ans,word,vis);

      vis[i][j]=false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> ans;

        TrieNode* root = new TrieNode();

        for(auto &word:words){
          root->addWord(word);
        }

        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> vis(rows,vector<bool>(cols,false));

        for(int i=0;i<rows;i++){
          for(int j=0;j<cols;j++){
              dfs(root,board,i,j,ans,"",vis);
          }
        }

        return vector<string>(ans.begin(),ans.end());

    }
};
