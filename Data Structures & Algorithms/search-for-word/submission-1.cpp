class Solution {
public:

    bool solve(int i,int j,vector<vector<char>>& board,int m,int n,vector<vector<int>>& vis,string& word,int index){
        if(index>=word.size()){
            return true;
        }

        if(i<0 || i>=m || j<0 || j>=n || vis[i][j] || word[index]!=board[i][j])
        return false;

        vis[i][j]=1;

        bool ans = solve(i,j-1,board,m,n,vis,word,index+1) || solve(i,j+1,board,m,n,vis,word,index+1) ||
                   solve(i+1,j,board,m,n,vis,word,index+1) || solve(i-1,j,board,m,n,vis,word,index+1);
        
        vis[i][j]=0;

        return ans;

        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(solve(i,j,board,m,n,vis,word,0)){
                    return true;
                }
                
            }
        }

        return false;
    }
};
