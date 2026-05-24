class Solution {
public:

    int solve(int i,int j,string text1,int n1,string text2,int n2,vector<vector<int>>& dp){
      if(i>=n1 || j>=n2)
      return 0;

      if(dp[i][j]!=-1)
      return dp[i][j];

      int ans = 0;

      if(text1[i]==text2[j]){
         ans=1+solve(i+1,j+1,text1,n1,text2,n2,dp);
         
      }
      else
      ans=max(solve(i,j+1,text1,n1,text2,n2,dp),solve(i+1,j,text1,n1,text2,n2,dp));

      return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();

        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

        for(int i=n1-1;i>=0;i--){
          for(int j=n2-1;j>=0;j--){
            if(text1[i]==text2[j]){
              dp[i][j]=1+dp[i+1][j+1];
            }

            else{
              dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
          }
        }

        return dp[0][0];
    }
};
