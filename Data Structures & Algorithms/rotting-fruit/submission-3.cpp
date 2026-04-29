class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int fresh = 0;

        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
            if(grid[i][j]==1)
            fresh++;

            if(grid[i][j]==2){
              q.push({i,j});
            }
          }
        }

        int time = 0;

        int dirx[4]={0,0,1,-1};
        int diry[4]={1,-1,0,0};

        while(fresh>0 && !q.empty()){
          int len = q.size();

          for(int i=0;i<len;i++){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int j=0;j<4;j++){
              int newRow = row+dirx[j];
              int newCol = col+diry[j];

              if(newRow>=0 && newRow<m && newCol>=0 && newCol<n && grid[newRow][newCol]==1){
                grid[newRow][newCol]=2;
                q.push({newRow,newCol});
                fresh--;
              }
            }
          }

          time++;
        }


        return fresh==0 ? time : -1;
    }
};
