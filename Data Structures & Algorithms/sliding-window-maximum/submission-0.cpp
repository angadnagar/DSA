class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;

        int i = 0;
        int j = 0;

        vector<int> ans;


        while(j<n){
          pq.push({nums[j],j});

          if(j-i+1 == k){
            while(pq.top().second < i){
                pq.pop();
            }
            ans.push_back(pq.top().first);

            i++;
          }
          j++;
        }

        return ans;
    }
};
