class Solution {
public:

    // int solveMem(int n,vector<int>& dp){
    //      if(n<0){
    //         return 0;
    //     }

    //     if(n==0)
    //     return 1;

    //     if(dp[n]!=-1)
    //     return dp[n];

    //     int ans = solveMem(n-1,dp)+solveMem(n-2,dp);

    //     return dp[n]=ans;
    // }

    int climbStairs(int n) {

        vector<int> dp(n+1,0);
        dp[0]=1;

        // return solveMem(n,dp);

        for(int i=1;i<=n;i++){
            if(i-2 >= 0)
            dp[i]=dp[i-1]+dp[i-2];

            else
            dp[i]=dp[i-1];
        }

        return dp[n];
        
    }
};
