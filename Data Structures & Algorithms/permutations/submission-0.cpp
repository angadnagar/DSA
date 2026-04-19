class Solution {
public:

    void solve(vector<int>& nums,int i,vector<int>& temp,vector<vector<int>>& ans,vector<bool>& vis){
      if(temp.size()==nums.size()){
        ans.push_back(temp);
        return;
      }

      for(int j=i;j<nums.size();j++){
            
            if(vis[j]==false){
              temp.push_back(nums[j]);
              vis[j]=true;
              solve(nums,0,temp,ans,vis);
              temp.pop_back();
              vis[j]=false;
            }

            
      }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;

        int n = nums.size();

        vector<bool> vis(n,false);

        solve(nums,0,temp,ans,vis);

        return ans;
    }
};
