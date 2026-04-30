class Solution {
public:

    int dirx[4]={0,0,1,-1};
    int diry[4]={1,-1,0,0};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> ans;

        vector<vector<bool>> pac(m,vector<bool>(n,false));
        vector<vector<bool>> atl(m,vector<bool>(n,false));

        queue<pair<int,int>> pacqueue;
        queue<pair<int,int>> atlqueue;

        for(int i=0;i<n;i++){
            pacqueue.push({0,i});
            atlqueue.push({m-1,i});
        }

        for(int j=0;j<m;j++){
            pacqueue.push({j,0});
            atlqueue.push({j,n-1});
        }

        bfs(pacqueue,pac,m,n,heights);
        bfs(atlqueue,atl,m,n,heights);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] && atl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;


    }

    void bfs(queue<pair<int,int>>& q,vector<vector<bool>>& ocean,int m,int n,vector<vector<int>>& heights){
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            ocean[r][c]=true;

            for(int i=0;i<4;i++){
                int newR = r+dirx[i];
                int newC = c+diry[i];

                if(newR>=0 && newC>=0 && newR<m && newC<n && !ocean[newR][newC] && heights[newR][newC]>=heights[r][c]){
                    q.push({newR,newC});
                }
            }
        }
    }

    // void dfs(int r,int c,vector<vector<bool>>& ocean,int m,int n,vector<vector<int>>& heights){
    //     ocean[r][c]=true;

    //     for(int i=0;i<4;i++){
    //         int newR = r+dirx[i];
    //         int newC = c+diry[i];

    //         if(newR>=0 && newC>=0 && newR<m && newC<n && !ocean[newR][newC] && heights[newR][newC]>=heights[r][c]){
    //             dfs(newR,newC,ocean,m,n,heights);
    //         }
    //     }
    // }
};
