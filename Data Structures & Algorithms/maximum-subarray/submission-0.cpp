class Solution {
public:

    int solve(int i,bool flag,vector<int>& nums,int n,vector<vector<int>>& dp){
        if(i==n-1){
            return flag ? max(0,nums[i]) : nums[i];
        }

        if(dp[i][flag]!=-1)
        return dp[i][flag];

        if(flag){
            return dp[i][flag]=max(0,nums[i]+solve(i+1,true,nums,n,dp));
        }

        return dp[i][flag]=max(solve(i+1,false,nums,n,dp),nums[i]+solve(i+1,true,nums,n,dp));
    }
    int maxSubArray(vector<int>& nums) {
         int n = nums.size();

         vector<vector<int>> dp(n+1,vector<int>(2,-1));
         
        return solve(0,false,nums,n,dp);
    }
};
