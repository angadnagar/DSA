class Solution {
public:

    bool solve(int i,int j,string s,string p,int n,int m,vector<vector<int>>& dp){
      if(j>=m)
      return i>=n;

      if(dp[i][j]!=-1)
      return dp[i][j];
      
      bool match = (i<n && (s[i]==p[j] || p[j]=='.'));

      if(j+1 < m && p[j+1]=='*'){
        dp[i][j]= solve(i,j+2,s,p,n,m,dp) || (match && solve(i+1,j,s,p,n,m,dp));
      }

      else
      dp[i][j]= match && solve(i+1,j+1,s,p,n,m,dp);

      
      return dp[i][j];
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        return solve(0,0,s,p,n,m,dp);
    }
};
