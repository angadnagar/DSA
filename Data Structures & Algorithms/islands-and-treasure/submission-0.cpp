class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int INF = INT_MAX;

        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
            if(grid[i][j]==0){
              q.push({{i,j},0});
            }
          }
        }

        while(!q.empty()){
          int row = q.front().first.first;
          int col = q.front().first.second;
          int dist = q.front().second;
          q.pop();

          if(row-1 >= 0 && (grid[row-1][col]==INF || grid[row-1][col]>dist+1)){
              grid[row-1][col]=dist+1;
              q.push({{row-1,col},dist+1});
          }

          if(row+1 < m && (grid[row+1][col]==INF || grid[row+1][col]>dist+1)){
              grid[row+1][col]=dist+1;
              q.push({{row+1,col},dist+1});
          }

          if(col+1 < n && (grid[row][col+1]==INF || grid[row][col+1]>dist+1)){
              grid[row][col+1]=dist+1;
              q.push({{row,col+1},dist+1});
          }

          if(col-1 >=0 && (grid[row][col-1]==INF || grid[row][col-1]>dist+1)){
            grid[row][col-1]=dist+1;
            q.push({{row,col-1},dist+1});
          }
        }
    }
};
