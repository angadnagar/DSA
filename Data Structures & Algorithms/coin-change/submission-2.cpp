class Solution {
public:

    // int solve(vector<int>& coins,int amount,vector<int>& dp){
    //   if(amount==0)
    //   return 0;

    //   int res = 1e9;

    //   if(dp[amount]!=-1)
    //   return dp[amount];

    //   for(auto &coin:coins){
    //     if(amount-coin >= 0){
    //       res=min(res,1+solve(coins,amount-coin,dp));
    //     }
    //   }

    //   return dp[amount]=res;
    
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int> dp(amount+1,1e9);
        dp[0]=0;

        for(int i=1;i<=amount;i++){
          for(int j=0;j<n;j++){
            if(i-coins[j]>=0){
              dp[i]=min(dp[i],1+dp[i-coins[j]]);
            }
          }
        }


        return dp[amount]==1e9 ? -1 : dp[amount];



        // int res = solve(coins,amount,dp);

        // return res>=1e9 ? -1 : res;
    }
};
