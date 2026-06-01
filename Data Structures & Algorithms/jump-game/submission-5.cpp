class Solution {
public:

    
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        if(n==1)
        return true;

        vector<int> dp(n+1,0);
        dp[n-1]=1;
        dp[n]=1;


        for(int i=n-2;i>=0;i--){
          for(int jump=1;jump<=nums[i];jump++){
            if(i+jump <=n && dp[i+jump])
            dp[i]=1;
          }
        }
        return dp[0];
    }
};
