class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0;
        int r = n-1;

        while(l<=r){
          int mid = l+(r-l)/2;

          if(nums[mid] == target)
          return mid;
          
          //left part
          if(nums[l]<=nums[mid]){
             if(target > nums[mid] || target < nums[l]){
              l=mid+1;
             }

             else{
              r=mid;
             }
          }

          //right part
          else{
            if(target < nums[mid] || target > nums[r]){
              r=mid;
            }
            else{
              l=mid+1;
            }
          }
        }

        return -1;
    }
};
