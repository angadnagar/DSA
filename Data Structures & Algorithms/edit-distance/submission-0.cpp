class Solution {
public:

    int solve(int i,int j,string word1,string word2,int n1,int n2,vector<vector<int>>& dp){
      if(i>=n1){
        return n2-j;
      }

      if(j>=n2){
        return n1-i;
      }

      if(i>=n1 && j>=n2)
      return 0;

      if(dp[i][j]!=-1)
      return dp[i][j];

      int ans = INT_MAX;

      if(word1[i]==word2[j]){
        ans=solve(i+1,j+1,word1,word2,n1,n2,dp);
      }
      else
      ans=1+min(solve(i,j+1,word1,word2,n1,n2,dp),min(solve(i+1,j,word1,word2,n1,n2,dp),solve(i+1,j+1,word1,word2,n1,n2,dp)));

      return dp[i][j]=ans;


    }
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();

        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));

        return solve(0,0,word1,word2,n1,n2,dp);
    }
};
