class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxi = -1;
        int count = 0;

        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
            if(grid[i][j]==1)
            count++;

            if(grid[i][j]==2){
              q.push({{i,j},0});
            }
          }
        }

        if(count==0)
        return 0;


      

        while(!q.empty()){
          int row = q.front().first.first;
          int col = q.front().first.second;
          int dist = q.front().second;

          q.pop();

          maxi=max(maxi,dist);

          if(row-1>=0 && grid[row-1][col]==1){
            grid[row-1][col]=2;
            count--;
            q.push({{row-1,col},dist+1});
          }

          if(col+1<n && grid[row][col+1]==1){
            grid[row][col+1]=2;
            count--;
            q.push({{row,col+1},dist+1});
          }

          if(col-1>=0 && grid[row][col-1]==1){
            grid[row][col-1]=2;
            count--;
            q.push({{row,col-1},dist+1});
          }

          if(row+1<m && grid[row+1][col]==1){
            grid[row+1][col]=2;
            count--;
            q.push({{row+1,col},dist+1});
          }


        } 

        if(count!=0)
        return -1;

        return maxi==0 ? -1 : maxi;
    }
};
