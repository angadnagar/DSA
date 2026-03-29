class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int totalProduct = 1;
       int productNotZero=1;

       int n = nums.size();
       int countZero = 0;

       for(int i=0;i<n;i++){
        if(nums[i]!=0){
            productNotZero*=nums[i];
        }
        totalProduct*=nums[i];
        if(nums[i]==0){
            countZero++;
        }
       }

       vector<int> ans(n);

       for(int i=0;i<n;i++){
        if(countZero==1 && nums[i]==0){
            ans[i]=productNotZero;
        }

       else if(countZero==0){
            ans[i]=totalProduct/nums[i];
        }

        else{
            ans[i]=0;
        }


       }

       return ans;
    }
};
