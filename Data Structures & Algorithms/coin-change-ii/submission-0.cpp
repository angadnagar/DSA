class Solution {
public:

    int solve(int i,vector<int>& coins,int n,int target,vector<vector<int>>& dp){
      if(target==0)
      return 1;

      if(i>=n)
      return 0;

      if(dp[i][target]!=-1)
      return dp[i][target];

      int res = 0;

      if(target >= coins[i]){
        res+=solve(i,coins,n,target-coins[i],dp);
        res+=solve(i+1,coins,n,target,dp);
      }

      return dp[i][target]=res;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        sort(coins.begin(),coins.end());

        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));

        return solve(0,coins,n,amount,dp);
    }
};
