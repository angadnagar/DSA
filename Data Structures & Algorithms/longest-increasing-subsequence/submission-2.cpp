class Solution {
public:

    int solve(int i,vector<int>& nums,int n,int prev,vector<vector<int>>& dp){
      if(i>=n){
        return 0;
      }

      if(prev!=-1 && dp[i][prev]!=-1)
      return dp[i][prev];

      //take 
      int ans = 0;
      int take = 0;
      if(prev==-1 || nums[i]>nums[prev]){
        take = 1+solve(i+1,nums,n,i,dp);
      }

      //not take
      int notTake = max(ans,solve(i+1,nums,n,prev,dp));
      
      ans=max(take,notTake);

      if(prev!=-1)
      dp[i][prev]=ans;

      return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return solve(0,nums,n,-1,dp);

        
    }
};
