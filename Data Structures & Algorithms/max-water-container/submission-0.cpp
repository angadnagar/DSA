class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0;
        int j = n-1;
        int maxi = -1;

        while(i<j){
           int mini = min(heights[i],heights[j]);

           maxi = max(maxi,mini*(j-i));

           if(heights[i]<heights[j]){
            i++;
           }
           else{
            j--;
           }

        }

        return maxi;
    }
};
