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

        for(int i=0;i<n;i++){
            dfs(0,i,pac,m,n,heights);
            dfs(m-1,i,atl,m,n,heights);
        }

        for(int j=0;j<m;j++){
            dfs(j,0,pac,m,n,heights);
            dfs(j,n-1,atl,m,n,heights);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] && atl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;


    }

    void dfs(int r,int c,vector<vector<bool>>& ocean,int m,int n,vector<vector<int>>& heights){
        ocean[r][c]=true;

        for(int i=0;i<4;i++){
            int newR = r+dirx[i];
            int newC = c+diry[i];

            if(newR>=0 && newC>=0 && newR<m && newC<n && !ocean[newR][newC] && heights[newR][newC]>=heights[r][c]){
                dfs(newR,newC,ocean,m,n,heights);
            }
        }
    }
};
