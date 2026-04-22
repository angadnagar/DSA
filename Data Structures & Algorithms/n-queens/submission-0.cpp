class Solution {
public:

    bool isSafe(int row,int col,vector<string>& board){

      //top

      int r = row;
      int c = col;
      int n = board.size();
      while(r>=0){
        if(board[r][c]=='Q')
        return false;

        r--;
      }
      r=row;

      //left diagonal

      while(r>=0 && c>=0){
        if(board[r][c]=='Q')
        return false;

        r--;
        c--;
      }

      r=row;
      c=col;

      //right diagonal

      while(r>=0 && c<n){
        if(board[r][c]=='Q')
        return false;

        r--;
        c++;
      }

      return true;
    }

    void solve(int row,vector<string>& board,vector<vector<string>>& res){
         if(row==board.size()){
          res.push_back(board);
          return;
         }
        
        for(int col=0;col<board.size();col++){
          if(isSafe(row,col,board)){
            board[row][col]='Q';
            solve(row+1,board,res);
            board[row][col]='.';
          }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n,string(n,'.'));

        solve(0,board,res);

        return res;
    }
};
