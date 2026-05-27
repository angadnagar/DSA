class Solution {
public:

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();


        vector<unordered_map<int,int>> dp(n+1);

        dp[0][0]=1;

        for(int i=0;i<n;i++){
          for(auto &it:dp[i]){
            dp[i+1][it.first + nums[i]]+=it.second;
            dp[i+1][it.first - nums[i]]+=it.second;
          }
        }

        return dp[n][target];
    }
};
