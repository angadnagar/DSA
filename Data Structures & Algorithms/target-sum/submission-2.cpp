class Solution {
public:

    int totalsum;

    int solve(int i,vector<int>& nums,int n,int sum,int target,vector<vector<int>>& dp){
      if(i>=n){
        if(sum==target)
        return 1;

        return 0;
      }

      if(dp[i][sum+totalsum]!=-1)
      return dp[i][sum+totalsum];

      int ans = 0;

      ans+=solve(i+1,nums,n,sum+nums[i],target,dp);
      ans+=solve(i+1,nums,n,sum-nums[i],target,dp);

      return dp[i][sum+totalsum]=ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int i=0;
        int sum = 0;

        totalsum = accumulate(nums.begin(),nums.end(),0);


        vector<vector<int>> dp(n+1,vector<int>(2*totalsum + 1,-1));

        return solve(i,nums,n,sum,target,dp);
    }
};
