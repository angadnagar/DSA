class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int totalSum = 0;
        int sum = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            sum+=nums[i];
            totalSum+=i;
        }
        totalSum+=n;

        return totalSum-sum;
    }
};
