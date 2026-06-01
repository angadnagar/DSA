class Solution {
public:

    int solve(int i,vector<int>& nums,int n,vector<int>& dp){
      if(i>=n-1){
        return 0;
      }

      if(dp[i]!=-1)
      return dp[i];

      int ans = 1e9;

      for(int jump=1;jump<=nums[i];jump++){
        ans=min(ans,1+solve(i+jump,nums,n,dp));
      }

      return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n+1,-1);

        return solve(0,nums,n,dp);
    }
};
