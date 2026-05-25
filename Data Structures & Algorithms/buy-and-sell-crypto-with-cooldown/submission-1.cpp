class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // unordered_map<string,int> dp;

        vector<vector<int>> dp(n+1,vector<int>(2,0));
        

        for(int i=n-1;i>=0;i--){
          for(int buying=1;buying>=0;buying--){
            if(buying == 1){
              dp[i][1]=max(dp[i+1][0]-prices[i],dp[i+1][1]);
            }

            else{
              int next = (i+2)<n ? dp[i+2][1] + prices[i] : prices[i];
              dp[i][0]=max(next,dp[i+1][0]);
            }
          }
        }

        return dp[0][1];
    }
};
