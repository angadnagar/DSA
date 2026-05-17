class Solution {
public:

    int solve(vector<int>& nums,int n,int index,bool flag,vector<vector<int>>& dp){
      if(index>=n || (flag && index==n-1))
      return 0;

      if(dp[index][flag]!=-1)
      return dp[index][flag];

      return dp[index][flag]=max(solve(nums,n,index+1,flag,dp),nums[index]+solve(nums,n,index+2,flag,dp));
      
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1)
        return nums[0];
        
        vector<vector<int>> dp(n,vector<int>(2,-1));
        

        return max(solve(nums,n,0,1,dp),solve(nums,n,1,0,dp));
    }
};
