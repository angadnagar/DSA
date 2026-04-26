class Solution {
public:

    int dfs(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>& vis){
      
      if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!=1 || vis[i][j]){
        return 0;
      }

      vis[i][j]=true;
      
      return 1+ 
        dfs(grid,i+1,j,vis) +
        dfs(grid,i,j+1,vis) +
        dfs(grid,i-1,j,vis) +
        dfs(grid,i,j-1,vis);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int maxArea = 0;

        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
            if(grid[i][j]==1 && !vis[i][j]){
              
              int area = dfs(grid,i,j,vis);
              maxArea=max(area,maxArea);
            }
          }
        }

        return maxArea;
    }
};
