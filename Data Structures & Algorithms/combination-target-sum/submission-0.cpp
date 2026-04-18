class Solution {
public:

    void solve(vector<int>& nums,int i,vector<int> &temp,vector<vector<int>> &ans,int target){
      if(target == 0){
        ans.push_back(temp);
        return;
      }

      if(i==nums.size())
      return;
      
      //take
      if(target - nums[i] >= 0){
      temp.push_back(nums[i]);
      solve(nums,i,temp,ans,target-nums[i]);
      temp.pop_back();
      }

      //not take
      solve(nums,i+1,temp,ans,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(nums,0,temp,ans,target);

        return ans;
    }
};
