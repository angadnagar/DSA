class Solution {
public:

    // int solve(vector<int>& nums,int n,int index,vector<int>& dp){
    //   if(index>=n)
    //   return 0;

    //   if(dp[index]!=-1)
    //   return dp[index];
     
    //   int take1 = nums[index]+solve(nums,n,index+2,dp);
    //   int take2 = solve(nums,n,index+1,dp);

    //   return dp[index]=max(take1,take2);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1)
        return nums[0];
        
        vector<int> dp(n+1,0);

        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);

        for(int i=2;i<n;i++){
          dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }


        return dp[n-1];



      //  return solve(nums,n,0,dp);
    }
};
