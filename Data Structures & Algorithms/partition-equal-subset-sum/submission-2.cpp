class Solution {
public:

    // bool solve(vector<int>& nums,int i,int n,double sum,double total,vector<vector<int>>& dp){
    //   if(i>=n){
    //     if(sum==total/2)
    //     return true;

    //     return false;
    //   }

    //   if(dp[i][sum]!=-1){
    //     return dp[i][sum]==1;
    //   }

    //   //take
    //   bool take = solve(nums,i+1,n,sum+nums[i],total,dp);
    //   bool notTake = solve(nums,i+1,n,sum,total,dp);

    //   return dp[i][sum]=take | notTake;

    // }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int total = 0;

        for(int i=0;i<n;i++){
           total+=nums[i];
        }

        if(total%2 !=0)
        return false;

        int target = total/2;

        vector<vector<bool>> dp(n+1,vector<bool>(total+1,false));

        for(int i=0;i<=n;i++){
          dp[i][0]=true;
        }

        for(int i=1;i<=n;i++){
          for(int j=target;j>=0;j--){
            if(nums[i-1]<=j){
              dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
            else{
              dp[i][j]=dp[i-1][j];
            }
          }
        }

        return dp[n][target];




    }
};
