class Solution {
public:

    int solve(vector<int>& coins,int amount,vector<int>& dp){
      if(amount==0)
      return 0;

      int res = 1e9;

      if(dp[amount]!=-1)
      return dp[amount];

      for(auto &coin:coins){
        if(amount-coin >= 0){
          res=min(res,1+solve(coins,amount-coin,dp));
        }
      }

      return dp[amount]=res;
    
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int> dp(amount+1,-1);

        int res = solve(coins,amount,dp);

        return res>=1e9 ? -1 : res;
    }
};
