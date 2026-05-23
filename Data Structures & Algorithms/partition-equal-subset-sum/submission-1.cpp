class Solution {
public:

    bool solve(vector<int>& nums,int i,int n,double sum,double total,vector<vector<int>>& dp){
      if(i>=n){
        if(sum==total/2)
        return true;

        return false;
      }

      if(dp[i][sum]!=-1){
        return dp[i][sum]==1;
      }

      //take
      bool take = solve(nums,i+1,n,sum+nums[i],total,dp);
      bool notTake = solve(nums,i+1,n,sum,total,dp);

      return dp[i][sum]=take | notTake;

    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        double total = 0;


        for(int i=0;i<n;i++){
           total+=nums[i];
        }

        vector<vector<int>> dp(n+1,vector<int>(total+1,-1));

        
        return solve(nums,0,n,0,total,dp);
    }
};
