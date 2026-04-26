class Solution {
public:

    void dfs(vector<vector<char>>& grid,int i,int j,vector<vector<bool>>& vis){
      
      if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!='1' || vis[i][j]){
        return;
      }

      vis[i][j]=true;

      dfs(grid,i+1,j,vis);
      dfs(grid,i,j+1,vis);
      dfs(grid,i-1,j,vis);
      dfs(grid,i,j-1,vis);

    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int islands = 0;

        vector<vector<bool>> vis(m,vector<bool>(n,false));
        
        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
            if(grid[i][j]=='1' && !vis[i][j]){
                islands++;
                dfs(grid,i,j,vis);
            }
          }
        }

        return islands;
    }
};
