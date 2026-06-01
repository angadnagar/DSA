class Solution {
public:

    bool solve(int i,vector<int>& nums,int n,vector<int>& dp){
        if(i>=n-1){
            return true;
        }

        if(dp[i]!=-1)
        return dp[i];

        if(nums[i]==0)
        return false;

        for(int jump=1;jump<=nums[i];jump++){
            if(solve(i+jump,nums,n,dp))
            return dp[i]=true;
        }

        return dp[i]=false;

        
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        if(n==1)
        return true;

        vector<int> dp(n+1,-1);
        return solve(0,nums,n,dp);
    }
};
