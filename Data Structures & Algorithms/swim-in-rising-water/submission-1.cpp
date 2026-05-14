class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        pq.push({grid[0][0],{0,0}});
    
        vector<vector<int>> vis(n,vector<int>(n,0));

        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        

        while(!pq.empty()){
          int time = pq.top().first;
          int r = pq.top().second.first;
          int c = pq.top().second.second;
          pq.pop();

          if(vis[r][c])
          continue;

          if(r==n-1 && c==n-1)
          return time;
          
          vis[r][c]=1;

          for(int i=0;i<4;i++){
            int newR = r+dx[i];
            int newC = c+dy[i];

            if(newR>=0 && newR<n && newC>=0 && newC<n && !vis[newR][newC]){
              int newtime=max(time,grid[newR][newC]);
              pq.push({newtime,{newR,newC}});
            }
          }

    
        }

        return -1;
    }
};
