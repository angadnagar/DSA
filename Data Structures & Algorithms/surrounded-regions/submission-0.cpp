class Solution {
public:

    int dirx[4]={1,0,-1,0};
    int diry[4]={0,1,0,-1};

    void dfs(vector<vector<char>>& board,int m,int n,int r,int c){
      
      board[r][c]='#';

      for(int i=0;i<4;i++){
          int newR = r+dirx[i];
          int newC = c+diry[i];

          if(newR>=0 && newC>=0 && newR<m && newC<n && board[newR][newC]=='O'){
            dfs(board,m,n,newR,newC);
          }
      }

      return;
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0;i<m;i++){
          if(board[i][0]=='O'){
            dfs(board,m,n,i,0);
          }
          if(board[i][n-1]=='O'){
            dfs(board,m,n,i,n-1);
          }
        }

        for(int j=1;j<n-1;j++){
          if(board[0][j]=='O'){
            dfs(board,m,n,0,j);
          }

          if(board[m-1][j]=='O'){
            dfs(board,m,n,m-1,j);
          }
        }

        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
            if(board[i][j]=='O'){
              board[i][j]='X';
            }

            if(board[i][j]=='#'){
              board[i][j]='O';
            }
          }
        }



    }
};
