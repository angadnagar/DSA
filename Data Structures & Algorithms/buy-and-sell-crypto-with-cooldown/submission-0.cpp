class Solution {
public:

    int solve(int i,int n,bool bought,vector<int>& prices,unordered_map<string,int>& dp){
      if(i>=n)
      return 0;

      string key = to_string(i) + "-" + to_string(bought);

      if(dp.find(key)!=dp.end())
      return dp[key];

      int profit = 0;

      int cooldown = solve(i+1,n,bought,prices,dp);

      if(!bought){
        profit+=max(solve(i+1,n,true,prices,dp)-prices[i],cooldown);
      }

      else{
        profit+=max(prices[i] + solve(i+2,n,false,prices,dp),cooldown);
      }

      return dp[key]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        unordered_map<string,int> dp;

        return solve(0,n,false,prices,dp);
    }
};
