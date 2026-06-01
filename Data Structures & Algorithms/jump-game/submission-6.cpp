class Solution {
public:

    
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        if(n==1)
        return true;

        vector<int> dp(n+1,0);
        dp[n-1]=1;


        for(int i=n-2;i>=0;i--){
          int end = min((int)nums.size(),i+nums[i]+1);
          for(int jump=i+1;jump<end;jump++){
            if(dp[jump]){
            dp[i]=1;
            break;
            }
          }
        }
        return dp[0];
    }
};
