class Solution {
public:

    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};

    int solve(int i,int j,int prevVal,vector<vector<int>>& matrix,vector<vector<int>>& dp){
       
       if(i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size() || matrix[i][j]<=prevVal)
       return 0;

       if(dp[i][j]!=-1)
       return dp[i][j];

       int ans = 1;

       for(int ind=0;ind<4;ind++){
        int new_r = i+dx[ind];
        int new_c = j+dy[ind];

        ans = max(ans,1+solve(new_r,new_c,matrix[i][j],matrix,dp));
       }
       return dp[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int prevVal = -1;

        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));


        int ans = 0;

        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
              ans=max(ans,solve(i,j,prevVal,matrix,dp));            
          }
        }

        return ans;
    }
};
