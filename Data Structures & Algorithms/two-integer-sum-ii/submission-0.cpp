class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0;
        int j = n-1;

        vector<int> ans(2,-1);

        while(i<j){
          if(numbers[i]+numbers[j] > target){
            j--;
          }

          else if(numbers[i]+numbers[j] < target){
            i++;
          }

          else{
            ans[0]=i+1;
            ans[1]=j+1;
            break;
          }
        }

        return ans;
    }
};
