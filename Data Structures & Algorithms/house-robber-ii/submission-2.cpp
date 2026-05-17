class Solution {
public:

    int solve(vector<int>& nums,int n,int index,vector<int>& dp){
      if(index>=n)
      return 0;

      if(dp[index]!=-1)
      return dp[index];

    
      int take1 = nums[index]+solve(nums,n,index+2,dp);

      int take2 = solve(nums,n,index+1,dp);

      return dp[index]=max(take1,take2);
      
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);

        if(n==1)
        return nums[0];

        
        vector<int> nums1(nums.begin(),nums.end()-1);
        vector<int> nums2(nums.begin()+1,nums.end());
        return max(solve(nums1,n-1,0,dp1),solve(nums2,n-1,0,dp2));
    }
};
