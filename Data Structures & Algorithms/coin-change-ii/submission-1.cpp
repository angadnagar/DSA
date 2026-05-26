class Solution {
public:


    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        sort(coins.begin(),coins.end());

        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));

        for(int i=0;i<=n;i++){
          dp[i][0]=1;
        }
        
        for(int j=n-1;j>=0;j--){
        for(int target=1;target<=amount;target++){
          if(target >= coins[j]){
            dp[j][target]=dp[j][target-coins[j]]+dp[j+1][target];
          }
        }

        }

        
        return dp[0][amount];
    }
};
