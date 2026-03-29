class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;

        for(int i=0;i<n-2;i++){

            if(nums[i]>0)
            break;

            if(i>0 && i<n-2 && nums[i]==nums[i-1])
            continue;

            int j = i+1;
            int k = n-1;

            while(j<k){
               if(nums[i]+nums[j]+nums[k]==0){
                ans.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;

                while(j<k && nums[j]==nums[j-1])
                j++;

               }

               else if(nums[i]+nums[j]+nums[k]>0){
                k--;
               }

               else{
                j++;
               }
            }
        }

        return ans;
    }
};
